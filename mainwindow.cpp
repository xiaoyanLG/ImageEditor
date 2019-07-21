#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xyfuncplugin.h"
#include "xystoragebox.h"
#include "xyfuncproxywidget.h"
#include "xyfuncpanelwidget.h"
#include "xybutton.h"
#include "plugins/crop/xycropfunc.h"
#include <QFileDialog>
#include <QPluginLoader>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initFrame();
    initFuncsBox();
    initStorageBox();
    resize(800, 600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initFrame()
{
    ui->splitter->setStretchFactor(0, 0);
    ui->splitter->setStretchFactor(1, 1);
    ui->splitter->setStretchFactor(2, 0);

    ui->FuncsBox->setVisible(false);
    ui->FuncPanelsBox->setVisible(false);
}

void MainWindow::initFuncsBox()
{
    XYCropFunc *crop = new XYCropFunc;
    auto func = crop->createFuncProxy();
    if (func != nullptr)
    {
        ui->FuncsBox->addFunc(func);
        auto funcPanel = func->createFuncPanel();
        if (funcPanel != nullptr)
        {
            funcPanel->setImageViewer(ui->ImageViewer);
            ui->FuncPanelsBox->addFuncPanel(funcPanel);
        }
    }

    // 加载插件
    QDir dir("./plugins");
    auto dlls = dir.entryList(QDir::Files);
    for (QString dll : dlls)
    {
        QPluginLoader loader(dir.filePath(dll));
        if (loader.load())
        {
            QString IID = loader.metaData().value("IID").toString();
            if (IID == XYFuncPluginInterface_iid)
            {
                XYFuncPlugin *plugin = reinterpret_cast<XYFuncPlugin *>(loader.instance());
                auto func = plugin->createFuncProxy();
                if (func != nullptr)
                {
                    ui->FuncsBox->addFunc(func);
                    auto funcPanel = func->createFuncPanel();
                    if (funcPanel != nullptr)
                    {
                        funcPanel->setImageViewer(ui->ImageViewer);
                        ui->FuncPanelsBox->addFuncPanel(funcPanel);
                    }
                }
            }
        }
    }
}

void MainWindow::initStorageBox()
{
    XYStorageBox *box = ui->StorageBox;
    auto btn = box->addButton(QStringLiteral("功能盒子"), QImage(":/func.ico"));
    connect(btn, &XYButton::clicked, this, [this]() {
        this->ui->FuncsBox->setVisible(!this->ui->FuncsBox->isVisible());
    });
    btn = box->addButton(QStringLiteral("功能扩展盒子"), QImage(":/extend.ico"));
    connect(btn, &XYButton::clicked, this, [this]() {
        this->ui->FuncPanelsBox->setVisible(!this->ui->FuncPanelsBox->isVisible());
    });
    box->addStretch();

    btn = box->addButton(QStringLiteral("恢复原始"), QImage(":/restore.ico"));
    connect(btn, &XYButton::clicked, ui->ImageViewer, &XYImageViewer::restore);
    btn = box->addButton(QStringLiteral("居中"), QImage(":/centered.ico"));
    connect(btn, &XYButton::clicked, ui->ImageViewer, &XYImageViewer::moveImageToCenter);
    btn = box->addButton(QStringLiteral("自适应"), QImage(":/adaptive.ico"));
    connect(btn, &XYButton::clicked, ui->ImageViewer, &XYImageViewer::adaptive);
    btn = box->addButton(QStringLiteral("缩小内部（保持图片大小）"), QImage(":/zoomout.ico"));
    connect(btn, &XYButton::clicked, ui->ImageViewer, &XYImageViewer::zoomOutContents);

    btn = box->addButton(QStringLiteral("上一张"), QImage(":/left.ico"));
    connect(btn, &XYButton::clicked, ui->ImageViewer, &XYImageViewer::previous);
    btn = box->addButton(QStringLiteral("下一张"), QImage(":/right.ico"));
    connect(btn, &XYButton::clicked, ui->ImageViewer, &XYImageViewer::next);

    btn = box->addButton(QStringLiteral("向左旋转"), QImage(":/rotate_left.ico"));
    connect(btn, &XYButton::clicked, ui->ImageViewer, [this](){
        ui->ImageViewer->rolate(-90);
    });
    btn = box->addButton(QStringLiteral("向右旋转"), QImage(":/rotate_right.ico"));
    connect(btn, &XYButton::clicked, ui->ImageViewer, [this](){
        ui->ImageViewer->rolate(90);
    });
    btn = box->addButton(QStringLiteral("保存"), QImage(":/save.ico"));
    connect(btn, &XYButton::clicked, ui->ImageViewer, &XYImageViewer::save);
    btn = box->addButton(QStringLiteral("删除"), QImage(":/delete.ico"));
    connect(btn, &XYButton::clicked, ui->ImageViewer, &XYImageViewer::deleteCurrentImage);

    box->addStretch();
    box->addSpacing(72);
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this);
    if (!file.isEmpty())
    {
        ui->ImageViewer->initImage(file);
    }
}

void MainWindow::on_actionRestore_triggered()
{
    ui->ImageViewer->restore();
}
