#ifndef XYEXPANSIONSBOX_H
#define XYEXPANSIONSBOX_H

#include <QWidget>

class XYFuncPanelWidget;
class XYFuncPanelsBox : public QWidget
{
    Q_OBJECT
public:
    explicit XYFuncPanelsBox(QWidget *parent = nullptr);
    void addFuncPanel(XYFuncPanelWidget *panel);
    void setCurrentPanel(XYFuncPanelWidget *panel);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // XYEXPANSIONSBOX_H
