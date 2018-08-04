#include "function_window.h"
#include "ui_function_window.h"

#include "settings.h"


function_window::function_window(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::function_window)
{
	ui->setupUi(this);
	mainwin = parent;
	show();

    setWindowTitle(tr("Functions"));

	//це конструктор так что це подготовка
	count_calculate = 0;
	type_function = 0;
	print_result(0);


    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
      shadowEffect -> setBlurRadius(9.0);
      shadowEffect -> setColor(QColor(0, 0, 0, 160));
      shadowEffect -> setOffset(4.0);

     // ui->centralwidget->setGraphicsEffect(shadowEffect);

      ui->toolBar->setMovable(false);

}

function_window::~function_window()
{
	delete ui;
}

void function_window::on_actionBack_triggered()
{
	mainwin->show();
	delete this;
}

void function_window::on_actionRefresh_triggered()
{
	hide();
	new function_window(mainwin);
	delete this;
}

void function_window::on_first_count_valueChanged(int arg1)
{
	count_calculate = arg1;
}

void function_window::on_consider_clicked()
{
	long long int result = 0;
	switch (type_function)
	{
		case 0 : {//факториал
			result = 1;
			for (unsigned long long int i = 2; i <= count_calculate; i++) {
				result *= i;
			}
			break;
		}
		case 1 : {//конверсия 10 ту 2 ( я могу сделать и универсальную, но не хочу )
			unsigned long long int i = 1, binary = 0, N = count_calculate;
			while(N > 0) {
				binary += (N % 2) * i;
				N = N / 2;
				i *= 10;
			}
			result = binary;
			break;
		}
		case 2 : {//хузе
			break;
		}
		case 3 : {//тоже хузе
			break;
		}
		default : {
			qDebug() << "hello, myster bug";
		}
	}

	print_result(result);
}

void function_window::print_result(unsigned long long puk) {
	ui->printf_result->setText(QString::number(puk));
}

//functions clicked
void function_window::on_actionFactorial_triggered() {
	type_function = 0;
}
void function_window::on_actionconversion_from_decimal_to_binary_triggered() {
	type_function = 1;
}
void function_window::on_actionApproximate_calculation_triggered() {
	type_function = 2;
}
void function_window::on_actionDerivative_triggered() {
	type_function = 3;
}


void function_window::resizeEvent(QResizeEvent *evt)
{
    Q_UNUSED(evt);
    QPixmap bkgnd(":/new/prefix1/img/thomas-tixtaaz-119883-unsplash.jpg");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette plt = palette();
    plt.setBrush(QPalette::Background,bkgnd);
    setPalette(plt);
}

void function_window::on_actionSettings_triggered()
{
    hide();
    new settings(this);
}
