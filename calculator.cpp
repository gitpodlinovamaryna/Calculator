#include "button.h"
#include "calculator.h"
#include <math.h>



Calculator::Calculator(QWidget *parent)
    : QDialog(parent)
{

    m_display = new QLineEdit("0");
    m_display->setReadOnly(true);
    m_display->setAlignment(Qt::AlignRight);
    m_display->setMaxLength(15);
    setStyleSheet("Calculator{background-color:black}");
    setFixedSize(260,350);
    setWindowTitle(tr("Calculator"));

}


Button *Calculator::createButton(const QString &text, QString color, const char *func_answer)
 {
     Button *button = new Button(text, color);
     connect(button, SIGNAL(clicked()), this,func_answer);
     return button;
 }
