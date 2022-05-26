#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model_filler.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->all_lang->setModel(&model);
    ui->all_lang->setSelectionMode(QAbstractItemView::SingleSelection);

    fill_model(&model);

    ui->ip_table->setModel(&table);

    fill_table(&table);

    ui->ip_table->resizeColumnsToContents();

    table.setHorizontalHeaderLabels({"No","Имя","IP","MAC"});

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_up_clicked()
{
    auto selection_model = ui->all_lang->selectionModel();
    if (selection_model->hasSelection()){
        QModelIndex cur_ind = selection_model->currentIndex();
        if (cur_ind.isValid() && cur_ind.row()!=0){
            QStandardItem *item = model.item(cur_ind.row()-1)->clone();
            model.removeRow(cur_ind.row()-1);
            model.insertRow(cur_ind.row(),item);

        }
    }
}


void MainWindow::on_down_clicked()
{
    auto selection_model = ui->all_lang->selectionModel();
    if (selection_model->hasSelection()){
        QModelIndex cur_ind = selection_model->currentIndex();
        if (cur_ind.isValid() && cur_ind.row()!=ui->all_lang->model()->rowCount()-1){
            QStandardItem *item = model.item(cur_ind.row()+1)->clone();
            model.removeRow(cur_ind.row()+1);
            model.insertRow(cur_ind.row(),item);

        }
    }

}


void MainWindow::on_pushButton_clicked()
{
    add_item(&model);
}


void MainWindow::on_pushButton_2_clicked()
{
    auto selection_model = ui->all_lang->selectionModel();
    if (selection_model->hasSelection()){
        QModelIndex cur_ind = selection_model->currentIndex();
        if (cur_ind.isValid()){
            model.removeRow(cur_ind.row());
        }
    }
}


void MainWindow::on_pic_only_clicked(bool checked)
{
    if (checked){
        ui->all_lang->setViewMode(QListView::IconMode);
    }else{
        ui->all_lang->setViewMode(QListView::ListMode);
    }
}


void MainWindow::on_Paint_clicked()
{
    auto selection_model = ui->ip_table->selectionModel();
    if (selection_model->hasSelection()){
        QModelIndex cur_ind = selection_model->currentIndex();
        if (cur_ind.isValid()){
            for (int i=0;i<4;i++){
                table.item(cur_ind.row(),i)->setBackground(QBrush(QColor(Qt::lightGray)));
            }
        }
    }
}

