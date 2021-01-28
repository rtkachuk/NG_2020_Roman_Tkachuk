#include <QCoreApplication>
#include "secretsmanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SecretsManager *secManager = new SecretsManager("Servak", "test.sqlite");
    if (secManager->openConnection())
    {
        secManager->addUser("TESTER1", "123");
        secManager->checkPassword("TETTTTT", "!@#");
        secManager->checkPassword("TESTER", "EEEEE");
        secManager->checkPassword("TESTER", "123");
        secManager->closeConnection();
    }

    return 0;
}
