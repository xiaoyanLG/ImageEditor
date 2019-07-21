#include "xyexpansionsbox.h"
#include <QPainter>

XYExpansionsBox::XYExpansionsBox(QWidget *parent)
    : QWidget(parent)
{
    setMinimumWidth(150);
}

void XYExpansionsBox::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.fillRect(rect(), QColor(Qt::darkGreen));
    painter.drawText(rect(), QStringLiteral("功能扩展盒子区域"), QTextOption(Qt::AlignCenter));
}
