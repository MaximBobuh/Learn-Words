#include "ProfileSelectWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ProfileSelectWidget wdg;
    wdg.show();

    return a.exec();
}
