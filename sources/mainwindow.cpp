
# include "../headlines/mainwindow.h"
# include "../forms/ui_untitled.h"


MainWindow::MainWindow(Qwidget *parent):
QMainWindow(parent),
ui(new Ui::MainWindow)
{
ui->setupUi(this);
}

MainWindow::~MainWindindow()
{
    delete ui;
}