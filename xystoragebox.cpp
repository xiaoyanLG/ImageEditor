#include "xystoragebox.h"
#include <QPainter>
#include <QHBoxLayout>
#include <QMouseEvent>

XYButton::XYButton(const QString &text, const QImage &icon, QWidget *parent)
    :QWidget(parent), mIcon(icon), mText(text), mChecked(false), mHover(false), mPressed(false)
{
    setMinimumWidth(qMax(18, mIcon.width()));
    setMinimumHeight(qMax(18, mIcon.height()));

    setToolTip(mText);
}

void XYButton::setChecked(bool check)
{
    mChecked = check;
    update();
}

void XYButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // 绘制底色
    if (mPressed)
    {
        painter.fillRect(rect(), QColor("#333333"));
    }
    else if (mHover)
    {
        painter.fillRect(rect(), QColor("#444444"));
    }

    if (mIcon.isNull())
    {
        // 绘制文字
        QPen pen = painter.pen();
        pen.setColor(Qt::white);
        painter.setPen(pen);
        painter.drawText(rect(), mText, QTextOption(Qt::AlignCenter));
    }
    else
    {
        // 绘制图片
        QRect gm = mIcon.rect();
        gm.moveCenter(rect().center());
        painter.drawImage(gm, mIcon);
    }


}

void XYButton::enterEvent(QEvent *)
{
    mHover = true;
    update();
}

void XYButton::leaveEvent(QEvent *)
{
    mHover = false;
    update();
}

void XYButton::mousePressEvent(QMouseEvent *)
{
    mPressed = true;
    update();
}

void XYButton::mouseReleaseEvent(QMouseEvent *event)
{
    if (rect().contains(event->pos()))
    {
        mChecked = !mChecked;
        emit clicked();
        emit checkChanged(mChecked);
    }
    mPressed = false;
    update();
}

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
