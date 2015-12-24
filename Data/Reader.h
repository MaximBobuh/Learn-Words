#ifndef READER
#define READER

#include <QStringList>
#include "WordData.h"


// A Reader allows to convert a QStringList to WordData.
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
    virtual ~SimpleReader(){}

protected:
    QStringList::iterator pos;
};

//--------------------------------------------------

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

//--------------------------------------------------

inline SimpleReader* createReader(bool full)
{
    return (full ? new FullReader : new SimpleReader);
}

#endif // READER

