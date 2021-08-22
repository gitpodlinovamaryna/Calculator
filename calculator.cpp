#include "button.h"
#include "calculator.h"
#include <math.h>



Calculator::Calculator(QWidget *parent)
    : QDialog(parent)
{

    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);

    setWindowTitle(tr("Calculator"));

}


