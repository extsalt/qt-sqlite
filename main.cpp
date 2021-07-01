#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <iostream>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\Users\\sherlock\\database.db");

    if(!db.open()) {
        std::cout << "Failed to open database";
    }
    QSqlQuery q("", db);
    q.exec("create table Movies (id integer primary key, Title varchar, Director varchar, Rating number)");
    q.exec("insert into Movies values (0, 'Metropolis', 'Fritz Lang', '8.4')");
    q.exec("insert into Movies values (1, 'Nosferatu, eine Symphonie des Grauens', 'F.W. Murnau', '8.1')");
    q.exec("insert into Movies values (2, 'Bis ans Ende der Welt', 'Wim Wenders', '6.5')");
    q.exec("insert into Movies values (3, 'Hardware', 'Richard Stanley', '5.2')");
    q.exec("insert into Movies values (4, 'Mitchell', 'Andrew V. McLaglen', '2.1')");
    q.exec("create table Names (id integer primary key, Firstname varchar, Lastname varchar, City varchar)");
    q.exec("insert into Names values (0, 'Sala', 'Palmer', 'Morristown')");
    q.exec("insert into Names values (1, 'Christopher', 'Walker', 'Morristown')");
    q.exec("insert into Names values (2, 'Donald', 'Duck', 'Andeby')");
    q.exec("insert into Names values (3, 'Buck', 'Rogers', 'Paris')");
    q.exec("insert into Names values (4, 'Sherlock', 'Holmes', 'London')");
    return a.exec();
}
