#ifndef XYSTORAGEBOX_H
#define XYSTORAGEBOX_H

#include <QWidget>

class XYButton : public QWidget
{
    Q_OBJECT
public:
    explicit XYButton(const QString &text, const QImage &icon, QWidget *parent = nullptr);
    void setChecked(bool check);

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
    QImage   mIcon;     // 图标
    QString  mText;     // 控件文本
    bool     mChecked;  // 记录是否选择
    bool     mHover;    // 记录是否鼠标悬浮
    bool     mPressed;  // 记录是否鼠标按下

};

class XYStorageBox : public QWidget
{
    Q_OBJECT
public:
    explicit XYStorageBox(QWidget *parent = nullptr);
    void addStretch(int stretch = 0);
    void addSpacing(int space);
    XYButton *addButton(const QString &name, const QImage &icon);

protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif // XYSTORAGEBOX_H
