#ifndef TIME_CALCULATE_WINDOW_H
#define TIME_CALCULATE_WINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QShortcut>
#include <QGraphicsEffect>
#include <QTimer>
#include <QThread>

#include "librarys/sort.h"

namespace Ui {
	class time_calculate_window;
}

class time_calculate_window : public QMainWindow
{
		Q_OBJECT

	public:
        explicit time_calculate_window(QWidget *parent = nullptr);
		~time_calculate_window();

		class sort_thread : public QThread
		{
		public:
				explicit sort_thread (QString threadName, int tsort, int arr_count) {
					t_sort = tsort;
					name = threadName;
					arr_size = arr_count;
				}

		// �������������� ����� run(), � ������� �����
		// ������������� ����������� ���
				void run() {
					int * arr = new int[arr_size];
					for (int i = 0; i < arr_size; i++)
						arr[i] = rand();
					switch(t_sort)
					{
						case 0 : {
//                            Bubble_sort(arr, arr_size);
							break;
						}
						case 1 : {
    //						Merge_sort(arr, arr_size);
							break;
						}
						case 2 : {
        //					Qsort(arr, 0, arr_size-1);
							break;
						}
						case 3 : {
            //				Tree_sort(arr, arr_size);
							break;
						}
						case 4 : {
                //			Radix_sort(arr, arr_size);
							break;
						}
					}
					delete[] arr;
				}
		private:
		QString name;   // ��� ������
			int t_sort, arr_size;
		};

	private slots:

		void on_actionBack_triggered();

		void on_elements_count_valueChanged(int arg1);

		void on_consider_clicked();

		void on_comboBox_currentIndexChanged(int index);

		//void on_actionSettings_triggered();

        void resizeEvent(QResizeEvent *evt);

        void what_do_every_mc();

        void on_progressBar_valueChanged(int value);

        void on_actionSettings_triggered();

private:
		Ui::time_calculate_window *ui;
		QWidget * mainwin;
        QShortcut       *keyEnter;
        QTimer *timer;
		int type_sort;
		long long int count_sort;
		sort_thread * thread_puk;
};



#endif // TIME_CALCULATE_WINDOW_H
