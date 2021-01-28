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

    void setDebugMode(bool mode) { m_debugMode = mode; }

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
    void log(QString message);

    QSqlDatabase m_database;
    bool m_debugMode = false;
};

#endif // SECRETSMANAGER_H
