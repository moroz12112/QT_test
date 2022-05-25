
# include "../headlines/mainwindow.h"
# include "../forms/ui_untitled.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent):
    QDialog (parent), cc(0),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(manual_connection_manu()));
    //connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_clac_clicked()));
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
    ui->lineEdit->setText(QString("%1").arg(def) + "        " + ui->lineEdit->text());
    ui->lineEdit_3->setText(ui->lineEdit_2->text()) ;
}

void MainWindow::on_pushButton_2_clicked()
{
    emit rotate(cc++);
}

void MainWindow::manual_connection_manu()
{
    emit rotate(--cc);
}

void MainWindow::rotateReceiver(int v)
{
    ui->lineEdit->setText(QString("%1").arg(v));
}

//void MainWindow::on_pushButton_clicked(){

 //   ui->label->setText("пока");

//}