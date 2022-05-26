#ifndef EASY_CHAR_H
#define EASY_CHAR_H

#include "qstring.h"
#include "qmap.h"

class EasyString {
    QString storage;
    QMap<QString,QString> map;

public:

    EasyString(QString input): storage(input){
        map["#avto#"] = "©";
        map["#prom#"] = "‰";
        map["#regi#"] = "®";
        map["#evro#"] = "€";
        map["#rubl#"] = "₽";
    }

    QString get_symbols(){
        QString ext = storage;
        foreach(QString key, map.keys()){
            while (ext.contains(key)){
                ext.replace(key,map[key]);
            }
        }
        return ext;
    }


};

#endif // EASY_CHAR_H
