#ifndef DICTIONARYMODEL_H
#define DICTIONARYMODEL_H

#include <set>
#include <list>
#include <memory>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

#include "WordData.h"
#include "Reader.h"
#include <QDebug>

//-------------------------------------

class BaseModel
{
public:
    virtual bool loadFromFile(const QString&, bool) = 0;
    virtual void saveToFile(const QString&) const = 0;
    virtual int find(const QString&) const = 0;
    virtual int size() const = 0;
    virtual const WordData& getCurrWord() = 0;
    virtual void resetCurrWord() = 0;

    virtual ~BaseModel(){}
};

//--------------------------------------------------------------

template<typename Container = std::set<WordData>>
class DictionaryModel : public BaseModel
{
public:
    DictionaryModel(const QString& fileName = "", bool MyDict = false );

    bool loadFromFile(const QString&, bool);
    void saveToFile(const QString&) const;

    int find(const QString&) const;
    int size() const { return data.size(); }
    void addWord(const WordData& word) { data.insert(word); }

    const WordData& getCurrWord() { return *(currWord++); }
    void resetCurrWord() { currWord = data.begin(); }


private:
    Container data;
    typename Container::iterator currWord;
};

//--------------------------------------------------------------

// Factory method.
inline BaseModel* createModel(int i)
{
    BaseModel* model = 0;
    if(i == 0)
        model = new DictionaryModel<std::list<WordData> >;
    else
        model = new DictionaryModel<>; // std::set<WordData> .
    return model;
}



//--------------------------------------------------------------------
// Implementation.
//--------------------------------------------------------------------

template<typename Container>
DictionaryModel<Container>::DictionaryModel(const QString& fileName, bool full)
{
    if(!fileName.isEmpty())
        loadFromFile(fileName, full);
}

//--------------------------------------------------------------------

template<typename Container>
bool DictionaryModel<Container>::loadFromFile(const QString& fileName, bool full)
{
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "can't open file";
        return false;
    }

    WordData word;
    QTextStream text(&file);

    std::shared_ptr<SimpleReader> reader(createReader(full));

    while(!text.atEnd())
    {
        QStringList list = text.readLine().split(QRegularExpression("\\s+"));
        if(list.begin()->isEmpty())
            continue;
        
        reader.get()->read(list, word);
        data.insert(data.begin(), word);
    }
    resetCurrWord();
    return true;
}

//--------------------------------------------------------------------

template<typename Container>
void DictionaryModel<Container>::saveToFile(const QString& fileName) const
{
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream text(&file);
    for(auto pos = data.begin(); pos != data.end(); ++pos)
    {
        text << pos->original << " " << pos->transcription << " " << pos->translation
             << " " << pos->date << " " << pos->level << "\n";
    }
    file.close();
}

//--------------------------------------------------------------------

template<typename Container>
int DictionaryModel<Container>::find(const QString& word) const
{
    auto pos = std::find(data.begin(), data.end(), word);
    return (pos == data.end() ? -1 : std::distance(data.begin(), pos));
}


//--------------------------------------------------------------------

#endif // DICTIONARYMODEL_H


//7319
//44688763
