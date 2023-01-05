#ifndef STUDENT_H_
#define STUDENT_H_

class Student
{
    std::string roll_num;
    std::string stu_name;
    std::string issued_book_num;
    unsigned int token;

  public:
    Student()                         ;
    Student(const Student&)            ;
    Student &operator=(const Student&) ;
    ~Student()                         ;

    void new_entry();
    void show_stu(std::string&, std::string&, unsigned int, std::string&);
    void reset_issued_book_num();
    void reset_token();
    void show_record();
};
#endif
