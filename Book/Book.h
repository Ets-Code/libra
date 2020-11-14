//
// Created by stpaul6tech on 11/14/20.
//

#ifndef LIBRA_BOOK_H
#define LIBRA_BOOK_H

#include <iostream>

using namespace std;


class Book {
public:
    Book();

    Book(const string &author, const string &title);
    string author() const { return m_author;}
    string title() const { return m_title;}
    void read(ostream out);
    void write(ostream in);
    void borrowBook(int customerId);
    void reserveBook(int customerId);

    __unused void unreserveBook(int customerId);
    void returnBook(int customerId);

private:
    string m_author;
    string m_title;
};


#endif //LIBRA_BOOK_H
