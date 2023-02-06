#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"
#include "QDebug"
#include "complex"
#include "cmath"
#include <QtGui>
#include <iostream>
#include <fstream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chartView=new QChartView;
    chart=new QChart;
    lineSeries = new QLineSeries;
    chart->addSeries(lineSeries);
    chartView->setChart(chart);
    ui->centralwidget->layout()->addWidget(chartView);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    A = ui->doubleSpinBox_2->value();
    x1= ui->doubleSpinBox->value();
    w = ui->doubleSpinBox_3->value();
    fi= ui->doubleSpinBox_4->value();
    lineSeries->clear();
    double t =-x1;
    while (t<=x1)
    {
        lineSeries->append(t, A*cos(w*t+fi));
        //
        t+=0.1;
    }
    chart->zoomReset();
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical)[0]->setRange(-A-0.2,A+0.2);
    chart->axes(Qt::Horizontal)[0]->setRange(-t,t);
}



void MainWindow::on_pushButton_2_clicked()
{
    A = ui->doubleSpinBox_2->value();
    x1= ui->doubleSpinBox->value();
    w = ui->doubleSpinBox_3->value();
    fi= ui->doubleSpinBox_4->value();
    lineSeries->clear();
    double t =0;
    while (t<=A)
    {
        lineSeries->append(w, t);
        //
        t+=0.1;
    }
    chart->zoomReset();
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical)[0]->setRange(0,A+1);
    chart->axes(Qt::Horizontal)[0]->setRange(0,w+1);
}

void MainWindow::on_pushButton_3_clicked()
{
    A = ui->doubleSpinBox_2->value();
    x1= ui->doubleSpinBox->value();
    w = ui->doubleSpinBox_3->value();
    fi= ui->doubleSpinBox_4->value();
    double t =-x1;


    std::ofstream out;
        out.open("C:\\Users\\Admin\\Desktop\\111.txt");
        if (out.is_open())
        {
            while (t<=x1)
            {
                double c=A*cos(w*t+fi);
            out <<"("<< t<<";" <<c<<")"<< std::endl;
            t+=0.1;
            }
        }

        std::cout << "End of program" << std::endl;


}
