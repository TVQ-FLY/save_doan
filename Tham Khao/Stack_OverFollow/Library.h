#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <fstream>
#include <string>
#include "book.h"
#include "student.h"

class Library : public Book, public Student
{
    std::fstream fp;
    //std::ifstream ifs;
    Book book;
    Student student;

  public:
    Library()                          ;
    Library(const Library&)            ;
    Library &operator=(const Library&) ;
    ~Library()                         ;

    void enter_book();
    void enter_stu();
    void display_book(const std::string&);
    void display_stu(const std::string&);
    void delete_book();
    void delete_stu(std::string&);
    void display_all_stu();
    void display_all_book();
    void book_issue();
    void book_deposit();
    void menu();
};
#endif
