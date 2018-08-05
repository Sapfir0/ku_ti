#ifndef MORE_ONE_SORTING_H
#define MORE_ONE_SORTING_H

#include <QDialog>
#include <QDebug>
#include <QFileDialog>

namespace Ui {
class More_one_sorting;
}

class More_one_sorting : public QDialog
{
    Q_OBJECT

public:
    explicit More_one_sorting(QWidget *parent = nullptr);
    ~More_one_sorting();

private slots:
    void on_iconOrNo_stateChanged(int arg1);

    void on_popular_sort_stateChanged(int arg1);

    void on_browse_clicked();

    void on_diff_spin_valueChanged(int arg1);

    void reject();
    void accept();

    void on_buttonBox_accepted();

    void on_title_user_textChanged(const QString &arg1);

    void on_progressBar_valueChanged(int value);

private:
    Ui::More_one_sorting *ui;
};

#endif // MORE_ONE_SORTING_H
