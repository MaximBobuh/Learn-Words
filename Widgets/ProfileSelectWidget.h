#ifndef PROFILESELECTWIDGET_H
#define PROFILESELECTWIDGET_H

#include <QListWidget>
#include <QPushButton>
#include <QDir>

class ProfileSelectWidget : public QWidget
{
    Q_OBJECT

private:
    void createWidget();
    void loadProfiles();
    void createItem(const QString&);  // Create QListWidgetItem and add to the QListWidget.

public:
    ProfileSelectWidget(QWidget* par = 0);

public slots:
    void slotCreateProfile();
    void slotSelectProfile();
    void slotDeleteProfile();
    void slotChangeCurrItem();

signals:
    void signalSelectProfile(QString);

private:
    QListWidget profiles;
    QPushButton butSelect;
    QPushButton butDelete;
    QDir dir;
};

#endif // PROFILESELECTWIDGET_H
