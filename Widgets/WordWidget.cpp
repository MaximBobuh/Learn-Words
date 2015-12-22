#include "WordWidget.h"
#include "WordData.h"

#include <QBoxLayout>
#include <QPushButton>

WordWidget::WordWidget(const WordData& data, QWidget *par) : QWidget(par)
{    
    createWidget();
    setWord(data);
}

//--------------------------------------------------------------

void WordWidget::createWidget()
{
    QPushButton* delBut = new QPushButton(this);
    delBut->setStyleSheet("border-image: url(:/delete.png); border-width: 1px; ");

    connect(delBut, SIGNAL(clicked(bool)), SIGNAL(signalDelete()));
    connect(&check, SIGNAL(clicked(bool)), SIGNAL(signalChangeCheck()));

    QHBoxLayout* hbox = new QHBoxLayout(this);
    hbox->addWidget(&check);
    hbox->addWidget(&textValue);
    hbox->addWidget(delBut);

    setLayout(hbox);
    setFixedHeight(45);
    setMinimumWidth(650);

    textValue.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

//--------------------------------------------------------------

void WordWidget::setWord(const WordData& word)
{
    QString text = word.original + (word.transcription.isEmpty() ? "" : " [" + word.transcription + "] ")
            + " - " + word.translation;
    textValue.setText("<p><font size=\"5\" color=\"midnightblue\" face=\"Arial\">  " + text + "</font> </p>");
}
