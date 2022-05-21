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
    void on_solve_clicked();

    void on_solve_triangle_clicked();

    void on_add_clicked();

    void on_replace_clicked();

    void on_html_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
