#include "more_one_sorting.h"
#include "ui_more_one_sorting.h"

#include <QMessageBox>
#include "windows/time_calculate/time_calculate_window.h"
#include "windows/time_calculate/write_sort.h"

More_one_sorting::More_one_sorting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::More_one_sorting)
{
    ui->setupUi(this);
    show();

    ui->browse->hide();
    ui->change_sort_combo->hide();
    ui->img_fin->setText(" ");

    QPalette palt;
    palt.setColor(QPalette::Window, QColor(53, 53, 53));
    qApp->setPalette(palt);


}

More_one_sorting::~More_one_sorting()
{
    delete ui;
}

void More_one_sorting::on_iconOrNo_stateChanged(int arg1)
{
    qDebug() << arg1;
    if ( arg1 == 2)
    {
        ui->browse->show();
    }
    else if (arg1 == 0)
    {
        ui->browse->hide();
        ui->img_fin->clear();
    }
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
    hide();
    new write_sort(this);

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


void More_one_sorting::on_progressBar_valueChanged(int value)
{
    Q_UNUSED(value);
    QString red_style = "QProgressBar {border: 1px solid grey;background-color: rgba(29, 55, 91, 10);border-radius: 5px;text-align: center;} "
                        "QProgressBar::chunk {background-color: rgba(255, 0, 0, 140);}";
    QString orange_style= "QProgressBar {border: 1px solid grey;background-color: rgba(29, 55, 91, 10);border-radius: 5px;text-align: center;} "
                          "QProgressBar::chunk {background-color: rgba(255, 165, 0, 140);}";
    QString yellow_style= "QProgressBar {border: 1px solid grey;background-color: rgba(29, 55, 91, 10);border-radius: 5px;text-align: center;} "
                          "QProgressBar::chunk {background-color: rgba(255, 255, 0, 140);}";
    QString green_style= "QProgressBar {border: 1px solid grey;background-color: rgba(29, 55, 91, 10);border-radius: 5px;text-align: center;} "
                         "QProgressBar::chunk {background-color: rgba(0, 128, 0, 140);}";
    QString green_light_style= "QProgressBar {border: 1px solid grey;background-color: rgba(29, 55, 91, 10);border-radius: 5px;text-align: center;} "
                         "QProgressBar::chunk {background-color: rgba(173, 255, 47, 140);}";

    if (ui->progressBar->value()<=10) //its dependence from progress bar's value
        ui->progressBar->setStyleSheet(green_style);//and now we need to do
                                                    //slow progress to nessessary value
    else if (ui->progressBar->value()>10 && ui->progressBar->value()<30)
        ui->progressBar->setStyleSheet(green_light_style);

    else if (ui->progressBar->value()>=30 &&ui->progressBar->value()<50)
        ui->progressBar->setStyleSheet(yellow_style);

    else if (ui->progressBar->value()>=50 && ui->progressBar->value() < 70)
        ui->progressBar->setStyleSheet(orange_style);

    else if (ui->progressBar->value()>=70 && ui->progressBar->value() <= 100)
        ui->progressBar->setStyleSheet(red_style);
}
