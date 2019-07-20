#include "xyimageviewer.h"
#include <QPainter>
#include <QDir>
#include <QImageReader>
#include <QMouseEvent>
#include <QMimeData>
#include <QDebug>

XYImageViewer::XYImageViewer(QWidget *parent)
    : QWidget(parent), mStartMoveImage(false), mScale(1.0)
{
    setAcceptDrops(true);
}

void XYImageViewer::initImage(const QString &img)
{
    mImageFile = img;
    if (mImageFile.isEmpty() || !mSourceImage.load(mImageFile))
    {
        return;
    }

    QFileInfo info = QFileInfo(mImageFile);
    QDir dir = info.absoluteDir();
    auto supports = QImageReader::supportedImageFormats();
    QStringList allTypes;
    for (int i = 0; i < supports.size(); ++i)
    {
        allTypes << QString("*.%1").arg(supports[i].data());
    }

    mAllDirImages = dir.entryList(allTypes, QDir::Files);
    if (!mAllDirImages.contains(info.fileName()))
    {
        mAllDirImages.prepend(info.fileName());
    }
    mPaintImage = mSourceImage;
    mScale = 1.0;

    moveImageToCenter();
    update();
}

void XYImageViewer::moveImageToCenter()
{
    int w = mPaintImage.width();
    int h = mPaintImage.height();
    mImagePos = QPoint((width() - w) / 2, (height() - h) / 2);
    update();
}

void XYImageViewer::restore()
{
    initImage(mImageFile);
}

void XYImageViewer::adaptive()
{
    if (mSourceImage.isNull())
    {
        return;
    }

    QSize windowSize = this->size();
    QSize imageSize = mSourceImage.size();

    double imageRatio = double(imageSize.height()) / imageSize.width();
    double scaleTo;

    if (windowSize.width() * imageRatio > windowSize.height())
    {
        scaleTo = double(windowSize.height()) / imageSize.height();
    }
    else
    {
        scaleTo = double(windowSize.width()) / imageSize.width();
    }

    if (qAbs(mScale - scaleTo) <= 0.00001)
    {
        setScale(1.0);
    }
    else
    {
        setScale(scaleTo);
        moveImageToCenter();
    }
}

void XYImageViewer::previous()
{
    if (mAllDirImages.size() <= 1)
    {
        return;
    }

    QFileInfo info(mImageFile);
    int index = mAllDirImages.indexOf(info.fileName());

    if (index == -1 || index == 0)
    {
        initImage(info.absoluteDir().path() + QDir::separator() + mAllDirImages.last());
    }
    else
    {
        initImage(info.absoluteDir().path() + QDir::separator() + mAllDirImages.at(index - 1));
    }
}

void XYImageViewer::next()
{
    if (mAllDirImages.size() <= 1)
    {
        return;
    }

    QFileInfo info(mImageFile);
    int index = mAllDirImages.indexOf(info.fileName());

    if (index == -1 || index == mAllDirImages.size() - 1)
    {
        initImage(info.absoluteDir().path() + QDir::separator() + mAllDirImages.first());
    }
    else
    {
        initImage(info.absoluteDir().path() + QDir::separator() + mAllDirImages.at(index + 1));
    }
}

void XYImageViewer::setScale(qreal scale)
{
    QPoint center = QRect(mImagePos, mPaintImage.size()).center();
    mScale = scale;
    mPaintImage = mSourceImage.scaled(mSourceImage.size() * mScale, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    mImagePos -= QRect(mImagePos, mPaintImage.size()).center() - center;
    update();
}

void XYImageViewer::rolate(int angle)
{
    QMatrix rm;
    rm.rotate(angle);
    QPoint center = QRect(mImagePos, mPaintImage.size()).center();
    mPaintImage = mPaintImage.transformed(rm);
    mSourceImage = mPaintImage;
    mImagePos -= QRect(mImagePos, mPaintImage.size()).center() - center;
    update();
}

void XYImageViewer::deleteCurrentImage()
{
    if (!mSourceImage.isNull())
    {
        QFileInfo info(mImageFile);
        QFile::remove(mImageFile);
        mAllDirImages.removeAll(info.fileName());
        if (mAllDirImages.isEmpty())
        {
            mImageFile.clear();
            mSourceImage = mPaintImage = QImage();
            update();
        }
        else if (mAllDirImages.size() == 1)
        {
            initImage(info.absoluteDir().path() + QDir::separator() + mAllDirImages.first());
        }
        else
        {
            next();
        }
    }
}

void XYImageViewer::save()
{
    if (!mPaintImage.isNull())
    {
        mPaintImage.save(mImageFile);
    }
}

void XYImageViewer::zoomOutContents()
{
    // 这个功能需要单独再设计，现在这样会越来越模糊
    if (!mPaintImage.isNull())
    {
        QImage image(mPaintImage.size(), QImage::Format_ARGB32);
        QPainter painter(&image);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
        painter.setCompositionMode(QPainter::CompositionMode_Clear);
        painter.fillRect(image.rect(), Qt::transparent);

        painter.setCompositionMode(QPainter::CompositionMode_Source);
        painter.drawImage(image.rect().adjusted(1, 1, -1, -1), mPaintImage);
        painter.end();

        mPaintImage = image;

        update();
    }
}

bool XYImageViewer::event(QEvent *event)
{
    QMouseEvent *mouseEvent = nullptr;
    QPoint curPos;
    switch (event->type())
    {
    case QEvent::MouseButtonPress:
        mouseEvent = static_cast<QMouseEvent *>(event);
        curPos = mouseEvent->pos();
        if (QRect(mImagePos, mPaintImage.size()).contains(curPos))
        {
            mStartMoveImage = true;
            mLastPos = curPos;
        }
        break;
    case QEvent::MouseButtonRelease:
        mStartMoveImage = false;
        break;
    case QEvent::MouseMove:
        mouseEvent = static_cast<QMouseEvent *>(event);
        curPos = mouseEvent->pos();
        if (mStartMoveImage)
        {
            QRect lastGm(mImagePos, mPaintImage.size());
            mImagePos += curPos - mLastPos;
            mLastPos = curPos;
            update();
        }
        break;
    case QEvent::Wheel:
    {
        QWheelEvent *wheel = static_cast<QWheelEvent *>(event);
        if (QRect(mImagePos, mPaintImage.size()).contains(wheel->pos()))
        {
            if (wheel->delta() > 0)
            {
                setScale(scale() * 1.05);
            }
            else
            {
                setScale(scale() * 0.95);
            }
        }
        else
        {
            if (wheel->delta() > 0)
            {
                mImagePos.setY(mImagePos.y() + 10);
            }
            else
            {
                mImagePos.setY(mImagePos.y() - 10);
            }
            update();
        }
        break;
    }
    default:
        break;
    }
    return QWidget::event(event);
}

void XYImageViewer::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::SmoothPixmapTransform);

    painter.fillRect(rect(), QColor("#606060"));

    // 绘制图片
    if (!mPaintImage.isNull())
    {
        painter.drawImage(mImagePos, mPaintImage);
    }
}

void XYImageViewer::dragEnterEvent(QDragEnterEvent *event)
{
    event->setDropAction(Qt::MoveAction);
    event->accept();
}

void XYImageViewer::dropEvent(QDropEvent *event)
{
    auto data = event->mimeData();
    if (data->hasUrls())
    {
        QUrl file = data->urls().first();
        initImage(file.toLocalFile());
    }
    event->accept();
}
