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
    QPushButton* selectProf = AdditionalFunctions::createPWButton("Смена профиля", this);

    connect(myDict,     SIGNAL(clicked(bool)), SLOT(slotMyDictionary()));
    connect(commDict,   SIGNAL(clicked(bool)), SLOT(slotWholeDictionary()));
    connect(training,   SIGNAL(clicked(bool)), SLOT(slotTraining()));
    connect(selectProf, SIGNAL(clicked(bool)), SIGNAL(signalBack()));

    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->addWidget(myDict);
    vbox->addWidget(commDict);
    vbox->addWidget(training);
    vbox->addWidget(selectProf);

    setLayout(vbox);
    setFixedSize(350, 350);
}

//-----------------------------

void ProfileWidget::slotMyDictionary()
{

}

void ProfileWidget::slotWholeDictionary()
{

}

void ProfileWidget::slotTraining()
{

}

