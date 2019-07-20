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

    btn = box->addButton(QStringLiteral("上一张"), QImage(":/left.ico"));
    connect(btn, &XYButton::clicked, ui->ImageViewer, &XYImageViewer::previous);
    btn = box->addButton(QStringLiteral("下一张"), QImage(":/right.ico"));
    connect(btn, &XYButton::clicked, ui->ImageViewer, &XYImageViewer::next);
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
