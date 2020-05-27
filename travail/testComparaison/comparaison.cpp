#include "comparaison.h"
#include "ui_comparaison.h"

Comparaison::Comparaison(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Comparaison)
{
    ui->setupUi(this);

    ui->plot1->addGraph();
    ui->plot1->graph(0)->setPen(QPen(Qt::blue));
    ui->plot1->graph(0)->setLineStyle(QCPGraph::lsLine);

    ui->plot1->setInteraction(QCP::iRangeDrag,true);
    ui->plot1->setInteraction(QCP::iRangeZoom,true);

    ui->plot2->addGraph();
    ui->plot2->graph(0)->setPen(QPen(Qt::red));
    ui->plot2->graph(0)->setLineStyle(QCPGraph::lsLine);

    ui->plot2->setInteraction(QCP::iRangeDrag,true);
    ui->plot2->setInteraction(QCP::iRangeZoom,true);
}

Comparaison::~Comparaison()
{
    delete ui;
}

void Comparaison::clearData()
{
    qv_x.clear();
    qv_y_cone.clear();
    qv_y_revolution.clear();

}

void Comparaison::plot(){

    ui->plot1->graph(0)->setData(qv_x,qv_y_cone);
    ui->plot2->graph(0)->setData(qv_x,qv_y_revolution);

    ui->plot1->xAxis->setLabel("Time");
    ui->plot1->yAxis->setLabel("Cone");
    ui->plot1->rescaleAxes();
    ui->plot1->replot();
    ui->plot1->update();

    ui->plot2->xAxis->setLabel("Time");
    ui->plot2->yAxis->setLabel("Revolution");
    ui->plot2->rescaleAxes();
    ui->plot2->replot();
    ui->plot2->replot();
    ui->plot2->update();



}

void Comparaison::give_datas(QVector<double> time,QVector<double> qv_y_cone_psi1, QVector<double> qv_y_revolution_psi1, QVector<double> qv_y_cone_theta1,
                             QVector<double> qv_y_revolution_theta1, QVector<double> qv_y_cone_phi1, QVector<double> qv_y_revolution_phi1,
                             QVector<double> qv_y_cone_psi_point1, QVector<double> qv_y_revolution_psi_point1, QVector<double> qv_y_cone_theta_point1,
                             QVector<double> qv_y_revolution_theta_point1, QVector<double> qv_y_cone_phi_point1, QVector<double> qv_y_revolution_phi_point1)
{

    time_temp=time;

    qv_y_cone_psi=qv_y_cone_psi1;
    qv_y_cone_theta=qv_y_cone_theta1;
    qv_y_cone_phi=qv_y_cone_phi1;

    qv_y_cone_psi_point=qv_y_cone_psi_point1;
    qv_y_cone_theta_point=qv_y_cone_theta_point1;
    qv_y_cone_phi_point=qv_y_cone_phi_point1;

    qv_y_revolution_psi=qv_y_revolution_psi1;
    qv_y_revolution_theta=qv_y_revolution_theta1;
    qv_y_revolution_phi=qv_y_revolution_phi1;

    qv_y_revolution_psi_point=qv_y_revolution_psi_point1;
    qv_y_revolution_theta_point=qv_y_revolution_theta_point1;
    qv_y_revolution_phi_point=qv_y_revolution_phi_point1;




}

void Comparaison::on_button_psi_clicked()
{
    qv_x= time_temp;
    qv_y_cone=qv_y_cone_psi;
    qv_y_revolution=qv_y_revolution_psi;
    plot();

}

void Comparaison::on_button_theta_clicked()
{
    qv_x= time_temp;
    qv_y_cone=qv_y_cone_theta;
    qv_y_revolution=qv_y_revolution_theta;
    plot();

}

void Comparaison::on_button_phi_clicked()
{
    qv_x= time_temp;
    qv_y_cone=qv_y_cone_phi;
    qv_y_revolution=qv_y_revolution_phi;
    plot();
}

void Comparaison::on_button_psi_point_clicked()
{
    qv_x= time_temp;
    qv_y_cone=qv_y_cone_psi_point;
    qv_y_revolution=qv_y_revolution_psi_point;
    plot();

}

void Comparaison::on_button_theta_point_clicked()
{
    qv_x= time_temp;
    qv_y_cone=qv_y_cone_theta_point;
    qv_y_revolution=qv_y_revolution_theta_point;
    plot();

}

void Comparaison::on_button_phi_point_clicked()
{
    qv_x= time_temp;
    qv_y_cone=qv_y_cone_phi_point;
    qv_y_revolution=qv_y_revolution_phi_point;


    plot();
}

void Comparaison::on_button_clear_clicked()
{
    clearData();
    plot();
}
