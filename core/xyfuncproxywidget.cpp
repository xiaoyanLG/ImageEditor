#include "xyfuncproxywidget.h"
#include <QPainter>
#include <QMouseEvent>

XYFuncProxyWidget::XYFuncProxyWidget()
{
    setMinimumSize(24, 24);
}

void XYFuncProxyWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (rect().contains(event->pos()))
    {
        emit clicked();
    }
}
