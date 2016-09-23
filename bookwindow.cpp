#include "bookwindow.h"
#include "ui_bookwindow.h"
#include <QtWidgets>

BookWindow::BookWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BookWindow)
{
    ui->setupUi(this);
    initToolBar();
    initBookGrid();
//    writeBookList();
//    readBookList();
}

BookWindow::~BookWindow()
{
    delete ui;
}
void BookWindow::initToolBar(){
//    const QIcon bookIcon = QIcon::fromTheme("document-new", QIcon(":/icons/folder.png"));
//    QAction *bookAct = new QAction(bookIcon, tr("&Book"), this);
//    bookAct->setShortcuts(QKeySequence::New);
//    bookAct->setStatusTip(tr("Open a new book"));
//    connect(bookAct, &QAction::triggered, this, &BookWindow::openBook);
//    ui->toolBar->addAction(bookAct);
//    //add bookmark tool button
//    const QIcon bookmarkIcon = QIcon::fromTheme("document-new", QIcon(":/icons/star.png"));
//    QAction *bookmarkAct = new QAction(bookmarkIcon, tr("&Bookmark"), this);
//    bookmarkAct->setShortcuts(QKeySequence::Open);
//    bookmarkAct->setStatusTip(tr("Open bookmark"));
//    connect(bookmarkAct, &QAction::triggered, this, &MainWindow::bookmark);
//    ui->toolBar->addAction(bookmarkAct);
//    //add setting tool button
//    const QIcon settingIcon = QIcon::fromTheme("document-new", QIcon(":/icons/settings.png"));
//    QAction *settingAct = new QAction(settingIcon, tr("&Setting"), this);
//    settingAct->setShortcuts(QKeySequence::New);
//    settingAct->setStatusTip(tr("Open setting"));
//    connect(settingAct, &QAction::triggered, this, &MainWindow::setting);
//    ui->toolBar->addAction(settingAct);


}
void BookWindow::openBook(){
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()){
        Book *book = new Book(fileName,"222",1,1);
        writeBookList(book);
    }


}

void BookWindow::initBookGrid(){
    ui->gridLayout_4->setSpacing(4);
    ui->gridLayout_4->setMargin(4);
    QLabel *lab_1=new QLabel;
    lab_1->setStyleSheet("image: url(:/icons/plus.png);");
    lab_1->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    ui->gridLayout_4->addWidget(lab_1,0,0);
    QLabel *lab_2=new QLabel;
    lab_2->setStyleSheet("image: url(:/icons/plus.png);");
    lab_2->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    ui->gridLayout_4->addWidget(lab_2,0,1);
    QLabel *lab_t_1=new QLabel;

    lab_t_1->setText("hello");
    lab_t_1->setAlignment(Qt::AlignHCenter);
    ui->gridLayout_4->addWidget(lab_t_1,1,0);

}
void BookWindow::readBookList(){
    QString fileName = QStandardPaths::standardLocations(QStandardPaths::HomeLocation)[0];
    fileName.append("/book.list");
    QSettings *configIniRead = new QSettings(fileName, QSettings::IniFormat);
    //将读取到的ini文件保存在QString中，先取值，然后通过toString()函数转换成QString类型
    QString ipResult = configIniRead->value("ip/second").toString();
    QString portResult = configIniRead->value("port/open").toString();
    //打印得到的结果
    qDebug() << ipResult;
    qDebug() << portResult;
    //读入入完成后删除指针
    delete configIniRead;

}
void BookWindow::writeBookList(Book *book){
    QString fileName = QStandardPaths::standardLocations(QStandardPaths::HomeLocation)[0];
    fileName.append("/book.list");
    //Qt中使用QSettings类读写ini文件
    //QSettings构造函数的第一个参数是ini文件的路径,第二个参数表示针对ini文件,第三个参数可以缺省

    QSettings *bookList = new QSettings(fileName, QSettings::IniFormat);
    //向ini文件中写入内容,setValue函数的两个参数是键值对
    //向ini文件的第一个节写入内容,ip节下的第一个参数
    bookList->setValue("book/name", book->name);
    //向ini文件的第一个节写入内容,ip节下的第二个参数
    bookList->setValue("book/lable", book->lable);
    //向ini文件的第二个节写入内容,port节下的第一个参数
    bookList->setValue("book/currentPage",book->currentPage );
    bookList->setValue("book/totalPage",book->totalPage );
    //写入完成后删除指针
    delete bookList;
}

void BookWindow::on_actionNew_triggered()
{
    openBook();
}
