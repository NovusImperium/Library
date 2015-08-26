#ifndef BOOK_H
#define BOOK_H

// File: Book.h
// Authors: Amandeep Gill, Kyle Janssen
// Contents: This file contains the description of a class
// called Book.

#include <iostream>
#include <memory>
#include "Asset.h"
#include "Date.h"

using namespace std;

class Book : public Asset {
    public:
        // Enumerated type for Book Classification
        enum BookType {FICTION, NONFICTION};

        // The default constructor creates a new Book object.
        Book (void);

        // This overloaded constructor will set all informational data at once
        Book(string name, string id, string aType, string author, string isbn, string bType);

        // This copy constructor will create a new Book object identical to the
        // passed Book object.
        Book (const Book &B);

        // This assignment operator will copy the values of one Book object
        // to another.
        shared_ptr<Library> operator = (const Book &B);

        // This sets the BookType that this Book belongs to
        void SetType(string bType);

        // This function returns the checkOut date of the Book
        vector<Date> GetCheckoutDates(void) const;

        // This function returns a vector that contains the due date of the Book.
        vector<Date> GetDueDates (void);

        // This function returns the pointer to the Member that has thid Book checked out
        vector<shared_ptr<Library> > GetCheckedoutBy(void) const;

        // This function reads the state of the Book object from input.
        void ReadIn (istream & input);

        // This function writes the state of the Book object to output.
        void WriteOut (ostream & output);

        // ignored by book, not sure if this is necessary --Aman
        inline void AddIssue(int volume, int number, string pubDate) {}

    private:
        // This function checks out the Book to the given Member on the given Date
        void Add(shared_ptr<Library> member, Date checkoutDate, int number);

        // This function checks the Book back in
        void Remove(shared_ptr<Library> member, int number);

        string Author;
        string ISBN;
        BookType Type;
        Date CheckedOut;
        shared_ptr<Library> CheckedOutBy;
};

#endif
