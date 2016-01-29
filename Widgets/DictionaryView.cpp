#include "DictionaryView.h"
#include <QBoxLayout>

DictionaryView::DictionaryView(QWidget *par) : QWidget(par), model(0)
{
    createWidget();
}

//---------------------------------------------------------

void DictionaryView::createWidget()
{
}

//---------------------------------------------------------

void DictionaryView::setModel(BaseModel *mod)
{
    model = mod;

    for(int i = 0; i < words.size(); ++i)  // If "words" isn't empty then delete old WordWidgets.
        delete words[i];
    words.clear();


    int sizeModel = model->size();
    for(int i = 0; i < sizeModel; ++i)
    {
        const WordData& word = model->getCurrWord();   //qDebug() << word.original;
        words.push_back(new WordWidget(word, this));
    }

    QVBoxLayout* vBox = new QVBoxLayout;
    for(auto word : words)
        vBox->addWidget(word);

    vBox->setAlignment(Qt::AlignTop);
    setLayout(vBox);
}
