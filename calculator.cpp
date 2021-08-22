#include "button.h"
#include "calculator.h"
#include <math.h>
#include <QGridLayout>



Calculator::Calculator(QWidget *parent)
    : QDialog(parent)
{

    QFont displayFont("Times", 16, QFont::Bold);
    m_display = new QLineEdit("0");
    m_display->setReadOnly(true);
    m_display->setAlignment(Qt::AlignRight);
    m_display->setMaxLength(15);
    m_display->setFixedHeight(60);
    m_display->setFont(displayFont);

    QString btn_orange = "QPushButton{background:#FF6600;}";
    QString btn_white = "QPushButton{background:#FFFFFF;}";
    QString btn_red = "QPushButton{background:#CC0000;}";
    QString btn_gray = "QPushButton{background:#B1CECE;}";

    setStyleSheet("Calculator{background-color:#02020D}");
    setFixedSize(260,300);
    setWindowTitle(tr("Calculator"));

    QGridLayout *topLayout = new QGridLayout;
    topLayout->setSpacing(2);
    topLayout->setVerticalSpacing(0);
    topLayout->addWidget(m_display, 0, 0, 1, 5);

    Button *plusButton = createButton("+",btn_orange, SLOT(plusClicked()));
    Button *minusButton = createButton("-",btn_orange, SLOT(minusClicked()));
    Button *divisionButton = createButton("/",btn_orange, SLOT(divisionClicked()));
    Button *multiplyButton = createButton("*",btn_orange, SLOT(multiplyClicked()));
    Button *equalButton = createButton("=",btn_orange, SLOT(equalClicked()));
    Button *pointButton = createButton(".",btn_white, SLOT(pointClicked()));
    Button *backspaceButton = createButton("<-",btn_gray , SLOT(backspaceClicked()));
    Button *cleanButton = createButton("CE",btn_red, SLOT(clean()));
    Button *percentButton = createButton("%",btn_gray, SLOT(percentClicked()));
    Button *changeSignButton = createButton("+/-",btn_white, SLOT(changeSignClicked()));
    Button *digitButton_0 = createButton("0",btn_white, SLOT(Clicked()));


    topLayout->addWidget(plusButton, 4, 4);
    topLayout->addWidget(minusButton, 3, 4);
    topLayout->addWidget(divisionButton, 1, 4);
    topLayout->addWidget(multiplyButton, 2, 4);
    topLayout->addWidget(equalButton, 5, 4);
    topLayout->addWidget(pointButton, 5, 3);
    topLayout->addWidget(backspaceButton, 1, 3);
    topLayout->addWidget(cleanButton, 1, 1);
    topLayout->addWidget(percentButton, 1, 2);
    topLayout->addWidget(changeSignButton, 5, 1);
    topLayout->addWidget(digitButton_0, 5, 2);
    setLayout(topLayout);
}


Button *Calculator::createButton(const QString &text, QString color, const char *func_answer)
{
    Button *button = new Button(text, color);
    connect(button, SIGNAL(clicked()), this, SLOT(func_answer));
    return button;
}

void Calculator::plusClicked()
{

}

void Calculator::minusClicked()
{

}

void Calculator::divisionClicked()
{

}

void Calculator::multiplyClicked()
{

}

void Calculator::equalClicked()
{

}

void Calculator::pointClicked()
{

}

void Calculator::percentClicked()
{

}

void Calculator::changeSignClicked()
{

}
void Calculator::backspaceClicked()
{

}

void Calculator::clean()
{

}
