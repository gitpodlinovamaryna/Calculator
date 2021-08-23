#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>
#include <QLineEdit>
#include "button.h"
#include <QIcon>
#include <qapplication.h>

 class Button;

 class Calculator : public QDialog
 {
     Q_OBJECT

 private:
      QLineEdit *m_display;
      QString m_displayText;
      bool m_check_operand;


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
      //void setText(QString);
      void setText();

private:
      Button *createButton(const QString &text, QString color);

 };

 #endif
