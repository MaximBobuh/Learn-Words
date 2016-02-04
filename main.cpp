#include "ProfileSelectWidget.h"
#include "DictionaryView.h"
#include "DictionaryModel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //ProfileSelectWidget wdg;

    BaseModel* model = createModel(1);
    model->loadFromFile("C:/Users/MBobukh/Desktop/file.txt", false);

    DictionaryView wdg;
    wdg.setModel(model);
    wdg.show();

    return a.exec();
}

