#ifndef BOOKFORM_H
#define BOOKFORM_H

#include <QWidget>

namespace Ui {
class BookForm;
}

class BookForm : public QWidget
{
    Q_OBJECT

public:
    explicit BookForm(QWidget *parent = 0);
    ~BookForm();

private slots:
    void on_btn_start_clicked();

private:
    Ui::BookForm *ui;
};

#endif // BOOKFORM_H
