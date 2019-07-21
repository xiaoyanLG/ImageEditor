#ifndef XYIMAGEVIEWER_H
#define XYIMAGEVIEWER_H

#include <QWidget>

class XYImageViewer : public QWidget
{
    Q_OBJECT
public:
    explicit XYImageViewer(QWidget *parent = nullptr);
    void initImage(const QString &img);
    inline qreal scale() { return mScale; }

public slots:
    void moveImageToCenter();
    void restore();
    void adaptive();
    void previous();
    void next();
    void setScale(qreal scale);
    void rolate(int angle);
    void deleteCurrentImage();
    void save();
    void zoomOutContents();

protected:
    bool loadImage(const QString &img);

protected:
    bool event(QEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

#if QT_CONFIG(draganddrop)
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
#endif

private:
    bool       mStartMoveImage;
    QPoint     mLastPos;

private:
    QImage      mSourceImage;    // 当前加载的图片
    QImage      mPaintImage;     // 当前绘制用的图片
    QPoint      mImagePos;       // 当前图片显示的位置
    QString     mImageFile;      // 当前加载的图片路径
    qreal       mScale;          // 缩放比例
    QStringList mAllDirImages;   // 当前加载的图片同级目录下的所有图片

};

#endif // XYIMAGEVIEWER_H
