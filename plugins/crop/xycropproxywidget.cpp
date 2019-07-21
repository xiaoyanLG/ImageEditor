#include "xycropproxywidget.h"
#include "xycroppanelwidget.h"
#include "xybutton.h"
#include <QHBoxLayout>

XYCropProxyWidget::XYCropProxyWidget()
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    XYButton *btn = new XYButton(QStringLiteral("图片裁剪"), QImage(":/cut.ico"));
    layout->setMargin(0);
    layout->addWidget(btn);

    connect(btn, &XYButton::clicked, this, &XYCropProxyWidget::clicked);
}

XYFuncPanelWidget *XYCropProxyWidget::createFuncPanel()
{
    return new XYCropPanelWidget(this);
}
