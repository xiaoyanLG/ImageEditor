#ifndef XYCROPPANELWIDGET_H
#define XYCROPPANELWIDGET_H

#include "xyfuncpanelwidget.h"

class XYCropPanelWidget : public XYFuncPanelWidget
{
    Q_OBJECT
public:
    explicit XYCropPanelWidget(XYFuncProxyWidget *proxy);

protected:
    void paintEvent(QPaintEvent *event);

};

#endif // XYCROPPANELWIDGET_H
