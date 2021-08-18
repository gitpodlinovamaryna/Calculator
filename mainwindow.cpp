#include "mainwindow.h"
#include "ui_mainwindow.h"


double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_plus_minus,SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_percent,SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_mult,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_div,SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
    ui->pushButton_div->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();
    double full_number;
    QString full_number_to_string;

    if(ui->result_show->text().contains(".") && button->text() == "0")
    {
        full_number_to_string = ui->result_show->text() + button->text();
    }
    else
    {
        full_number = (ui->result_show->text()+button->text()).toDouble();
        full_number_to_string = QString::number(full_number, 'g', 12);
    }

    ui->result_show->setText(full_number_to_string);
}


void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result_show->text().contains(".")))
        ui->result_show->setText(ui->result_show->text() + ".");
}


void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();
    double full_number;
    QString full_number_to_string;

    if(button->text() == "+/-")
    {
    full_number = (ui->result_show->text()).toDouble();
    full_number = full_number * -1;
    full_number_to_string = QString::number(full_number, 'g', 12);

    ui->result_show->setText(full_number_to_string);
    }

    else if(button->text() == "%")
    {
    full_number = (ui->result_show->text()).toDouble();
    full_number = full_number * 0.01;
    full_number_to_string = QString::number(full_number, 'g', 12);

    ui->result_show->setText(full_number_to_string);
    }
}

void MainWindow::on_pushButton_clean_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_div->setChecked(false);

    ui->result_show->setText("0");
}


void MainWindow::on_pushButton_equal_clicked()
{
    double result_number, num_second;
    QString result_label;

    num_second = ui->result_show->text().toDouble();

    if(ui->pushButton_plus->isChecked())
    {
        result_number = num_first + num_second;
        result_label = QString::number(result_number, 'g', 12);

        ui->result_show->setText(result_label);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked())
    {
        result_number = num_first - num_second;
        result_label = QString::number(result_number, 'g', 12);

        ui->result_show->setText(result_label);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_mult->isChecked())
    {
        result_number = num_first * num_second;
        result_label = QString::number(result_number, 'g', 12);

        ui->result_show->setText(result_label);
        ui->pushButton_mult->setChecked(false);
    }
    else if(ui->pushButton_div->isChecked())
    {
        if(num_second == 0)
        {
            ui->result_show->setText("0");
        }
        else
        {
        result_number = num_first / num_second;
        result_label = QString::number(result_number, 'g', 12);

        ui->result_show->setText(result_label);
        }
        ui->pushButton_div->setChecked(false);
    }
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();
    num_first = ui->result_show->text().toDouble();

    ui->result_show->setText("");
    button->setChecked(true);
}

