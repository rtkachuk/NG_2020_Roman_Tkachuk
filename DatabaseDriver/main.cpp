#include <QCoreApplication>
#include "secretsmanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    bool debugMode = false;

    for (int currentArgument = 0; currentArgument < argc; currentArgument++) {
        if (argv[currentArgument] == QString("--debug").toStdString())
            debugMode = true;
    }

    SecretsManager *secManager = new SecretsManager("Servak", "test.sqlite");
    secManager->setDebugMode(debugMode);
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
