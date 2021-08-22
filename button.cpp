#include "button.h"

Button::Button(const QString &text, QString color, QWidget *parent)
       : QPushButton(parent)
{
    setText(text);
    QFont btn_font("SansSerif", 14, QFont::Bold);
    setFont(btn_font);
    setStyleSheet(color);
    setMinimumHeight(60);
    setMinimumWidth(60);
}
//this->setStyleSheet("MainWindow{background-color:black}");
