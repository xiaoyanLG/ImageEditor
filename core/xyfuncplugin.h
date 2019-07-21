#ifndef XYFUNCPLUGIN_H
#define XYFUNCPLUGIN_H

#include <QObject>

#define XYFuncPluginInterface_iid "xyimagefunc.expansion.1.0"

class XYFuncProxyWidget;
class XYFuncPlugin : public QObject
{
    Q_OBJECT
public:
    explicit XYFuncPlugin(QObject *parent = nullptr);

    // 创建显示在功能盒子里面的功能选择控件
    virtual XYFuncProxyWidget *createFuncProxy() = 0;

};

#endif // XYFUNCPLUGIN_H
