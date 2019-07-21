#ifndef XYBUTTON_H
#define XYBUTTON_H

#include <QWidget>

class XYButton : public QWidget
{
    Q_OBJECT
public:
    explicit XYButton(const QString &text, const QImage &icon, QWidget *parent = nullptr);
    void setChecked(bool check);
    void setCheckable(bool checkable);

signals:
    void checkChanged(bool checked);
    void clicked();

protected:
    void paintEvent(QPaintEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QImage   mIcon;      // 图标
    QString  mText;      // 控件文本
    bool     mCheckable; // 是否可选中
    bool     mChecked;   // 记录是否选择
    bool     mHover;     // 记录是否鼠标悬浮
    bool     mPressed;   // 记录是否鼠标按下

};

#endif // XYBUTTON_H
