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

signals:
    void rotate(int deg_cw);

public slots:
    void receiveRotate(int def);
    void on_clac_clicked();
    void manual_connection_manu();
    void rotateReceiver(int);


private:
    int cc;

    Ui::Dialog *ui;

};

#define JOINTS_COUNT 6
#include <kdl/chainiksolverpos_nr_jl.hpp>
#include <kdl/chain.hpp>
#include <kdl/frames.hpp>
#include <kdl/frames_io.hpp>
#include <kdl/chainfksolver.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/chainiksolvervel_pinv.hpp>
#include <kdl/chainiksolvervel_wdls.hpp>
#include <kdl/chainiksolverpos_nr.hpp>

class KDL_CHAIN {
    double j[JOINTS_COUNT];
    KDL::Chain ourChain;

  public:
    KDL_CHAIN(double j1=0., double j2=0., double j3=0., double j4=0, double j5=0, double j6=0);
    bool evaluate();
    double getX() const;
};

#endif
