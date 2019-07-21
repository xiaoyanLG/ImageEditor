#ifndef XYCROPFUNC_H
#define XYCROPFUNC_H

#include <QObject>
#include "xyfuncplugin.h"

class XYCropFunc : public QObject, public XYFuncPlugin
{
    Q_OBJECT
//    Q_PLUGIN_METADATA(IID XYFuncPluginInterface_iid)  // 这个插件直接链接
public:
    explicit XYCropFunc(QObject *parent = nullptr);

    XYFuncProxyWidget *createFuncProxy() override;

};

#endif // XYCROPFUNC_H
