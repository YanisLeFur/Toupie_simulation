#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void MakePlot(QVector<double>,QVector<double>,QVector<double>);
private:
    Ui::MainWindow *ui;
    QVector<double> time;
    QVector<double> x;
    QVector<double> y;
};
#endif // MAINWINDOW_H
