#include "button.h"
#include "calculator.h"
#include <math.h>
#include <QGridLayout>



Calculator::Calculator(QWidget *parent)
    : QDialog(parent)
{

    m_display = new QLineEdit("0");
    m_display->setReadOnly(true);
    m_display->setAlignment(Qt::AlignRight);
    m_display->setMaxLength(15);
    m_display->setFixedHeight(50);
    setStyleSheet("Calculator{background-color:black}");
    setFixedSize(260,350);
    setWindowTitle(tr("Calculator"));

    QGridLayout *topLayout = new QGridLayout;

    topLayout->addWidget(m_display, 0, 0, 2, 4);
    Button *pointButton = createButton(tr("."),"white", SLOT(pointClicked()));
    topLayout->addWidget(pointButton,2,2);

    setLayout(topLayout);
}


Button *Calculator::createButton(const QString &text, QString color, const char *func_answer)
{
    Button *button = new Button(text, color);
    connect(button, SIGNAL(clicked()), this, SLOT(func_answer));
    return button;
}

void Calculator::pointClicked()
{

}
