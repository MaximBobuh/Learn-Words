#ifndef DICTIONARYMODEL_H
#define DICTIONARYMODEL_H

#include <set>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

#include "WordData.h"
#include <QDebug>

//-------------------------------------

template<typename Container = std::set<WordData> >
class DictionaryModel
{
public:
    DictionaryModel(const QString& fileName = "");

    bool loadFromFile(const QString&);
    void saveToFile(const QString&) const;

    int find(const QString&) const;

private:
    Container data;
};


//--------------------------------------------------------------------
// Implementation.
//--------------------------------------------------------------------

template<typename Container>
DictionaryModel<Container>::DictionaryModel(const QString& fileName)
{
    if(!fileName.isEmpty())
        loadFromFile(fileName);
}

//--------------------------------------------------------------------

template<typename Container>
bool DictionaryModel<Container>::loadFromFile(const QString& fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    WordData word;
    QTextStream text(&file);
    while(!text.atEnd())
    {
        QStringList list = text.readLine().split(QRegularExpression("\\s+"));
        auto pos = list.begin();

        word.original      = *(pos++);
        word.transcription = *(pos++);
        word.translation   = *(pos++);

        if(list.size() == 5)
        {
            word.date  = (pos++)->toInt();
            word.level = (pos)->toInt();
        }
        data.insert(word);
    }
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
