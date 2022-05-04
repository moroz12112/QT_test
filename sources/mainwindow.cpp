
# include "../headlines/mainwindow.h"
# include "../forms/ui_untitled.h"


#include <iostream>
#include <unistd.h>


MainWindow::MainWindow(QWidget *parent):
    QDialog (parent), cc(0),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->manu, SIGNAL(clicked()), this, SLOT(manual_connection_manu()));
    connect(this, SIGNAL(rotate(int)), this, SLOT(receiveRotate(int)));
    connect(this, SIGNAL(rotate(int)), this, SLOT(rotateReceiver(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveRotate(int def)
{
    std::cout<<"receiveRotate with value "<<def<<std::endl;
    ui->schr->setText(QString("%1").arg(def) + "        " + ui->schr->text());
}

void MainWindow::on_clac_clicked()
{
    emit rotate(cc++);
}

void MainWindow::manual_connection_manu()
{
    emit rotate(--cc);
}

void MainWindow::rotateReceiver(int v)
{
    ui->schr->setText(QString("%1").arg(v));
}
