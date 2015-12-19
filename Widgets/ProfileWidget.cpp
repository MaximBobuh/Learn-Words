#include "ProfileWidget.h"

#include <QPushButton>
#include <QBoxLayout>


ProfileWidget::ProfileWidget()
{
    createWidget();
}

//-----------------------------

void ProfileWidget::createWidget()
{
    QPushButton* myDict = new QPushButton("Мой словарь", this);
    QPushButton* commDict = new QPushButton("Общий словарь", this);
    QPushButton* training = new QPushButton("Тренировки", this);

    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->addWidget(myDict);
    vbox->addWidget(commDict);
    vbox->addWidget(training);

    setLayout(vbox);
    setFixedSize(350, 350);
}

