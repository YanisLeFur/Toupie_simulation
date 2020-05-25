#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void clearData();
    void plot();
    void transmet(QVector<double> time, QVector<double> y_energie_RK,                                       //transmet les coordonées prise pour les invariant d'une toupie au widget
                  QVector<double> y_prod_mixt_RK, QVector<double> y_LA_a_RK, QVector<double> y_LA_k_RK,
                  QVector<double> y_energie_NM, QVector<double> y_prod_mixt_NM,
                  QVector<double> y_LA_a_NM, QVector<double> y_LA_k_NM, QVector<double> y_energie_EC,
                  QVector<double> y_prod_mixt_EC, QVector<double> y_LA_a_EC, QVector<double> y_LA_k_EC);

private slots:

    void on_Clear_Button_clicked();  //fonctions utilisant les boutons du widget

    void on_Energie_button_clicked();

    void on_Prod_mixt_button_2_clicked();

    void on_LA_a_button_3_clicked();

    void on_LA_k_button_clicked();

    void on_Scale_button_clicked();

private:
    Ui::MainWindow *ui;

    QVector<double> qv_x;
    QVector<double> qv_y_RK;
    QVector<double> qv_y_NM;
    QVector<double> qv_y_EC;


    QVector<double> time_temp;

    QVector<double> qv_y_energie_RK;
    QVector<double> qv_y_prod_mixt_RK;
    QVector<double> qv_y_LA_a_RK;
    QVector<double> qv_y_LA_k_RK;

    QVector<double> qv_y_energie_NM;
    QVector<double> qv_y_prod_mixt_NM;
    QVector<double> qv_y_LA_a_NM;
    QVector<double> qv_y_LA_k_NM;

    QVector<double> qv_y_energie_EC;
    QVector<double> qv_y_prod_mixt_EC;
    QVector<double> qv_y_LA_a_EC;
    QVector<double> qv_y_LA_k_EC;
};
#endif // MAINWINDOW_H
