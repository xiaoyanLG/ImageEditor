#ifndef XYEXPANSIONSBOX_H
#define XYEXPANSIONSBOX_H

#include <QWidget>

class XYExpansionsBox : public QWidget
{
    Q_OBJECT
public:
    explicit XYExpansionsBox(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // XYEXPANSIONSBOX_H
