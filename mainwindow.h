#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void book();

private slots:

    void bookmark();
    void setting();
    void nextPage();
    void previousPage();
    void progress();

private:
    void readBook(const QString &fileName);
    void openBook();
    void openPage();
    void totalPage();
    void initUi();
    void setPageStatus();
    void setProgress();

    Ui::MainWindow *ui;
    QString text;
    const int PAGE_MAX=830;
    int page_current=0;
    int page_total=0;
};

#endif // MAINWINDOW_H
