#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

private:
    QString m_display;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    void UpdateDisplay(QString);

public slots:
    void buttonPressed();
    void reset();
};
#endif // WIDGET_H



/*#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace
Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digits_numbers();
    void on_pushButton_dot_clicked();
    void operations();
    void on_pushButton_clean_clicked();
    void on_pushButton_equal_clicked();
    void math_operations();
};
#endif // MAINWINDOW_H*/
