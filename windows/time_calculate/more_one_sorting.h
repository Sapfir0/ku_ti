#ifndef MORE_ONE_SORTING_H
#define MORE_ONE_SORTING_H

#include <QDialog>

namespace Ui {
class More_one_sorting;
}

class More_one_sorting : public QDialog
{
    Q_OBJECT

public:
    explicit More_one_sorting(QWidget *parent = nullptr);
    ~More_one_sorting();

private:
    Ui::More_one_sorting *ui;
};

#endif // MORE_ONE_SORTING_H
