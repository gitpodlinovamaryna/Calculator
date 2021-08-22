#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>
#include <QLineEdit>
#include "button.h"
#include <QIcon>


 class Calculator : public QDialog
 {
     Q_OBJECT

 private:
      QLineEdit *display;

 public:
     Calculator(QWidget *parent = 0);

 };

 #endif
