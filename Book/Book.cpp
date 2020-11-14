//
// Created by stpaul6tech on 11/14/20.
//

#include "Book.h"
#include <list>
#include <map>
#include <string>
#include <fstream>
#include <ostream>
#include <utility>

using namespace std;


int Book::MaxBookId=0;

Book::Book() = default;

Book::Book(string author, string title):m_bookId(++MaxBookId),m_author(std::move(author)),m_title(std::move(title)) {
    // Empty the constructor is make to access the value .
}

void Book::read(ifstream& in) {
    in.read((char*) &m_bookId, sizeof m_bookId);
    getline(in,m_author);
    getline(in,m_title);

    in.read((char*) &m_borrowed,sizeof m_borrowed);
    in.read((char*) &m_customerId , sizeof m_customerId);

    // Reading the reservation list using the number of reservation in the list

    {
        int reservationListSize;
        in.read((char*) &reservationListSize ,sizeof reservationListSize);
        for (int count = 0; count < reservationListSize; ++count) {
            int customerId;
            in.read((char*) &customerId,sizeof customerId);
            m_reservationList.push_back(customerId);
        }
    }
}

void Book::write(ofstream& out) {
    out.write((char*) &m_bookId,sizeof m_bookId);
    out<<m_author<<endl;
    out<<m_title<<endl;

    out.write((char*) &m_borrowed , sizeof m_borrowed);
    out.write((char*) &m_customerId , sizeof m_customerId);

    // reading value with the number of reservation in the list
    {
        int reservationListSize=m_reservationList.size();
        out.write((char*) &reservationListSize ,sizeof reservationListSize);
        for(int customerId : m_reservationList){
            out.write((char*) &customerId,sizeof customerId);
        }
    }
}

void Book::borrowBook(int customerId) {
    m_borrowed=true;
    m_customerId=customerId;
}

int Book::reserveBook(int customerId) {
    m_reservationList.push_back(customerId);
    return m_reservationList.size();
}

void Book::unreserveBook(int customerId) {
    m_reservationList.remove(customerId);
}

void Book::returnBook() {
    m_borrowed=false;
}

ostream operator<<(ostream &outStream, const Book &book) {
        outStream<<" "<<book.m_title<<" By "<<book.m_author;
    if (book.m_borrowed) {
        outStream << endl << " Borrowed by: "
                  << Library::s_customerMap[book.m_customerId].name()
                  << ".";
    }
    if (!book.m_reservationList.empty()) {
        outStream << endl << " Reserved by: ";
        bool first = true;
        for (int customerId : book.m_reservationList) {
            outStream << (first ? "" : ",")
                      << Library::s_customerMap[customerId].name();
            first = false;
        }
        outStream << ".";
    }
    return outStream;
}
}
