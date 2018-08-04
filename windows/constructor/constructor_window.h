#ifndef CONSTRUCTOR_WINDOW_H
#define CONSTRUCTOR_WINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include <QGraphicsEffect>

namespace Ui {
	class constructor_window;
}

class constructor_window : public QMainWindow
{
		Q_OBJECT

	public:
        explicit constructor_window(QWidget *parent = nullptr);
		~constructor_window();

	private slots:

		void on_actionBack_triggered();

        void on_compile_clicked();

        void resizeEvent(QResizeEvent *evt);  //redefinition default func

        void on_actionSettings_triggered();

private:
		Ui::constructor_window *ui;
		QWidget * mainwin;
        QShortcut       *keyEnter;

};

#endif // CONSTRUCTOR_WINDOW_H
