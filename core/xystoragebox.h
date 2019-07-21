#ifndef XYSTORAGEBOX_H
#define XYSTORAGEBOX_H

#include <QWidget>

class XYButton;
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
