#ifndef XYFUNCPROXYWIDGET_H
#define XYFUNCPROXYWIDGET_H

#include <QWidget>

class XYFuncPanelWidget;
class XYFuncProxyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit XYFuncProxyWidget(QWidget *parent = nullptr);

    // 创建显示在功能扩展盒子里面的具体功能面板
    virtual XYFuncPanelWidget *createFuncPanel() = 0;
};

#endif // XYFUNCPROXYWIDGET_H
