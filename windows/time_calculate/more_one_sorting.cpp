#include "more_one_sorting.h"
#include "ui_more_one_sorting.h"

More_one_sorting::More_one_sorting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::More_one_sorting)
{
    ui->setupUi(this);
}

More_one_sorting::~More_one_sorting()
{
    delete ui;
}
