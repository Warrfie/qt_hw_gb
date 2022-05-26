#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QStandardItemModel"

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


    void on_up_clicked();

    void on_down_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pic_only_clicked(bool checked);

    void on_Paint_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel table,model;
};
#endif // MAINWINDOW_H
