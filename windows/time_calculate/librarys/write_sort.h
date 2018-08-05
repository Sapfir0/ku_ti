#ifndef WRITE_SORT_H
#define WRITE_SORT_H

#include <QDialog>

namespace Ui {
class write_sort;
}

class write_sort : public QDialog
{
    Q_OBJECT

public:
    explicit write_sort(QWidget *parent = nullptr);
    ~write_sort();

private:
    Ui::write_sort *ui;
};

#endif // WRITE_SORT_H
