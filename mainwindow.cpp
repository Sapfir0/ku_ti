#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFontDatabase>

#include "windows/constructor/constructor_window.h"
#include "windows/time_calculate/time_calculate_window.h"
#include "windows/function/function_window.h"

int LINGVO=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    setWindowTitle(tr("Diplom"));

    int id = QFontDatabase::addApplicationFont(":/fonts/SantEliaRoughAltBoldThrDEMO.otf"); //i fuck our users
    QString family = QFontDatabase::applicationFontFamilies(id).at(0); //use my fonts, biches
    QFont sk(family); //ooo da
    ui->logo->setFont(sk);

    ui->centralWidget->setStyleSheet("background-color: #2E2F31;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_function_button_clicked()
{
    hide();
    new function_window(this);
}

void MainWindow::on_time_calculate_clicked()
{
    hide();
    new time_calculate_window(this);
}

void MainWindow::on_constructor_clicked()
{
    hide();
    new constructor_window(this);
}


