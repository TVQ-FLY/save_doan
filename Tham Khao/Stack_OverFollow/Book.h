#ifndef BOOK_H_
#define BOOK_H_

#include <string>

class Book
{
    std::string book_num;
    std::string book_name;
    std::string author_name;

  public:
    Book()                      ;
    Book(const Book&)            ;
    Book &operator=(const Book&) ;
    ~Book()                      ;

    void new_entry();
    void show_book(std::string&, std::string&, std::string&);
    std::string get_book_num() const;
    void show_record();
};

#endif
