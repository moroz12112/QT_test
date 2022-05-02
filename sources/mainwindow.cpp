
# include "../headlines/mainwindow.h"
# include "../forms/ui_untitled.h"


MainWindow::MainWindow(QWidget *parent):
    QDialog (parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}