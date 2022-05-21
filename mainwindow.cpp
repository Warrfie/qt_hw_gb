#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtMath"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_solve_clicked()
{
    ui->answer->clear();
    float a = ui->a->text().toFloat();
    float b = ui->b->text().toFloat();
    float c = ui->c->text().toFloat();
    if(a == 0 && b == 0){
        ui->answer->setText("Не имеет корней!");
        return;
    }else if (a == 0) {
        float x = -c/b;
        QString answer = "X=";
        answer.append(QString::number(x));
        ui->answer->setText(answer);
        return;
    }
    float disc = b*b-4*a*c;
    if (disc>0){
        float x_1 = (qSqrt(disc)-b)/(2*a);
        float x_2 = (-qSqrt(disc)-b)/(2*a);
        QString answer = "X(1)=";
        answer.append(QString::number(x_1));
        answer.append(" X(2)=");
        answer.append(QString::number(x_2));
        ui->answer->setText(answer);
    }else if (disc==0){
        float x = -b/(2*a);
        QString answer = "X=";
        answer.append(QString::number(x));
        ui->answer->setText(answer);
    }else{
        ui->answer->setText("Не имеет корней!");
    }
}


void MainWindow::on_solve_triangle_clicked()
{
    ui->answer_triangle->clear();
    float a = ui->ab->text().toFloat();
    float b = ui->bc->text().toFloat();
    float angle = ui->b_angle->text().toFloat();
    if (ui->grad->isChecked()){
        angle = qDegreesToRadians(angle);
    }
    if(a == 0 || b == 0 || angle == 0){
        ui->answer->setText("Не треугольник!");
        return;
    }
    float x = qSqrt(a*a+b*b-2*a*b*qCos(angle));
    QString answer = "AC=";
    answer.append(QString::number(x));
    ui->answer_triangle->setText(answer);
}


void MainWindow::on_add_clicked()
{
    ui->text_out->appendPlainText(ui->text_in->toPlainText());
}


void MainWindow::on_replace_clicked()
{
    ui->text_out->setPlainText(ui->text_in->toPlainText());
}


void MainWindow::on_html_clicked()
{
    ui->text_in->appendHtml("<font color='red'>Hello</font>");

}
