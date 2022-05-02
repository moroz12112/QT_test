#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>

namespace Ui {
    class Dialog;
};

class MainWindow : public  QDialog 
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0 );
    ~MainWindow();

private:

    Ui::Dialog *ui;

};

#endif