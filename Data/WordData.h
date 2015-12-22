#ifndef WORDDATA
#define WORDDATA

#include <QString>

struct WordData
{
    WordData(const QString& orig = "", const QString& trsl = "", const QString& trsc = "") :
        original(orig), translation(trsl), transcription(trsc) {}

    //-------------------

    QString original;
    QString translation;
    QString transcription;
};

#endif // WORDDATA

