#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include "mysql.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QMySql mysql;
    mysql.connect_mysql();

    return a.exec();
}
