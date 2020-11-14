//
// Created by stpaul6tech on 11/14/20.
//

#ifndef LIBRA_BOOK_H
#define LIBRA_BOOK_H

#include <iostream>
#include <list>

using namespace std;


class Book {
public:
    Book();

    Book(string author, string title);

    string author() const { return m_author; }

    string title() const { return m_title; }

    void read(ifstream& in);

    void write(ofstream& out);

    void borrowBook(int customerId);

    int reserveBook(int customerId);

    void unreserveBook(int customerId);

    void returnBook();

    int bookId() const { return m_bookId; }

    bool borrowed() const { return m_borrowed; }

    int customerId() const { return m_customerId; }

    list<int> &reservationList() { return m_reservationList; }

    static int MaxBookId;

    friend ostream operator<<(ostream &outStream, const Book &book);

private:
    bool  m_borrowed= false;
    int m_bookId{},m_customerId{};
    string m_author;
    string m_title;
    list<int> m_reservationList;
};


#endif //LIBRA_BOOK_H
