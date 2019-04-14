#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),  ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_toggled(bool checked)
{
    if (checked)
    {
        ui->lineEdit->setEchoMode(QLineEdit::EchoMode::Normal);
    }
    else
    {
        ui->lineEdit->setEchoMode(QLineEdit::EchoMode::Password);
    }
}
