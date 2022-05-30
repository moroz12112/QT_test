
# include "../headlines/mainwindow.h"
# include "../forms/ui_untitled.h"
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <iostream>

MainWindow::MainWindow(QWidget *parent):
    QDialog (parent), cc(0),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
    ui->comboBox->addItem(info.portName(),info.portName());
    }

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(manual_connection_manu()));
    connect(this, SIGNAL(rotate(int)), this, SLOT(receiveRotate(int)));
    connect(this, SIGNAL(rotate(int)), this, SLOT(rotateReceiver(int)));
    connect(serial, SIGNAL(readyRead()), this, SLOT(serialRecieve()));
    connect(ui->pushButtonOpenPort, SIGNAL(clicked()), this, SLOT(OpenPort()));
    connect(ui->pushButtonClosePort, SIGNAL(clicked()), this, SLOT(ClosePorts()));

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

void MainWindow::serialRecieve()
{
    QByteArray ba;
    ba = serial->readAll();
    ui->lineEdit_10->setText(ba.toHex());
}

void MainWindow::OpenPort()
{
    serial = new QSerialPort(this);
    serial->setPortName(ui->comboBox->currentText());
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    serial->write("привет");
}

void MainWindow::ClosePorts()
{
    delete serial;
}