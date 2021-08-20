#include <QPushButton>
#include "mainwindow.h"

#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    /*QVBoxLayout * layout = new QVBoxLayout;
    QHBoxLayout * layout_hor = new QHBoxLayout;

    QPushButton * ButtonA = new QPushButton("A");
    QPushButton * ButtonB = new QPushButton("B");
    QPushButton * ButtonC = new QPushButton("C");
    QPushButton * ButtonD = new QPushButton("D");

    layout->setMargin(50);//расстояние от внешних границ виджета до кнопок
    layout->setSpacing(30);//расстояния между кнопками

    layout->addWidget(ButtonA);
    layout->addStretch(1);//растяжения расстояний между кнопками
    layout->addWidget(ButtonB, 2);// фактор растяжения
    layout->addWidget(ButtonC, 3);
    w.setLayout(layout);*/

    // Вложение одного layout в другой layout
    /*QVBoxLayout * layout = new QVBoxLayout;//внешний layout

    QPushButton * ButtonA = new QPushButton("A");
    QPushButton * ButtonB = new QPushButton("B");
    layout->addWidget(ButtonA, 0, Qt::AlignBottom);
    layout->addStretch(1);
    layout->addWidget(ButtonB, 0, Qt::AlignBottom);
    layout->addStretch(1);

    QHBoxLayout * layout_hor = new QHBoxLayout;//будущий вложенный layout

    QPushButton * ButtonC = new QPushButton("C");
    QPushButton * ButtonD = new QPushButton("D");

    layout_hor->addWidget(ButtonC, 1);
    layout_hor->addSpacing(20);
    layout_hor->addWidget(ButtonD, 1);
    layout->addLayout(layout_hor);// вложение внутреннего layout

    w.setLayout(layout);*/

    QGridLayout * layout = new QGridLayout;//внешний layout

    QPushButton * ButtonA = new QPushButton("A");
    QPushButton * ButtonB = new QPushButton("B");
    QPushButton * ButtonC = new QPushButton("C");
    QPushButton * ButtonD = new QPushButton("D");

    layout->addWidget(ButtonA, 0,0);//кнопка А в строка 0 столбец 0
    layout->addWidget(ButtonB, 0,1);//кнопка B в строка 0 столбец 1
    layout->addWidget(ButtonC, 2,3);//кнопка C в строка 2 столбец 3
    layout->addWidget(ButtonD, 1,2);//кнопка D в строка 1 столбец 2

    w.setLayout(layout);

    w.show();
    return a.exec();
}





/*#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}*/
