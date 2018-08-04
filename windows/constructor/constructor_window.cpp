#include "constructor_window.h"
#include "ui_constructor_window.h"

#include "settings.h"

constructor_window::constructor_window(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::constructor_window)
{
	ui->setupUi(this);
	mainwin = parent;

	show();

    setWindowTitle(tr("Constructor"));

    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
     shadowEffect -> setBlurRadius(9.0);
     shadowEffect -> setColor(QColor(0, 0, 0, 160));
     shadowEffect -> setOffset(4.0);
     ui->centralwidget->setGraphicsEffect(shadowEffect);

    QPalette split_color; //������ ��� ���� ������� ����� ��������� ����� � ����� ����
    split_color.setColor(QPalette::Background, Qt::darkGray);
    ui->splitter->setPalette(split_color);

    QGraphicsBlurEffect* sapEffect = new QGraphicsBlurEffect(this);
    sapEffect ->setBlurRadius(9.0);
    ui->input_box->setGraphicsEffect(sapEffect);

    ui->toolBar->setMovable(false);
     //ui->input_box->setAutoFillBackground(true); //����� ������� �����, ���� ���� ������� ��� ���


    keyEnter = new QShortcut(this);
    keyEnter->setKey(Qt::Key_Enter);
    connect(keyEnter,SIGNAL(activated()), this, SLOT(on_compile_clicked())); //��� ���� ����� ������� �� ����� ��������� �������� ��������


}


constructor_window::~constructor_window()
{
	delete ui;
}

void constructor_window::on_actionBack_triggered()
{
	mainwin->show();
	delete this;
}

void constructor_window::on_compile_clicked()
{

}

void constructor_window::resizeEvent(QResizeEvent *evt)
{
    Q_UNUSED(evt);
    QPixmap bkgnd(":/new/prefix1/img/david-marcu-114194-unsplash.jpg");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette plt = palette();
    plt.setBrush(QPalette::Background,bkgnd);
    setPalette(plt);
}

void constructor_window::on_actionSettings_triggered()
{
    hide();
    new settings(this);


}
