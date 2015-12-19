#ifndef ADDITIONALFUNCTIONS
#define ADDITIONALFUNCTIONS

#include <QPushButton>

namespace AdditionalFunctions
{

// Create QPushButton for the ProfileWidget.
QPushButton* createPWButton(const QString& text,QWidget* par = 0)
{
    QPushButton* but = new QPushButton(text, par);
    but->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but->setStyleSheet("QPushButton {"
                           "font-size: 16pt;"
                           "font-weight: bold;"
                           "background-color: #E6E6FA;"
                           "border-radius: 7; "
                           "color: darkslategray;"
                       "}"
                       "QPushButton::hover { "
                           "background-color: darkgray;"
                       "}"
                       "QPushButton::pressed { "
                           "background-color: dimgray;"
                       "}");
    return but;
}

}

#endif // ADDITIONALFUNCTIONS

