#ifdef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindows
{
    Q_OBJECT

public:
    explicit MainWindow(Qwidget *parent = 0 );
    ~MainWidow();

private:

    Ui::MainWindow *ui;

};

#endif