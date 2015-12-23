#ifndef DICTIONARYMODEL_H
#define DICTIONARYMODEL_H

#include <set>
#include <memory>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

#include "WordData.h"
#include <QDebug>

//-------------------------------------

template<typename Container = std::set<WordData>>
class DictionaryModel
{
public:
    DictionaryModel(const QString& fileName = "", bool MyDict = false );

    bool loadFromFile(const QString&, bool);
    void saveToFile(const QString&) const;

    int find(const QString&) const;

private:
    Container data;
};

//-------------------------------------

class SimpleReader
{
public:
    virtual void read(const QStringList& in, WordData& word)
    {
        auto pos = in.begin();
        word.original      = *(pos++);
        word.transcription = *(pos++);
        word.translation   = *(pos++);
    }
protected:
    QStringList::iterator pos;
};

class FullReader : public SimpleReader
{
public:
    void read(const QStringList& in, WordData& word)
    {
        SimpleReader::read(in, word);    // "Common dictionary" contains only 3 members.
        word.date  = (pos++)->toInt();   // "My Dictionary" besides contains a date and level of the User.
        word.level = (pos)->toInt();
    }
};

inline SimpleReader* createReader(bool full)
{
    return (full ? new FullReader : new SimpleReader);
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
        return false;


    WordData word;
    QTextStream text(&file);

    std::shared_ptr<SimpleReader> reader(createReader(full));

    while(!text.atEnd())
    {
        QStringList list = text.readLine().split(QRegularExpression("\\s+"));
        reader.get()->read(list, word);
        data.insert(word);
    }
    return true;
}

//--------------------------------------------------------------------

template<typename Container>
void DictionaryModel<Container>::saveToFile(const QString& fileName) const
{
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

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

#endif // DICTIONARYMODEL_H
