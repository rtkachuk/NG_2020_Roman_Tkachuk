#include "secretsmanager.h"

SecretsManager::SecretsManager()
{
    init();
}

SecretsManager::SecretsManager(QString hostName, QString databaseName)
{
    init();
    setHostName(hostName);
    setDatabaseName(databaseName);
}

bool SecretsManager::openConnection()
{
    if (m_database.open()) {
        qDebug() << "Opened database at " << m_database.hostName();
        bool ok = createNewDatabase();
        if (!ok) {
            qDebug() << "Error creating database! OPENED EMPTY FILE";
        }
        return true;
    } else {
        qDebug() << m_database.lastError().databaseText();
        return false;
    }
}

void SecretsManager::closeConnection()
{
    m_database.close();
}

bool SecretsManager::addUser(QString name, QString password)
{
    if (checkUserExist(name) != 0) {
        return false;
    }
    QString queryString = QString("INSERT INTO users(login, password) VALUES ('%1', '%2');")
            .arg(name)
            .arg(password);
    if (!execSql(queryString)) {
        qDebug() << "ERROR Creating user!";
        return false;
    }
    return true;
}

int SecretsManager::checkPassword(QString name, QString password)
{
    QSqlQuery query;
    QString queryString = "SELECT password FROM users WHERE login='" + name + "';";
    bool ok = query.exec(queryString);
    if (!ok) {
        qDebug() << "ERROR executting query: " << query.lastError().databaseText();
        return 1;
    }

    ok = query.next();

    if (!ok) {
        qDebug() << "ERROR: no such user!";
        return 2;
    }

    QString passwordFromDatabase = query.value("password").toString();

    if (password != passwordFromDatabase) {
        qDebug() << "ERROR: Wrong password!";
        return 3;
    }

    qDebug() << "USER " << name << " PASSWORD CHECK: OK!";
    return 0;
}

void SecretsManager::init()
{
    m_database = QSqlDatabase::addDatabase("QSQLITE");
}

bool SecretsManager::createNewDatabase()
{
    QString queryString = "CREATE TABLE IF NOT EXISTS users (login TEXT, password TEXT);";
    if (!execSql(queryString)) {
        qDebug() << "ERROR: Can't create init table!";
        return false;
    }
    return true;
}

bool SecretsManager::execSql(QString queryString)
{
    QSqlQuery query;
    bool ok = query.exec(queryString);
    if (!ok) {
        qDebug() << "Database error occured: " << query.lastError().databaseText();
    }
    return ok;
}

int SecretsManager::checkUserExist(QString name)
{
    QSqlQuery query;
    QString queryString = "SELECT password FROM users WHERE login='" + name + "';";
    bool ok = query.exec(queryString);
    if (!ok) {
        qDebug() << "ERROR checking user exist: " << query.lastError().databaseText();
        return 1;
    }

    if (query.next()) {
        qDebug() << "ERROR: User " + name + " already exists!";
        return 2;
    }

    qDebug() << "Username " + name + " is available!";
    return 0;
}

