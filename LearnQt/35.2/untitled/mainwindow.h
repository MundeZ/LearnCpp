#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_1_clicked();
    void on_button_2_clicked();
    void on_button_3_clicked();
    void on_button_4_clicked();
    void on_button_5_clicked();
    void on_button_6_clicked();
    void on_button_7_clicked();
    void on_button_8_clicked();
    void on_button_9_clicked();
    void on_button_c_clicked();
    void on_button_backspace_clicked();
    void on_button_eq_clicked();
    void on_button_plus_clicked();
    void on_button_minus_clicked();
    void on_button_multiply_clicked();
    void on_button_divide_clicked();
    void on_button_0_clicked();


    void updateLcdOperand();
    void updateLcdResult();

private:
    double operand = 0;
    double a;
    double b;
    QString operation;
    QString result;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
