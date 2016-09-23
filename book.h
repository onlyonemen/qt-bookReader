#ifndef BOOK_H
#define BOOK_H
#include<QString>


class Book
{
public:
    Book();
    Book(const QString &name,const QString &lable,int currentPage,int totalPage);
    QString name;
    QString lable;
    int currentPage;
    int totalPage;
};

#endif // BOOK_H
