#ifndef FUNCTION_WINDOW_H
#define FUNCTION_WINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QGraphicsEffect>

namespace Ui {
	class function_window;
}

class function_window : public QMainWindow
{
		Q_OBJECT

	public:
        explicit function_window(QWidget *parent = nullptr);
		~function_window();

	private slots:
		void on_actionBack_triggered();

		void on_actionRefresh_triggered();

		void on_first_count_valueChanged(int arg1);

		void on_consider_clicked();

		void print_result(unsigned long long puk);

        void resizeEvent(QResizeEvent *evt);

		//functions
		void on_actionFactorial_triggered();
		void on_actionconversion_from_decimal_to_binary_triggered();
		void on_actionApproximate_calculation_triggered();
		void on_actionDerivative_triggered();

        void on_actionSettings_triggered();

private:
		Ui::function_window *ui;
		QWidget * mainwin;
		unsigned long long int count_calculate;
		int type_function;
};

#endif // FUNCTION_WINDOW_H
