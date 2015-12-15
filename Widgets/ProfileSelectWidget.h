#ifndef PROFILESELECTWIDGET_H
#define PROFILESELECTWIDGET_H

#include <QListWidget>
#include <QPushButton>

class ProfileSelectWidget : public QWidget
{
    Q_OBJECT

private:
    void createWidget();
    void checkExistProfile();
    void loadProfiles();

public:
    ProfileSelectWidget(QWidget* par = 0);

public slots:
    void slotAddProfile();
    void slotSelectProfile();
    void slotDeleteProfile();

private:
    QListWidget profiles;
    QPushButton butSelect;
    QPushButton butDelete;
};

#endif // PROFILESELECTWIDGET_H
