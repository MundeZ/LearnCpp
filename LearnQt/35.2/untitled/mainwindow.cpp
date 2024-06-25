#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_button_1_clicked() {
    operand = operand * 10 + 1;
    updateLcdOperand();
}


void MainWindow::on_button_2_clicked() {
    operand = operand * 10 + 2;
    updateLcdOperand();
}


void MainWindow::on_button_3_clicked() {
    operand = operand * 10 + 3;
    updateLcdOperand();
}


void MainWindow::on_button_4_clicked() {
    operand = operand * 10 + 4;
    updateLcdOperand();
}


void MainWindow::on_button_5_clicked() {
    operand = operand * 10 + 5;
    updateLcdOperand();
}


void MainWindow::on_button_6_clicked() {
    operand = operand * 10 + 6;
    updateLcdOperand();
}


void MainWindow::on_button_7_clicked() {
    operand = operand * 10 + 7;
    updateLcdOperand();
}


void MainWindow::on_button_8_clicked() {
    operand = operand * 10 + 8;
    updateLcdOperand();
}


void MainWindow::on_button_9_clicked() {
    operand = operand * 10 + 9;
    updateLcdOperand();
}


void MainWindow::on_button_0_clicked() {
    operand = operand * 10;
    updateLcdOperand();
}

void MainWindow::on_button_c_clicked() {
    operand = 0;
    operation = "";
    updateLcdOperand();
}


void MainWindow::on_button_backspace_clicked() {
    operand = (int)operand / 10;
    updateLcdOperand();
}


void MainWindow::on_button_eq_clicked() {
    b = operand;
    if(operation == "+"){
        result = QString::number(a + b);
        updateLcdResult();
    }
    else if(operation == "-"){
        result = QString::number(a - b);
        updateLcdResult();
    }
    else if(operation == "*"){
        result = QString::number(a * b);
        updateLcdResult();
    }
    else if(operation == "/"){
        result = QString::number(a / b);
        updateLcdResult();
    }
    updateLcdOperand();
    b = 0;
}


void MainWindow::on_button_plus_clicked() {

    result = QString::number(operand);
    a = operand;
    updateLcdResult();
    on_button_c_clicked(); // очищаем операнд и надо ввести новые цифры
    operation = ""; // очищаем операцию
    operation = "+";
}


void MainWindow::on_button_minus_clicked() {
    result = QString::number(operand);
    a = operand;
    updateLcdResult();
    on_button_c_clicked(); // очищаем операнд и надо ввести новые цифры
    operation = ""; // очищаем операцию
    operation = "-";
}


void MainWindow::on_button_multiply_clicked() {
    result = QString::number(operand);
    a = operand;
    updateLcdResult();
    on_button_c_clicked(); // очищаем операнд и надо ввести новые цифры
    operation = ""; // очищаем операцию
    operation = "*";
}


void MainWindow::on_button_divide_clicked() {
    result = QString::number(operand);
    a = operand;
    updateLcdResult();
    on_button_c_clicked(); // очищаем операнд и надо ввести новые цифры
    operation = ""; // очищаем операцию
    operation = "/";
}

void MainWindow::updateLcdOperand() {
    ui->lcd_operand->display(operand);
}

void MainWindow::updateLcdResult() {
    ui->lcd_result->setText(result);
}
