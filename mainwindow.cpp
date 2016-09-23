#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    initUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::book()
{
    openBook();
    totalPage();
    openPage();
}

void MainWindow::bookmark()
{

}

void MainWindow::setting()
{
    ui->label_title->setText("setting");
}
void MainWindow::readBook(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName), file.errorString()));
        return;
    }

    QTextStream in(&file);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    text=in.readAll();
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    statusBar()->showMessage(tr("File loaded"), 2000);
    ui->label_title->setText(file.fileName());
}
void MainWindow::openBook()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
        readBook(fileName);

}
void MainWindow::openPage()
{
    ui->textB_left->setText(text.mid(page_current*PAGE_MAX,PAGE_MAX));
    ui->textB_right->setText(text.mid((page_current+1)*PAGE_MAX,PAGE_MAX));
    setPageStatus();
}
//progress
void MainWindow::setProgress(){

    ui->slider_progress->setValue(page_current);

}

void MainWindow::nextPage(){
    if(++page_current>page_total){
        --page_current;
    }

    setProgress();
}
void MainWindow::previousPage(){
    if(--page_current<0){
        ++page_current;
    }

    setProgress();
}
void MainWindow::totalPage(){
    page_total=text.count()/PAGE_MAX;
    ui->slider_progress->setMaximum(0);
    ui->slider_progress->setMaximum(page_total);
    ui->slider_progress->setPageStep(1);
}
void MainWindow::setPageStatus(){
    ui->label_status_left->setText(QString::number(page_current+1, 10));
    ui->label_status_right->setText(QString::number(page_current+2, 10));
}
void MainWindow::progress(){
    page_current=ui->slider_progress->value();
    openPage();
}

void MainWindow::initUi(){
    ui->setupUi(this);
    //add book tool button
    const QIcon bookIcon = QIcon::fromTheme("document-new", QIcon(":/icons/book.png"));
    QAction *bookAct = new QAction(bookIcon, tr("&Book"), this);
    bookAct->setShortcuts(QKeySequence::New);
    bookAct->setStatusTip(tr("Open a new book"));
    connect(bookAct, &QAction::triggered, this, &MainWindow::book);
    ui->mainToolBar->addAction(bookAct);
    //add bookmark tool button
    const QIcon bookmarkIcon = QIcon::fromTheme("document-new", QIcon(":/icons/star.png"));
    QAction *bookmarkAct = new QAction(bookmarkIcon, tr("&Bookmark"), this);
    bookmarkAct->setShortcuts(QKeySequence::Open);
    bookmarkAct->setStatusTip(tr("Open bookmark"));
    connect(bookmarkAct, &QAction::triggered, this, &MainWindow::bookmark);
    ui->mainToolBar->addAction(bookmarkAct);
    //add setting tool button
    const QIcon settingIcon = QIcon::fromTheme("document-new", QIcon(":/icons/setting.png"));
    QAction *settingAct = new QAction(settingIcon, tr("&Setting"), this);
    settingAct->setShortcuts(QKeySequence::New);
    settingAct->setStatusTip(tr("Open setting"));
    connect(settingAct, &QAction::triggered, this, &MainWindow::setting);
    ui->mainToolBar->addAction(settingAct);
    //add btn ->
    connect(ui->btn_down,&QPushButton::clicked,this,&MainWindow::nextPage);
    //add btn <-
    connect(ui->btn_up,&QPushButton::clicked,this,&MainWindow::previousPage);
    //page add ->
    connect(ui->textB_left,&QTextBrowser::anchorClicked,this,&MainWindow::previousPage);
    //page add <-
    connect(ui->textB_right,&QTextBrowser::anchorClicked,this,&MainWindow::nextPage);
    //font
    //font size
    ui->textB_left->setStyleSheet("font: 75 12pt \"微软雅黑\"");
    //progress
//    connect(ui->slider_progress,&QSlider::sliderReleased,this,&MainWindow::progress);
    connect(ui->slider_progress,&QSlider::valueChanged,this,&MainWindow::progress);

}
