#ifndef WORDWIDGET_H
#define WORDWIDGET_H

#include <QCheckBox>
#include <QLabel>

class WordData;

class WordWidget : public QWidget
{
    Q_OBJECT
    void createWidget();

public:
    WordWidget(const WordData&, QWidget* par = 0);

    void setWord(const WordData&);
    bool isCheck() const { return check.isChecked(); }

signals:
    void signalDelete();
    void signalChangeCheck();

private:
    QCheckBox check;
    QLabel textValue;
};

#endif // WORDWIDGET_H
