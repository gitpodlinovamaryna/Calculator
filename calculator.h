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
      QLineEdit *m_display;

 public:
     Calculator(QWidget *parent = 0);

private slots:
      void pointClicked();
      void backspaceClicked();
      void plusClicked();
      void minusClicked();
      void divisionClicked();
      void multiplyClicked();
      void equalClicked();

private:
      Button *createButton(const QString &text, QString color, const char *func_answer);
 };

 #endif
