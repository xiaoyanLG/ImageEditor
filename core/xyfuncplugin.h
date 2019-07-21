#ifndef XYFUNCPLUGIN_H
#define XYFUNCPLUGIN_H

#define XYFuncPluginInterface_iid "xyimagefunc.expansion.1.0"

class XYFuncProxyWidget;
class XYFuncPlugin
{
public:
    XYFuncPlugin();
    virtual ~XYFuncPlugin();
    // 创建显示在功能盒子里面的功能选择控件
    virtual XYFuncProxyWidget *createFuncProxy() = 0;

};

#endif // XYFUNCPLUGIN_H
