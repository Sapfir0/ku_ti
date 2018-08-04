#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>


namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = nullptr);
    ~settings();

private slots:
    void check();


    void on_checkBox_stateChanged(bool arg1);

    void on_buttonBox_accepted();
    void reject();
    void accept();

private:
    Ui::settings *ui;
};

#endif // SETTINGS_H
