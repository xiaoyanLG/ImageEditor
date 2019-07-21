#include "xyfuncsbox.h"
#include "flowlayout.h"
#include "xyfuncproxywidget.h"
#include <QPainter>

XYFuncsBox::XYFuncsBox(QWidget *parent)
    : QWidget(parent)
{
    setLayout(new FlowLayout(2));
}

void XYFuncsBox::addFunc(XYFuncProxyWidget *func)
{
    layout()->addWidget(func);
}

void XYFuncsBox::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.fillRect(rect(), QColor(Qt::darkCyan));
    painter.drawText(rect(), QStringLiteral("功能盒子区域"), QTextOption(Qt::AlignCenter));
}
