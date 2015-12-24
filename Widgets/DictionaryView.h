#ifndef DICTIONARYVIEW_H
#define DICTIONARYVIEW_H

#include <QWidget>
#include <vector>

#include "DictionaryModel.h"
#include "WordWidget.h"

class DictionaryView : public QWidget
{
    Q_OBJECT

private:
    void createWidget();

public:
    DictionaryView(QWidget* par = 0);

    void setModel(BaseModel*);
    BaseModel* getModel() const { return model; }

protected:
    BaseModel* model;
    std::vector<WordWidget*> words;
};

#endif // DICTIONARYVIEW_H
