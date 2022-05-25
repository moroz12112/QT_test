
# include "../headlines/mainwindow.h"
# include "../forms/ui_untitled.h"


#include <iostream>
#include <unistd.h>


KDL_CHAIN::KDL_CHAIN(double j1, double j2, double j3, double j4, double j5, double j6)
{
    j[0] = j1;
    j[1] = j2;
    j[2] = j3;
    j[3] = j4;
    j[4] = j5;
    j[5] = j6;

    ourChain.addSegment( KDL::Segment( std::string("world -> "),
            KDL::Joint( std::string("world_joint0"), KDL::Joint::RotY),
            KDL::Frame( KDL::Rotation::Identity(), {0, 0, 0.})));

    ourChain.addSegment( KDL::Segment( std::string("link001 -> link002"),
            KDL::Joint( std::string("j2"), {0, 0, 0}, {0.4330127, 0.25, 0.8660254}, KDL::Joint::RotAxis),
            KDL::Frame( KDL::Rotation::RPY(-0.7137243789447655, 0.848062078981481, -0.8570719478501307)   , {0.165, 0, 0})));

    ourChain.addSegment( KDL::Segment( std::string("base_link tip -> a1_link tip"),
            KDL::Joint( std::string("a1_joint"), KDL::Joint::RotY),
            KDL::Frame( KDL::Rotation::RotX(3.1416), {0.2175, -0.118, 0})));
    ourChain.addSegment( KDL::Segment( std::string("a1_link tip -> a2_link tip"),
            KDL::Joint( std::string("a2_joint"), KDL::Joint::RotX, -1),
            KDL::Frame( KDL::Rotation::RotZ(3.1416), {-0.0935, 0.5, 0})));
    ourChain.addSegment( KDL::Segment( std::string("a2_link tip -> a3_link tip"),
            KDL::Joint( std::string("a3_joint"), KDL::Joint::RotX, -1),
            KDL::Frame( KDL::Rotation::RotZ(3.1416), {0.065001,-0.1505, 0})));
    ourChain.addSegment( KDL::Segment( std::string("a3_link  tip -> a4_link tip"),
            KDL::Joint( std::string("a4_joint"), KDL::Joint::RotY, -1),
            KDL::Frame( KDL::Rotation::Identity(), {0.1055, 0.3765, 0})));

    ourChain.addSegment( KDL::Segment( std::string("a4_link tip -> a5_link tip"),
            KDL::Joint( std::string("a5_joint"), KDL::Joint::RotX, 1),
            KDL::Frame( KDL::Rotation::Identity(), {0.0175, 0.174, 0})));

}


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
