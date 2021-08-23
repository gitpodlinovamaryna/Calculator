#include "button.h"
#include "calculator.h"
#include <math.h>
#include <QGridLayout>
#include <QDebug>



Calculator::Calculator(QWidget *parent)
    : QDialog(parent)
{

    QFont displayFont("Times", 16, QFont::Bold);
    QString btn_orange = "QPushButton{background:#FF6600;}";
    QString btn_white = "QPushButton{background:#FFFFFF;}";
    QString btn_red = "QPushButton{background:#CC0000;}";
    QString btn_gray = "QPushButton{background:#B1CECE;}";

    setStyleSheet("Calculator{background-color:#02020D}");
    setFixedSize(260,300);
    setWindowTitle(tr("Calculator"));

    m_display = new QLineEdit("0");
    m_display->setReadOnly(true);
    m_display->setAlignment(Qt::AlignRight);
    m_display->setFixedHeight(60);
    m_display->setMaxLength(15);
    m_display->setFont(displayFont);
    m_check_operand = true;

    Button *plusButton = createButton("+",btn_orange);
    Button *minusButton = createButton("-",btn_orange);
    Button *divisionButton = createButton("/",btn_orange);
    Button *multiplyButton = createButton("*",btn_orange);
    Button *equalButton = createButton("=",btn_orange);
    Button *pointButton = createButton(".",btn_white);
    Button *backspaceButton = createButton("<-",btn_gray);
    Button *cleanButton = createButton("CE",btn_red);
    Button *percentButton = createButton("%",btn_gray);
    Button *changeSignButton = createButton("+/-",btn_white);
    Button *digitButton_0 = createButton("0",btn_white);
    Button *digitButton_1 = createButton("1",btn_white);
    Button *digitButton_2 = createButton("2",btn_white);
    Button *digitButton_3 = createButton("3",btn_white);
    Button *digitButton_4 = createButton("4",btn_white);
    Button *digitButton_5 = createButton("5",btn_white);
    Button *digitButton_6 = createButton("6",btn_white);
    Button *digitButton_7 = createButton("7",btn_white);
    Button *digitButton_8 = createButton("8",btn_white);
    Button *digitButton_9 = createButton("9",btn_white);


    connect(this, SIGNAL(UpdateDisplay()),this, SLOT(setText()));
    connect(plusButton, SIGNAL(clicked()), this, SLOT(plusClicked()));
    connect(minusButton, SIGNAL(clicked()), this, SLOT(minusClicked()));
    connect(divisionButton, SIGNAL(clicked()), this, SLOT(divisionClicked()));
    connect(multiplyButton, SIGNAL(clicked()), this, SLOT(multiplyClicked()));
    connect(equalButton, SIGNAL(clicked()), this, SLOT(equalClicked()));
    connect(pointButton, SIGNAL(clicked()), this, SLOT(pointClicked()));
    connect(backspaceButton, SIGNAL(clicked()), this, SLOT(backspaceClicked()));
    connect(cleanButton, SIGNAL(clicked()), this, SLOT(clean()));
    connect(percentButton, SIGNAL(clicked()), this, SLOT(percentClicked()));
    connect(changeSignButton, SIGNAL(clicked()), this, SLOT(changeSignClicked()));
    connect(digitButton_0, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(digitButton_1, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(digitButton_2, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(digitButton_3, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(digitButton_4, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(digitButton_5, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(digitButton_6, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(digitButton_7, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(digitButton_8, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(digitButton_9, SIGNAL(clicked()), this, SLOT(digitClicked()));


    QGridLayout *topLayout = new QGridLayout;
    topLayout->setSpacing(2);
    topLayout->setVerticalSpacing(0);


    topLayout->addWidget(m_display, 0, 0, 1, 5);
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
    topLayout->addWidget(digitButton_1, 4, 1);
    topLayout->addWidget(digitButton_2, 4, 2);
    topLayout->addWidget(digitButton_3, 4, 3);
    topLayout->addWidget(digitButton_4, 3, 1);
    topLayout->addWidget(digitButton_5, 3, 2);
    topLayout->addWidget(digitButton_6, 3, 3);
    topLayout->addWidget(digitButton_7, 2, 1);
    topLayout->addWidget(digitButton_8, 2, 2);
    topLayout->addWidget(digitButton_9, 2, 3);

    setLayout(topLayout);
}


Button *Calculator::createButton(const QString &text, QString color)
{
    Button *button = new Button(text, color);
    return button;
}

void Calculator::setText()
{
    m_display->setText(m_displayText);
}

void Calculator::digitClicked()
{
    QString btn_value = ((QPushButton *)sender())->text();
    if (m_displayText == "0" && btn_value == "0.0")
        return;
    if (m_check_operand) {
             m_display->clear();
             m_check_operand = false;
         }
    m_displayText += btn_value;
    qDebug() << btn_value;
    setText();
    emit UpdateDisplay(); //посылает сигнал

}

void Calculator::plusClicked()
{
    double second_operand = m_display->text().toDouble();
}

void Calculator::minusClicked()
{
     double second_operand = m_display->text().toDouble();
}

void Calculator::divisionClicked()
{
     double second_operand = m_display->text().toDouble();
}

void Calculator::multiplyClicked()
{
     double second_operand = m_display->text().toDouble();
}

void Calculator::equalClicked()
{

}

void Calculator::pointClicked()
{

}

void Calculator::percentClicked()
{
    if (m_displayText == "0")
        return;
    double result = (m_displayText.toDouble()) / 100;
    m_displayText = QString::number(result);
    setText();
    emit UpdateDisplay();
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
