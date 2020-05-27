#ifndef COMPARAISON_H
#define COMPARAISON_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Comparaison; }
QT_END_NAMESPACE

class Comparaison : public QMainWindow
{
    Q_OBJECT

public:
    Comparaison(QWidget *parent = nullptr);
    ~Comparaison();

    void clearData();
    void plot();
    void give_datas(QVector<double> time,QVector<double> qv_y_cone_psi,QVector<double> qv_y_revolution_psi,QVector<double> qv_y_cone_theta,
                    QVector<double> qv_y_revolution_theta,QVector<double> qv_y_cone_phi,QVector<double> qv_y_revolution_phi,
                    QVector<double> qv_y_cone_psi_point,QVector<double> qv_y_revolution_psi_point,QVector<double> qv_y_cone_theta_point,
                    QVector<double> qv_y_revolution_theta_point,QVector<double> qv_y_cone_phi_point,QVector<double> qv_y_revolution_phi_point);

private slots:


    void on_button_psi_clicked();

    void on_button_theta_clicked();

    void on_button_phi_clicked();

    void on_button_psi_point_clicked();

    void on_button_theta_point_clicked();

    void on_button_phi_point_clicked();

    void on_button_clear_clicked();

private:

    Ui::Comparaison *ui;

    QVector<double> qv_x;
    QVector<double> qv_y_cone;
    QVector<double> qv_y_revolution;

    QVector<double> time_temp;

    QVector<double> qv_y_cone_psi;
    QVector<double> qv_y_revolution_psi;

    QVector<double> qv_y_cone_theta;
    QVector<double> qv_y_revolution_theta;

    QVector<double> qv_y_cone_phi;
    QVector<double> qv_y_revolution_phi;

    QVector<double> qv_y_cone_psi_point;
    QVector<double> qv_y_revolution_psi_point;

    QVector<double> qv_y_cone_theta_point;
    QVector<double> qv_y_revolution_theta_point;

    QVector<double> qv_y_cone_phi_point;
    QVector<double> qv_y_revolution_phi_point;

};
#endif // COMPARAISON_H
