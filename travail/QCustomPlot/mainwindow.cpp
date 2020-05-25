#include "mainwindow.h"
#include "ui_mainwindow.h"


//Constructeur du MainWindow=========================================================================================
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->plot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as decimal separator and comma as thousand separator
    ui->plot->legend->setVisible(true);
    QFont legendFont = font();  // start out with MainWindow's font..
    legendFont.setPointSize(9); // and make a bit smaller for legend
    ui->plot->legend->setFont(legendFont);
    ui->plot->legend->setBrush(QBrush(QColor(255,255,255,230)));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:
    ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);


    ui->plot->setInteraction(QCP::iRangeDrag,true);
    ui->plot->setInteraction(QCP::iRangeZoom,true);

    ui->plot->addGraph();
    ui->plot->graph(0)->setPen(QPen(Qt::blue));
    ui->plot->graph(0)->setName("Runge-Kutta");
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->plot->addGraph();
    ui->plot->graph(1)->setPen(QPen(Qt::red));
    ui->plot->graph(1)->setName("Newmark");
    ui->plot->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->plot->addGraph();
    ui->plot->graph(2)->setPen(QPen(Qt::black));
    ui->plot->graph(2)->setName("Euler-Cromer");
    ui->plot->graph(2)->setLineStyle(QCPGraph::lsLine);
}
//Destructeur du MainWindow=========================================================================================
MainWindow::~MainWindow()
{
    delete ui;
}
//=================================================================================================================
void MainWindow::clearData()
{
    qv_x.clear();
    qv_y_RK.clear();
    qv_y_NM.clear();
    qv_y_EC.clear();
}
//=================================================================================================================
void MainWindow::plot()
{

  ui->plot->graph(0)->setData(qv_x,qv_y_RK);
  ui->plot->graph(1)->setData(qv_x,qv_y_NM);
  ui->plot->graph(2)->setData(qv_x,qv_y_EC);
  ui->plot->xAxis->setLabel("time");
  ui->plot->yAxis->setLabel("invariant");
  ui->plot->replot();
  ui->plot->update();
  ui->plot->xAxis->setRange(0, 50);
  ui->plot->yAxis->setRange(0, 60);

}
//=================================================================================================================
void MainWindow::transmet(QVector<double> time_plot,QVector<double> y_energie_RK, QVector<double> y_prod_mixt_RK,
                          QVector<double> y_LA_a_RK,QVector<double> y_LA_k_RK,
                          QVector<double> y_energie_NM, QVector<double> y_prod_mixt_NM,
                          QVector<double> y_LA_a_NM,QVector<double> y_LA_k_NM,
                          QVector<double> y_energie_EC, QVector<double> y_prod_mixt_EC,
                          QVector<double> y_LA_a_EC,QVector<double> y_LA_k_EC           ){

           time_temp=time_plot;

           qv_y_energie_RK=y_energie_RK ;
           qv_y_prod_mixt_RK=y_prod_mixt_RK ;
           qv_y_LA_a_RK=y_LA_a_RK ;
           qv_y_LA_k_RK=y_LA_k_RK ;

           qv_y_energie_NM=y_energie_NM ;
           qv_y_prod_mixt_NM=y_prod_mixt_NM ;
           qv_y_LA_a_NM=y_LA_a_NM ;
           qv_y_LA_k_NM=y_LA_k_NM ;

           qv_y_energie_EC=y_energie_EC ;
           qv_y_prod_mixt_EC=y_prod_mixt_EC ;
           qv_y_LA_a_EC=y_LA_a_EC ;
           qv_y_LA_k_EC=y_LA_k_EC ;


}
//=================================================================================================================
void MainWindow::on_Clear_Button_clicked()
{
    clearData();
    plot();
}
//=================================================================================================================
void MainWindow::on_Energie_button_clicked()
{
    clearData();
    qv_x=time_temp;
    qv_y_RK=qv_y_energie_RK;
    qv_y_NM=qv_y_energie_NM;
    qv_y_EC=qv_y_energie_EC;
    plot();

}
//=================================================================================================================
void MainWindow::on_Prod_mixt_button_2_clicked()
{
    clearData();
    qv_x=time_temp;
    qv_y_RK=qv_y_prod_mixt_RK;
    qv_y_NM=qv_y_prod_mixt_NM;
    qv_y_EC=qv_y_prod_mixt_EC;
    plot();

}
//=================================================================================================================
void MainWindow::on_LA_a_button_3_clicked()
{
    clearData();
    qv_x=time_temp;
    qv_y_RK=qv_y_LA_a_RK;
    qv_y_NM=qv_y_LA_a_NM;
    qv_y_EC=qv_y_LA_a_EC;
    plot();

}
//=================================================================================================================
void MainWindow::on_LA_k_button_clicked()
{
    clearData();
    qv_x=time_temp;
    qv_y_RK=qv_y_LA_k_RK;
    qv_y_NM=qv_y_LA_k_NM;
    qv_y_EC=qv_y_LA_k_EC;
    plot();
}
//=================================================================================================================
void MainWindow::on_Scale_button_clicked()
{
    ui->plot->xAxis->setRange(*std::min_element(qv_x.begin(),qv_x.end()),*std::max_element(qv_x.begin(),qv_x.end()));
    ui->plot->yAxis->setRange(*std::min_element(qv_y_RK.begin(),qv_y_RK.end()),*std::max_element(qv_y_NM.begin(),qv_y_NM.end()));
    plot();
}
//=================================================================================================================
