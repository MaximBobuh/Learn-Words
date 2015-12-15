#include "ProfileSelectWidget.h"

#include <QBoxLayout>
#include <QLabel>
#include <QApplication>
#include <QMessageBox>
#include <QInputDialog>

#include <QDebug>



ProfileSelectWidget::ProfileSelectWidget(QWidget *par) : QWidget(par), butSelect("Выбрать"), butDelete("Удалить")
{
    createWidget();
    loadProfiles();
}

//--------------------------------

void ProfileSelectWidget::createWidget()
{
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::lightGray);
    setAutoFillBackground(true);
    setPalette(pal);

    //-------------------

    QLabel* lbl = new QLabel(this);
    lbl->setText("Профили:");

    QPushButton* butCreate = new QPushButton(this);
    butCreate->setText("Создать");

    connect(butCreate,  SIGNAL(clicked(bool)), SLOT(slotCreateProfile()));
    connect(&butSelect, SIGNAL(clicked(bool)), SLOT(slotSelectProfile()));
    connect(&butDelete, SIGNAL(clicked(bool)), SLOT(slotDeleteProfile()));
    connect(&profiles,  SIGNAL(doubleClicked(QModelIndex)), SLOT(slotSelectProfile()));
    connect(&profiles,  SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), SLOT(slotChangeCurrItem()));

    QHBoxLayout* hbox = new QHBoxLayout;
    hbox->addWidget(butCreate);
    hbox->addWidget(&butSelect);
    hbox->addWidget(&butDelete);

    //--------------------

    QVBoxLayout* vbox = new QVBoxLayout;
    vbox->addWidget(lbl);
    vbox->addWidget(&profiles);
    vbox->addLayout(hbox);

    setLayout(vbox);
    setFixedSize(350, 350);

    slotChangeCurrItem();
}

//-------------------------------------------

void ProfileSelectWidget::loadProfiles()
{
    dir.setPath(QApplication::applicationDirPath());
    dir.mkdir("Profiles");
    dir.setPath(dir.absoluteFilePath("Profiles"));

    QStringList names = dir.entryList(QDir::Dirs);

    for(auto name : names)
    {
        if(name == "." || name == "..")
            continue;

        createItem(name);
    }
}

//-------------------------------------------

void ProfileSelectWidget::createItem(const QString& name)
{
    QListWidgetItem* item = new QListWidgetItem(name, &profiles);
    profiles.addItem(item);
}

//-------------------------------------------

void ProfileSelectWidget::slotChangeCurrItem()
{
    bool en = (profiles.currentItem() != 0);
    butDelete.setEnabled(en);
    butSelect.setEnabled(en);
}

//-------------------------------------------

void ProfileSelectWidget::slotCreateProfile()
{
    bool ok;
    QString text = QInputDialog::getText(this, QString::fromUtf8("Новый профиль"), QString::fromUtf8("Введите имя вашего профиля:"),
                                          QLineEdit::Normal, QDir::home().dirName(), &ok);
    if(ok && !text.isEmpty())
    {
        if(!dir.mkdir(text))
        {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::information(this, QString::fromUtf8("Предупреждение"),
                                   QString::fromUtf8("Профиль с таким именем уже существует!"));
            return;
        }
        createItem(text);
    }
}

//-------------------------------------------

void ProfileSelectWidget::slotSelectProfile()
{qDebug() << profiles.currentItem()->text();
    emit signalSelectProfile(profiles.currentItem()->text());
}

//-------------------------------------------

void ProfileSelectWidget::slotDeleteProfile()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, QString::fromUtf8("Удаление профиля"),
                          QString::fromUtf8("Вы действительно хотите удалить профиль?"),
                          QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        QListWidgetItem* item = profiles.takeItem(profiles.currentRow());
        dir.rmdir(item->text());

        delete item;
    }
}

//-------------------------------------------
