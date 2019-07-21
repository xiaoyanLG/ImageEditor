#ifndef XYFUNCSBOX_H
#define XYFUNCSBOX_H

#include <QWidget>

class XYFuncProxyWidget;
class XYFuncsBox : public QWidget
{
    Q_OBJECT
public:
    explicit XYFuncsBox(QWidget *parent = nullptr);
    void addFunc(XYFuncProxyWidget *func);

protected:
    void paintEvent(QPaintEvent *event);

};

#endif // XYFUNCSBOX_H
