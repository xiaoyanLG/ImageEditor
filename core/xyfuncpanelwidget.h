#ifndef XYFUNCPANELWIDGET_H
#define XYFUNCPANELWIDGET_H

#include <QWidget>

class XYImageViewer;
class XYFuncProxyWidget;
class XYFuncPanelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit XYFuncPanelWidget(XYFuncProxyWidget *proxy);
    void setImageViewer(XYImageViewer *viewer);

signals:
    void proxyClicked();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

    virtual void paintMaskImage();

protected:
    XYFuncProxyWidget *mProxyWidget;
    XYImageViewer     *mImageViewer;

    QImage             mMaskImage;

};

#endif // XYFUNCPANELWIDGET_H
