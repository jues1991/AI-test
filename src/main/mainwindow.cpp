#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "workspace.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    QGraphicsView *gw = ui->graphicsView;
    WorkSpace *ws = dynamic_cast<WorkSpace*>(gw->scene());
    //
    if ( nullptr != ws )
    {
        delete ws;
    }

    //
    ws = new WorkSpace();
    gw->setScene(ws);
}
