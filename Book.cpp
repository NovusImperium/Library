// File: Book.cpp
// Author: Kyle Janssen
// Contents: This file contains the implementation of a class
// called Book.

#include <iostream>
#include <ctime>
#include "Asset.h"
#include "Book.h"

Book::Book () {
    Library::Type = BOOK;
    Author = "";
    ISBN = "";
    CheckedOut = Date (0, 0, 0);
    CheckedOutBy = NULL;
}

Book::Book(string name, string id, string aType, string author, string isbn, string bType) {
    Library::Type = BOOK;
    Name = name;
    ID = id;
    Asset::SetType(aType);
    Author = author;
    ISBN = isbn;

}

Book::Book (const Book &B) {
    Library::Type = BOOK;
    Asset::Type = B.Asset::Type;
    Type = B.Type;
    Author = B.Author;
    ISBN = B.ISBN;
    CheckedOut = B.CheckedOut;
    CheckedOutBy = B.CheckedOutBy;
}

void Book::SetType(string bType) {
    if (bType == "FICTION")
        Book::Type = FICTION;
    else if (bType == "NONFICTION")
        Book::Type = NONFICTION;
}

shared_ptr<Library> Book::operator = (const Book &B) {
    Library::Type = BOOK;
    Asset::Type = B.Asset::Type;
    Type = B.Type;
    Author = B.Author;
    ISBN = B.ISBN;
    CheckedOut = B.CheckedOut;
    CheckedOutBy = B.CheckedOutBy;

    return shared_ptr<Library>(this);
}

vector<Date> Book::GetCheckoutDates(void) const {
    return vector<Date>(1, CheckedOut);
}

vector<Date> Book::GetDueDates (void) {
    if (!CheckedOut.IsNull())
      return vector<Date>(1, CheckedOut + 27);
    else
        return vector<Date>(1, CheckedOut);
}

vector<shared_ptr<Library> > Book::GetCheckedoutBy(void) const {
    return vector<shared_ptr<Library> >(1, CheckedOutBy);
}

void Book::ReadIn (istream & input) {
    for (string line; input.good(); getline(input, line)) {
        int i = line.find(" ");
        string fieldName = line.substr(0, i);
        string fieldData = line.substr(i+1);

        if (fieldName == "Name:")  {
            Name = fieldData;
            debug << "Getting name = " << fieldData << endl;
        }

        else if (fieldName == "ID:") {
            ID = fieldData;
            debug << "Getting ID = " << fieldData << endl;
        }

        else if (fieldName == "Asset_Type:") {
            Asset::SetType(fieldData);
            debug << "Getting = Asset_Type = " << fieldData << endl;
        } 
        
        else if (fieldName == "Author:") {
            Author = fieldData;
            debug << "Getting Author = " << fieldData << endl;
        }

        else if (fieldName == "ISBN:") {
            ISBN = fieldData;
            debug << "Getting ISBN = " << fieldData << endl;
        }

        else if (fieldName == "Type:") {
            Book::SetType(fieldData);
            debug << "Getting book Type = " << fieldData << endl;
        } 
        
        else if (fieldName == "Checked_Out_On:") {
            CheckedOut = Date(fieldData);
            debug << "Getting checkout date = " << fieldData << endl;
            return;
        }
    }
}

void Book::WriteOut (ostream & output) {
    output << "Type: BOOK" << endl;
    output << "Name: " << Name << endl;
    output << "ID: " << ID << endl;
    output << "Asset_Type: " << Asset::GetType() << endl; 
    output << "Author: " << Author << endl;
    output << "ISBN: " << ISBN << endl;
    output << "Checked_Out_On: " << CheckedOut << endl;
    output << "Checked_Out_By: ";

    if (CheckedOutBy != NULL)
        output << CheckedOutBy->GetID();
    else
        output << "NONE";

    output << endl << endl;
}

void Book::Add(shared_ptr<Library> member, Date checkoutDate, int number) {
    CheckedOut = checkoutDate;
    CheckedOutBy = member;
}

void Book::Remove(shared_ptr<Library> member, int number) {
    CheckedOut.SetNull();
    CheckedOutBy = NULL;
}
