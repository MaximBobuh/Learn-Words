#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QWidget>

class ProfileWidget : public QWidget
{
    Q_OBJECT

public:
    ProfileWidget();

signals:
    void signalMyDictionary();
    void signalWholeDictionary();
    void signalTraining();

private:
    void createWidget();
};

#endif // PROFILEWIDGET_H

