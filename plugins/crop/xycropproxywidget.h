#ifndef XYCROPPROXYWIDGET_H
#define XYCROPPROXYWIDGET_H

#include "xyfuncproxywidget.h"

class XYCropProxyWidget : public XYFuncProxyWidget
{
    Q_OBJECT
public:
    // 创建显示在功能扩展盒子里面的具体功能面板
    XYFuncPanelWidget *createFuncPanel() override;

};

#endif // XYCROPPROXYWIDGET_H
