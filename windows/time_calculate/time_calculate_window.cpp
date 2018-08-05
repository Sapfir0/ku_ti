#include "time_calculate_window.h"
#include "ui_time_calculate_window.h"

#include "windows/time_calculate/more_one_sorting.h"
#include "windows/time_calculate/librarys/color_progress_bar.h"

time_calculate_window::time_calculate_window(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::time_calculate_window)
{
	ui->setupUi(this);
	mainwin = parent;
	show();

    setWindowTitle(tr("Time calculate"));

	on_comboBox_currentIndexChanged(0);//ставим пузырьковую сортировку первой
	on_elements_count_valueChanged(0);//ставим размер сортировки
    //translate on utf8, proger
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect -> setBlurRadius(9.0);
    shadowEffect -> setColor(QColor(0, 0, 0, 160));
    shadowEffect -> setOffset(4.0);

    ui->centralwidget->setGraphicsEffect(shadowEffect);

    keyEnter = new QShortcut(this);
    keyEnter->setKey(Qt::Key_Enter);
    connect(keyEnter,SIGNAL(activated()), this, SLOT(on_consider_clicked()));

    ui->toolBar->setMovable(false);

    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(what_do_every_mc())); //��� ������ ������ ���

    int id = QFontDatabase::addApplicationFont(":/fonts/SantEliaRoughAltBoldThrDEMO.otf"); //i fuck our users
    QString family = QFontDatabase::applicationFontFamilies(id).at(0); //use my fonts, biches
    QFont sk(family); //ooo da
    ui->label_4->setFont(sk);
    ui->quote->setFont(sk);




}

time_calculate_window::~time_calculate_window()
{
	delete ui;
}

void time_calculate_window::on_actionBack_triggered()
{
	mainwin->show();
	delete this;
}

void time_calculate_window::what_do_every_mc()
{
    //WE NEED QTHREADS
    static double p = 0.001; //default time = 1 mc
    ui->lcdNumber->display(QString::number(p+=0.006)); //+0.6mc
    //qDebug() << "timer executed"<< p;
	if ( thread_puk->isFinished ()) {
        timer->stop();
        p = 0.001;
		delete thread_puk;
    }
}

void time_calculate_window::on_comboBox_currentIndexChanged(int index)
{
    type_sort = index;

	struct {
		QString name;
		int top;
	} listSort[5] = { {"Bubble sort", 90} , {"Merge sort", 65} , {"Quick sort", 45} , {"Tree sort", 35} , {"Radix sort", 20} };

	ui->statusbar->showMessage(listSort[type_sort].name);
	ui->progressBar->setValue(listSort[type_sort].top);
}

void time_calculate_window::on_elements_count_valueChanged(int arg1)
{
	count_sort = arg1;
}

void time_calculate_window::on_consider_clicked()
{
     //WE NEED QTHREADS
    //fix me please (dobav sortirovki) //i'm add file sortings
	ui->lcdNumber->display(0);
	sort_thread * puk = new sort_thread("puk_sort", type_sort, count_sort);
	thread_puk = puk;
	timer->start();
	puk->start();

}


void time_calculate_window::resizeEvent(QResizeEvent *evt) //heh its nice func, but its not working
{
    Q_UNUSED(evt); //:/new/prefix1/img/andrew-seaman-746845-unsplash.jpg
    QPixmap bkgnd(":/new/prefix1/img/tim-marshall-82948-unsplash.jpg");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette plt = palette();
    plt.setBrush(QPalette::Background,bkgnd);
    setPalette(plt);
    qDebug() << "passed" << "\n";
}

void time_calculate_window::on_progressBar_valueChanged(int value)
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

void time_calculate_window::on_actionSettings_triggered()
{
    hide();
    new settings(this);
}

void time_calculate_window::on_actionLet_s_try_triggered()
{
    hide();
    new More_one_sorting(this);
}
