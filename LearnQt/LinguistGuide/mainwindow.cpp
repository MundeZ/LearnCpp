#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_MessageButton_clicked() {
    auto result = QMessageBox::question(this, tr("our message"),
                                        tr("this is our message for you"),
                                        QMessageBox::StandardButtons ((
                                            QMessageBox::Yes|
                                            QMessageBox::No)|
                                            QMessageBox::Help));

    switch (result) {
    case QMessageBox::Yes:
        QMessageBox::information(this, tr("Result"),
                                 tr("Yes was pressed"));
        break;
    case QMessageBox::No:
        QMessageBox::information(this, tr("Result"),
                                 tr("No was pressed"));
        break;
    case QMessageBox::Help:
        QMessageBox::information(this, tr("Result"),
                                 tr("we cant help you try again <a href=\"https://google.com\"> google </a>"));
        break;
    default:
        QMessageBox::information(this, tr("Result"),
                                 tr("some error"));
        break;
    }
}

