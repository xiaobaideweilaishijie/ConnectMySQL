#include "qmysql.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>

QMySql::QMySql()
{

}

void QMySql::connect_mysql()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "192.168.0.111_3306");
    db.setHostName("192.168.0.111");    //数据库的主机IP地址
    db.setPort(3306);   //数据库的端口号
    db.setDatabaseName("mysql");    //连接的数据库名
    db.setUserName("root");;    //连接数据库的用户登录名
    db.setPassword("123456");   //连接数据库的用户登录密码
    if (!db.open())
    {
        qDebug()<<"不能打开"<<"connect to mysql error"<<db.lastError().text();
        return;
    }
    else
    {
        qDebug()<<"打开成功"<<"connect to mysql OK\n\n";
    }
    QSqlQuery query(db);
    query.exec("select host,user,plugin from user;");
    while (query.next())
    {
        qDebug()<<query.value("host").toString()<<query.value("user").toString()<<query.value("plugin").toString();
    }
}
