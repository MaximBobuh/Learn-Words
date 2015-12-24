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
        const WordData& word = model->getCurrWord();qDebug() << word.original;
        WordWidget* tmp = new WordWidget(word);
        tmp->show();
    }
}
