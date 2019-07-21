#include "xyfuncpanelwidget.h"
#include "xyfuncproxywidget.h"
#include "xyimageviewer.h"
#include <QEvent>
#include <QPainter>

XYFuncPanelWidget::XYFuncPanelWidget(XYFuncProxyWidget *proxy)
    : mProxyWidget(proxy)
{
    connect(proxy, &XYFuncProxyWidget::clicked, this, &XYFuncPanelWidget::proxyClicked);
}

void XYFuncPanelWidget::setImageViewer(XYImageViewer *viewer)
{
    mImageViewer = viewer;
    mImageViewer->installEventFilter(this);
}

bool XYFuncPanelWidget::eventFilter(QObject *obj, QEvent *event)
{
    if (this->isVisible() && mImageViewer == obj)
    {
        switch (event->type())
        {
        case QEvent::Paint:
        {
            paintMaskImage();
            break;
        }
        default:
            break;
        }
    }

    return QWidget::eventFilter(obj, event);
}

void XYFuncPanelWidget::paintMaskImage()
{
    // 如果需要，添加图层到ImageViewer

    if (!mMaskImage.isNull())
    {
        mImageViewer->addMaskImage(mMaskImage, mImageViewer->imagePos());
    }
}
