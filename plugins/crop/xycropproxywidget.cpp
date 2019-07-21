#include "xycropproxywidget.h"
#include "xycroppanelwidget.h"

XYFuncPanelWidget *XYCropProxyWidget::createFuncPanel()
{
    return new XYCropPanelWidget(this);
}
