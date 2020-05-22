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

    void addPoint(double y);
    void clearData();
    void plot();
    void changeData();

private slots:

    void on_Clear_Button_clicked();

    void on_Change_button_clicked();

private:
    Ui::MainWindow *ui;

    QVector<double> qv_x;
    QVector<double> qv_y;
};
#endif // MAINWINDOW_H
