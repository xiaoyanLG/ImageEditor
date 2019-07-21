#include "xybutton.h"
#include <QPainter>
#include <QMouseEvent>

XYButton::XYButton(const QString &text, const QImage &icon, QWidget *parent)
    :QWidget(parent), mIcon(icon), mText(text),
      mCheckable(false), mChecked(false),
      mHover(false), mPressed(false)
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

void XYButton::setCheckable(bool checkable)
{
    mCheckable = checkable;
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
    else if (mCheckable && mChecked)
    {
        painter.fillRect(rect(), QColor("#393939"));
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
