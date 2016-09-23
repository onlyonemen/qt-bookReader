#include "bookform.h"
#include "mainwindow.h"
#include "ui_bookform.h"
#include <QtWidgets>

BookForm::BookForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookForm)
{
    ui->setupUi(this);
}

BookForm::~BookForm()
{
    delete ui;
}


void BookForm::on_btn_start_clicked()
{

    MainWindow *m=new MainWindow;
    m->book();
    m->show();
    this->setHidden(true);
}

