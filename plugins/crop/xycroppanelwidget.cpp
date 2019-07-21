#include "xycroppanelwidget.h"
#include <QPainter>

XYCropPanelWidget::XYCropPanelWidget(XYFuncProxyWidget *proxy)
    : XYFuncPanelWidget(proxy)
{

}

void XYCropPanelWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.fillRect(rect(), Qt::red);
}
