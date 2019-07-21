#include "xyfuncpanelwidget.h"
#include "xyfuncproxywidget.h"
#include "xyimageviewer.h"
#include <QEvent>

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
    // 实现模版
    if (this->isVisible() && mImageViewer == obj)
    {
        switch (event->type())
        {
        default:
            break;
        }
    }

    return QWidget::eventFilter(obj, event);
}
