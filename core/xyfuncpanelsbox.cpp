#include "xyfuncpanelsbox.h"
#include "xyfuncpanelwidget.h"
#include <QPainter>
#include <QStackedLayout>

XYFuncPanelsBox::XYFuncPanelsBox(QWidget *parent)
    : QWidget(parent)
{
    setMinimumWidth(150);

    setLayout(new QStackedLayout);
}

void XYFuncPanelsBox::addFuncPanel(XYFuncPanelWidget *panel)
{
    layout()->addWidget(panel);

    connect(panel, &XYFuncPanelWidget::proxyClicked, this, [this, panel]() {
        this->setCurrentPanel(panel);
        if (!this->isVisible())
        {
            this->setVisible(true);
        }
    });
}

void XYFuncPanelsBox::setCurrentPanel(XYFuncPanelWidget *panel)
{
    QStackedLayout *stacked = qobject_cast<QStackedLayout *>(layout());
    stacked->setCurrentWidget(panel);
}

void XYFuncPanelsBox::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.fillRect(rect(), QColor(Qt::darkGreen));
    painter.drawText(rect(), QStringLiteral("功能扩展盒子区域"), QTextOption(Qt::AlignCenter));
}
