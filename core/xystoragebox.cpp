#include "xystoragebox.h"
#include "xybutton.h"
#include <QPainter>
#include <QHBoxLayout>

XYStorageBox::XYStorageBox(QWidget *parent)
    : QWidget(parent)
{
    setMinimumHeight(25);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(0);
    setLayout(layout);
}

void XYStorageBox::addStretch(int stretch)
{
    QHBoxLayout *layout = qobject_cast<QHBoxLayout *>(this->layout());
    layout->addStretch(stretch);
}

void XYStorageBox::addSpacing(int space)
{
    QHBoxLayout *layout = qobject_cast<QHBoxLayout *>(this->layout());
    layout->addSpacing(space);
}

XYButton *XYStorageBox::addButton(const QString &name, const QImage &icon)
{
    XYButton *btn = new XYButton(name, icon);

    layout()->addWidget(btn);

    if (isVisible())
    {
        btn->setVisible(true);
    }
    return btn;
}

void XYStorageBox::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.fillRect(rect(), QColor("#555555"));
}
