#include "xyfuncsbox.h"
#include <QPainter>

XYFuncsBox::XYFuncsBox(QWidget *parent)
    : QWidget(parent)
{
    setMinimumWidth(50);
}

void XYFuncsBox::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.fillRect(rect(), QColor(Qt::darkCyan));
    painter.drawText(rect(), QStringLiteral("功能盒子区域"), QTextOption(Qt::AlignCenter));
}
