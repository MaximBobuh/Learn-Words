#ifndef WORDDATA
#define WORDDATA

#include <QString>

struct WordData
{
    WordData(const QString& orig = "", const QString& trsl = "", const QString& trsc = "",
             int d = 0, int l = 0) : original(orig), translation(trsl), transcription(trsc),
                                     date(d), level(l) {}

    bool operator <(const WordData& other)  const { return original < other.original; }
    bool operator ==(const WordData& other) const { return original == other.original; }

    //-------------------

    QString original;
    QString translation;
    QString transcription;

    int date;
    int level;
};

#endif // WORDDATA
