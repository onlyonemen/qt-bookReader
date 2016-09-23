#ifndef BOOKWINDOW_H
#define BOOKWINDOW_H

#include <QMainWindow>
#include"book.h"

namespace Ui {
class BookWindow;
}

class BookWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BookWindow(QWidget *parent = 0);
    ~BookWindow();

private slots:
    void on_actionNew_triggered();

private:
    Ui::BookWindow *ui;
    void initToolBar();
    void initBookGrid();
    Book bookList[];
    void writeBookList(Book *book);
    void readBookList();
    void openBook();
};

#endif // BOOKWINDOW_H
