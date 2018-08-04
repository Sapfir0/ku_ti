#include "settings.h"
#include "ui_settings.h"

#include <iostream>
#include <QFontDatabase>
#include <QFile>
#include <QTranslator>
#include <QDebug>
#include <QPushButton>

#include "windows/constructor/constructor_window.h"
#include "windows/time_calculate/time_calculate_window.h"
#include "windows/function/function_window.h"

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
    show();

    setWindowTitle(tr("Settings"));

    int id = QFontDatabase::addApplicationFont(":/fonts/SantEliaRoughAltBoldThrDEMO.otf"); //i fuck our users
    QString family = QFontDatabase::applicationFontFamilies(id).at(0); //use my fonts, biches
    QFont sk(family); //ooo da
    ui->logo->setFont(sk);

    QString OS="default";

#if (defined (_WIN32) || defined (_WIN64))
     OS = "Windows";
#elif (defined (LINUX) || defined (__linux__))
     OS = "Linux";
#endif

     if ( OS == "Windows")
     {
        QPixmap logo(":/new/prefix1/img/icons8-windows-xp-26.png");
        ui->OS_img->setPixmap(logo);
        ui->OS_title->setText(OS);
     }
     else if ( OS == "Linux")
     {
         QPixmap logo(":/new/prefix1/img/icons8-linux-filled-50.png");
         ui->OS_img->setPixmap(logo);
         ui->OS_title->setText(OS);
     }


     QPalette darkPalette;
     darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
     qApp->setPalette(darkPalette);

     check();
}
void settings::check() {
    QFile language_file("language.ini");
    if (language_file.open(QIODevice::ReadOnly))
    {
        QTranslator translator;
        if(language_file.readAll() == "Russian" )
        {
            //LINGVO=1;
            qDebug() << "rus";
            translator.load(":/translations/translate_RU.qm");
            qApp->installTranslator(&translator);
            qDebug() << "change to russian";
        }
        else
        {
            //LINGVO=0;
            qDebug() << "eng";
            qApp->installTranslator(&translator);
            qDebug() << "change to english";
        }
    }
     language_file.close();

}



settings::~settings()
{
    delete ui;
}

void settings::on_checkBox_stateChanged(bool arg1)
{
    QFile settings_file("settings.ini");
    if (settings_file.open(QIODevice::WriteOnly))
    {
        if (arg1 == true)
        {
            QTextStream writeStream(&settings_file);
            writeStream << "true";
        }
        else
        {
            QTextStream writeStream(&settings_file);
            writeStream << "false";
        }
    }
}


void settings::on_buttonBox_accepted()
{
    ui->buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                         | QDialogButtonBox::Cancel);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

void settings::accept()
{

    qDebug() << "ac";


}

void settings::reject()
{
    qDebug() << "rej";
    delete this;
}
