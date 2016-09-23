#include "book.h"

Book::Book()
{

}
Book::Book(const QString &name,const QString &lable,int currentPage,int totalPage)
{
    this->name=name;
    this->lable=lable;
    this->currentPage=currentPage;
    this->totalPage=totalPage;
}
