#include "write_sort.h"
#include "ui_write_sort.h"



write_sort::write_sort(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::write_sort)
{
    ui->setupUi(this);
    show();


}

write_sort::~write_sort()
{
    delete ui;
}

