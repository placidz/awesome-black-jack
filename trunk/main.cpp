#include <QtCore/QCoreApplication>
#include "bjapplication.h"
#include <time.h>

int main(int argc, char *argv[])
{
    BJackApplication a(argc, argv);
	qsrand(time(NULL));
    return a.exec();
}

