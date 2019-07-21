#include "xycropfunc.h"
#include "xycropproxywidget.h"

XYCropFunc::XYCropFunc(QObject *parent)
    :QObject (parent)
{

}

XYFuncProxyWidget *XYCropFunc::createFuncProxy()
{
    return new XYCropProxyWidget;
}
