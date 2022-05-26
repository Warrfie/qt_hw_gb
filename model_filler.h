#ifndef MODEL_FILLER_H
#define MODEL_FILLER_H

#include "qnetworkrequest.h"
#include "qnetworkaccessmanager.h"
#include "qnetworkreply.h"
#include "QStandardItemModel"
#include "QEventLoop"
#include "QApplication"
#include "QStyle"
#include "QVector"

QMap<QString,QString> load_lang_map(){
    QMap<QString,QString> map;
    map["C++"] = "https://icons-for-free.com/iconfiles/png/512/bxl+c+plus+plus-1325051931431540241.png";
    map["Python"] = "https://icons-for-free.com/iconfiles/png/512/python+original-1324760557612294785.png";
    map["Java"] = "https://icons-for-free.com/iconfiles/png/512/java+original-1324760550667278175.png";
    map["C#"] = "https://icons-for-free.com/iconfiles/png/512/C-1324888703033939247.png";
    map["PHP"] = "https://icons-for-free.com/iconfiles/png/512/php+plain-1324760555060951567.png";
    map["JavaScript"] = "https://icons-for-free.com/iconfiles/png/512/javascript+original-1324760550805182024.png";
    return map;
}

QVector<QList<QStandardItem*>> load_table(){
    QList first = {new QStandardItem("1"),new QStandardItem("Maxim"),new QStandardItem("192.168.5.0"),new QStandardItem("00:30:48:5a:58:65")};
    QList second = {new QStandardItem("2"),new QStandardItem("Oleg"),new QStandardItem("192.168.5.2"),new QStandardItem("00:30:H1:5a:58:65")};
    QList third = {new QStandardItem("3"),new QStandardItem("Arsen"),new QStandardItem("192.168.5.3"),new QStandardItem("00:30:G5:5a:58:65")};
    QVector<QList<QStandardItem*>> ext;
    ext.append(first);
    ext.append(second);
    ext.append(third);
    return ext;
}

QPixmap get_image(QString url){
    QNetworkAccessManager *networkManager;
    QNetworkRequest request;
    request.setUrl(QUrl(url));

    networkManager = new QNetworkAccessManager();
    QNetworkReply* reply=networkManager->get(request);
    QEventLoop eventLoop;
    QObject::connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    QPixmap buttonImage;
    buttonImage.loadFromData(reply->readAll());

    delete networkManager;

    return buttonImage;
}

void fill_model(QStandardItemModel *model){
    QMap<QString,QString> map = load_lang_map();
    foreach(QString key, map.keys()){
        model->appendRow(new QStandardItem(get_image(map[key]),key));
    }
}

void add_item(QStandardItemModel *model){

    model->appendRow(new QStandardItem((QIcon(QApplication::style()->standardIcon(QStyle::SP_TitleBarMenuButton))),""));
}

void fill_table(QStandardItemModel *table){
    foreach(QList<QStandardItem*> row,load_table()){
        table->appendRow(row);
    }

}

#endif // MODEL_FILLER_H
