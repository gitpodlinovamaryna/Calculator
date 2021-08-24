#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>
#include <QLineEdit>
#include "button.h"
#include <QIcon>
#include <qapplication.h>
#include <QLabel>

 class Button;

 class Calculator : public QDialog
 {
     Q_OBJECT

 private:
      QLabel *m_display;
      QString m_operator;
      bool    m_checkOperand;
      double  m_leftOperand;
      double  m_rightOperand;
      double  m_result;
      bool  m_check_memory;
      bool m_sign;

 public:
     Calculator(QWidget *parent = 0);


 signals:
     void UpdateDisplay();


private slots:
      void pointClicked();
      void backspaceClicked();
      void plusClicked();
      void minusClicked();
      void divisionClicked();
      void multiplyClicked();
      void equalClicked();
      void clean();
      void percentClicked();
      void changeSignClicked();
      void digitClicked();


private:
      Button *createButton(const QString &text, QString color);
      void calculate();

 };

 #endif
