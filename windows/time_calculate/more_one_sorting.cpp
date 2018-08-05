#include "more_one_sorting.h"
#include "ui_more_one_sorting.h"

#include <QMessageBox>
#include "windows/time_calculate/time_calculate_window.h"

More_one_sorting::More_one_sorting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::More_one_sorting)
{
    ui->setupUi(this);
    show();

    ui->browse->hide();
    ui->change_sort_combo->hide();

}

More_one_sorting::~More_one_sorting()
{
    delete ui;
}

void More_one_sorting::on_iconOrNo_stateChanged(int arg1)
{
    qDebug() << arg1;
    if ( arg1 == 2)
        ui->browse->show();
    else if (arg1 == 0)
        ui->browse->hide();
}

void More_one_sorting::on_popular_sort_stateChanged(int arg1)
{
    qDebug() << arg1;
    if ( arg1 == 2)
    {
        ui->Razocharovanie->setText(tr("Ваша сортировка найдена)"));
        ui->change_sort_combo->show();
    }
    else if (arg1 == 0)
    {
        ui->Razocharovanie->setText(tr("Вам придется писать сортировку)))"));
        ui->change_sort_combo->hide();
    }
}

void More_one_sorting::on_browse_clicked()
{
    QString directory = QFileDialog::getOpenFileName(this,
                       tr("Find your image"), "", "*.jpg *.png");

    QPixmap img_os_sort = directory;
    img_os_sort = img_os_sort.scaled(100, 100, Qt::KeepAspectRatio);
    ui->img_fin->setPixmap(img_os_sort);
}

void More_one_sorting::on_diff_spin_valueChanged(int arg1)
{

    ui->progressBar->setValue(arg1);
}


void More_one_sorting::on_buttonBox_accepted()
{
    ui->buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                         | QDialogButtonBox::Cancel);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

void More_one_sorting::accept()
{

    qDebug() << "ac";

}

void More_one_sorting::reject()
{
    qDebug() << "rej";
    hide();
    new time_calculate_window(this); //heh
}

void More_one_sorting::on_title_user_textChanged(const QString &arg1)
{
    ui->Name_of_sort_fin->setText(arg1);
}
