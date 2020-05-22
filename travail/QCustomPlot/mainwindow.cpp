#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->plot->addGraph();
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsLine);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPoint(double y)
{
 qv_x.append(qv_x.size());
 qv_y.append(y);
}

void MainWindow::clearData()
{
    qv_x.clear();
    qv_y.clear();
}

void MainWindow::plot()
{
  ui->plot->graph(0)->setData(qv_x,qv_y);
  ui->plot->replot();
  ui->plot->update();
}

void MainWindow::changeData()
{

}



void MainWindow::on_Clear_Button_clicked()
{

}

void MainWindow::on_Change_button_clicked()
{
    clearData();
    plot();
}
