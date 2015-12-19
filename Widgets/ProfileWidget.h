#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QWidget>

class ProfileWidget : public QWidget
{
    Q_OBJECT

public:
    ProfileWidget();

public slots:
    void slotMyDictionary();
    void slotWholeDictionary();
    void slotTraining();

signals:
    void signalBack();

private:
    void createWidget();
};

#endif // PROFILEWIDGET_H

