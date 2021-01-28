#ifndef SECRETSMANAGER_H
#define SECRETSMANAGER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QDebug>

class SecretsManager
{
public:
    SecretsManager();
    SecretsManager(QString hostName, QString databaseName);

    void setHostName(QString hostName) { m_database.setHostName(hostName); }
    void setDatabaseName(QString databaseName) { m_database.setDatabaseName(databaseName); }

    bool openConnection();
    void closeConnection();

    bool addUser(QString name, QString password);
    int checkPassword(QString name, QString password);

private:
    void init();
    bool createNewDatabase();
    bool execSql(QString queryString);
    int checkUserExist(QString name);

    QSqlDatabase m_database;
};

#endif // SECRETSMANAGER_H
