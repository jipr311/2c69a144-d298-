#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#include "BaseRequest.h"
#include "Point.h"
#include "Person.h"
#include "Robot.h"
#include "Factory.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    {
        nlohmann::json j = "{ \"robot\": {\"modelName\": \"iiwa\"}, \"point\": {\"x\": 17, \"y\": 17} }"_json;
        qDebug() << "j: " << j.dump().c_str();
        json::Factory p = j;
        qDebug() << "p: " << p.getIsValid();
        qDebug() << "p3: " << p.getR().getModelName().c_str();
        if(p)
        {
            qDebug() << "p: " << p.getIsValid();
            p.getChunk();
            qDebug() << "pp.getChunk(): " << p.getChunk().dump().c_str();
        }
    }
    {
        nlohmann::json j = "{ \"x\": 12, \"y\": 12 }"_json;
        qDebug() << "j: " << j.dump().c_str();
        json::Point p = j;
        qDebug() << "p: " << p.getIsValid();
        qDebug() << "p3: " << p.getX();
        if(p)
        {
            qDebug() << "p: " << p.getIsValid();
            p.getChunk();
            qDebug() << "pp.getChunk(): " << p.getChunk().dump().c_str();
        }
    }
    {
        nlohmann::json j = "{ \"modelName\": \"UR5\" }"_json;
        qDebug() << "j: " << j.dump().c_str();
        json::Robot p = j;
        qDebug() << "p: " << p.getIsValid();
        qDebug() << "p3: " << p.getModelName().c_str();
        if(p)
        {
            qDebug() << "p: " << p.getIsValid();
            p.getChunk();
            qDebug() << "pp.getChunk(): " << p.getChunk().dump().c_str();
        }
    }

    {
        json::BaseRequest* p = new json::Point();
        dynamic_cast<json::Point*>(p)->setX(1);
        dynamic_cast<json::Point*>(p)->setY(1);
        nlohmann::json j = *dynamic_cast<json::Point*>(p);
        qDebug() << "p: " << j.dump().c_str();
        qDebug() << "p: " << dynamic_cast<json::Point*>(p)->getChunk().dump().c_str();
        delete p;
    }
    {
        json::BaseRequest* p = new json::Person();
        dynamic_cast<json::Person*>(p)->setAge(17);
        dynamic_cast<json::Person*>(p)->setName("xoce");
        nlohmann::json j = *dynamic_cast<json::Person*>(p);
        qDebug() << "p2: " << j.dump().c_str();
        qDebug() << "p2: " << dynamic_cast<json::Person*>(p)->getChunk().dump().c_str();
        delete p;
    }

    return a.exec();
}
