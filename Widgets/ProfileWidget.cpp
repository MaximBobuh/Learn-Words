#include "ProfileWidget.h"
#include "AdditionalFunctions.h"

#include <QPushButton>
#include <QBoxLayout>


ProfileWidget::ProfileWidget()
{
    createWidget();
}

//-----------------------------

void ProfileWidget::createWidget()
{
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::lightGray);
    setAutoFillBackground(true);
    setPalette(pal);

    //-----------------------

    QPushButton* myDict   = AdditionalFunctions::createPWButton("Мой словарь", this);
    QPushButton* commDict = AdditionalFunctions::createPWButton("Общий словарь", this);
    QPushButton* training = AdditionalFunctions::createPWButton("Тренировки", this);
    QPushButton* selectProf = AdditionalFunctions::createPWButton("Выбор профиля", this);

    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->addWidget(myDict);
    vbox->addWidget(commDict);
    vbox->addWidget(training);
    vbox->addWidget(selectProf);

    setLayout(vbox);
    setFixedSize(350, 350);
}

