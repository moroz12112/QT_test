#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>



namespace Ui {
    class Dialog;
};

class MainWindow : public  QDialog 
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0 );
    ~MainWindow();

signals:
    void rotate(int deg_cw);

public slots:
    void receiveRotate(int def);
    void on_pushButton_2_clicked();
    void manual_connection_manu();
    void rotateReceiver(int);
    void serialRecieve();
    void  OpenPort();
    void  ClosePorts();

private:
    int cc;
    Ui::Dialog *ui;
    QSerialPort *serial;

};

#endif