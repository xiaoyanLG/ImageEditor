#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xystoragebox.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initFrame();
    initFuncsBox();
    initExpansionsBox();
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
    ui->ExpansionsBox->setVisible(false);
}

void MainWindow::initFuncsBox()
{

}

void MainWindow::initExpansionsBox()
{

}

void MainWindow::initStorageBox()
{
    XYStorageBox *box = ui->StorageBox;
    auto btn = box->addButton(QStringLiteral("功能盒子"), QImage(":/func.ico"));
    connect(btn, &XYButton::clicked, this, [this](){
        this->ui->FuncsBox->setVisible(!this->ui->FuncsBox->isVisible());
    });
    btn = box->addButton(QStringLiteral("功能扩展盒子"), QImage(":/extend.ico"));
    connect(btn, &XYButton::clicked, this, [this](){
        this->ui->ExpansionsBox->setVisible(!this->ui->ExpansionsBox->isVisible());
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
    box->addSpacing(36);
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
