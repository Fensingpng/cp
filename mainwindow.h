#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QLayout>


using namespace QtCharts;





#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QChart* chart;
    QChartView* chartView;
    QLineSeries* lineSeries;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int A, x1, fi, w;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
