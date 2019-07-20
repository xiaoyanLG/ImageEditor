#ifndef XYFUNCSBOX_H
#define XYFUNCSBOX_H

#include <QWidget>

class XYFuncsBox : public QWidget
{
    Q_OBJECT
public:
    explicit XYFuncsBox(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);

};

#endif // XYFUNCSBOX_H
