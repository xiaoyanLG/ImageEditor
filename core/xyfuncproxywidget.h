#ifndef XYFUNCPROXYWIDGET_H
#define XYFUNCPROXYWIDGET_H

#include <QWidget>

class XYFuncPanelWidget;
class XYFuncProxyWidget : public QWidget
{
    Q_OBJECT
public:
    XYFuncProxyWidget();

    // 创建显示在功能扩展盒子里面的具体功能面板
    virtual XYFuncPanelWidget *createFuncPanel() = 0;

signals:
    void clicked();

protected:
    void mouseReleaseEvent(QMouseEvent *event);

};

#endif // XYFUNCPROXYWIDGET_H
