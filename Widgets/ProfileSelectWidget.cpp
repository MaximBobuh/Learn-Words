#include "ProfileSelectWidget.h"
#include <QBoxLayout>
#include <QLabel>
#include <QDir>
#include <QApplication>

#include <QDebug>



ProfileSelectWidget::ProfileSelectWidget(QWidget *par) : QWidget(par), butSelect("Выбрать"), butDelete("Удалить")
{
    createWidget();
    loadProfiles();
}

//--------------------------------

void ProfileSelectWidget::createWidget()
{
    QLabel* lbl = new QLabel(this);
    lbl->setText("Профили:");

    //--------------------------

    QPalette pal;
    pal.setColor(QPalette::Background, Qt::lightGray);
    setAutoFillBackground(true);
    setPalette(pal);

    //-----------------------------

    QPushButton* butCreate = new QPushButton(this);
    butCreate->setText("Создать");

    connect(butCreate, SIGNAL(clicked(bool)), SLOT(slotAddProfile()));
    connect(&butSelect, SIGNAL(clicked(bool)), SLOT(slotAddProfile()));
    connect(&butDelete, SIGNAL(clicked(bool)), SLOT(slotDeleteProfile()));

    QHBoxLayout* hbox = new QHBoxLayout;
    hbox->addWidget(butCreate);
    hbox->addWidget(&butSelect);
    hbox->addWidget(&butDelete);

    //----------------------------

    QVBoxLayout* vbox = new QVBoxLayout;
    vbox->addWidget(lbl);
    vbox->addWidget(&profiles);
    vbox->addLayout(hbox);

    setLayout(vbox);
    setFixedSize(350, 350);
}

//-------------------------------------------

void ProfileSelectWidget::slotAddProfile()
{

}

void ProfileSelectWidget::slotSelectProfile()
{

}

void ProfileSelectWidget::slotDeleteProfile()
{

}

//-------------------------------------------

void ProfileSelectWidget::loadProfiles()
{
    QDir dir(QApplication::applicationDirPath());
    dir.mkdir("Profiles");
    dir.setPath(dir.absoluteFilePath("Profiles"));

    QStringList names = dir.entryList(QDir::Dirs); qDebug() << names;

    for(auto name : names)
    {
        if(name == "." || name == "..")
            continue;

        QListWidgetItem* item = new QListWidgetItem(name, &profiles);
        profiles.addItem(item);
    }

    checkExistProfile();
}

//-------------------------------------------

void ProfileSelectWidget::checkExistProfile()
{
    bool en = profiles.count();
    butDelete.setEnabled(en);
    butSelect.setEnabled(en);
}
