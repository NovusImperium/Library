#ifndef LIBRARY_H
#define LIBRARY_H

// File: Library.h
// Author: Amandeep Gill
// Contents: This file contains the description of a virtual class
// called Library.

#include <vector>
#include <iostream>
#include <memory>
#include <sstream>

#include "Date.h"

#define DEBUG false
#define debug if (DEBUG) cout

using namespace std;

class Library
{
    public:
        // Enumerated types for Library Objects
        enum LibType {LIBRARY, MEMBER, ASSET, BOOK, PERIODICAL};

        // The default constructor creates a new library object.
        Library (void);

        // overloaded constructor with just ID for searching purposes
        Library (string id);

        // This constructor will create a new library object identical to the passed library
        // object.
        Library (const shared_ptr<Library> S);

        // This assignment operator will copy one object to another of the same type.
        shared_ptr<Library> operator = (const shared_ptr<Library> S);

        // The IsA function will return the appropriate LibType value.
        LibType IsA (void) const;

        // The input operator will call the ReadIn function for the passed library object.
        friend istream & operator >> (istream & outs, const shared_ptr<Library> S);

        // The output operator will call the WriteOut function for the passed library object.
        friend ostream & operator << (ostream & outs, const shared_ptr<Library> S);

        // This function sets Type based on a string value.
        void SetType (string TypeS);

        // This function returns the Library Type as a string.
        string GetType (void) const;

        // This function returns the checkout dates for all checked out items
        virtual vector<Date> GetCheckoutDates (void) const;

        // This function returns the Members that have an asset checked out
        virtual vector<shared_ptr<Library> > GetCheckedoutBy (void) const;

        // This function will only be implemented by Periodical
        virtual void AddIssue(int volume, int number, string pubDate);

        // This function will be used by the child classes to read in object state data from a report file
        virtual void ReadIn (istream & input);

        // This function will be used be the child classes to write out object state data to a report file
        virtual void WriteOut (ostream & output);

        // This function will return a phone number - only used by Member
        virtual string GetPhone (void) const;

        // This function will return the list of Assets checked out - only used by Member
        virtual vector<shared_ptr<Library> > GetCheckedOut (void) const;

        // This function wiill return a vector with the due dates of the object
        virtual vector<Date> GetDueDates (void);

        // This function checks out the asset to the member given
        static void CheckOut (shared_ptr<Library> member, shared_ptr<Library> asset, Date date, int number = 0);

        // This function returns the asset from the member given
        static void Return (shared_ptr<Library> member, shared_ptr<Library> asset, int number = 0);

        // This function returns the object's ID
        string GetID(void);

	// This function return the object's Name
	string GetName(void) const;

        // overloaded equality operator for Library pointers
        bool operator==(const Library &lib);

        // overloaded equality operator for comparing Library pointers to ID strings
        bool operator==(const string &id);

        // overloaded lessthan operator for Library pointers
        bool operator<(const Library &lib);
       
    protected:
        // This function is called by the static function CheckOut
        // The behavior of this function is defined as follows
        //  Members: adds the lib (typed as Asset) into the checked out list, ignores the date and issue number
        //  Assets: sets checkedOutBy to the lib (typed as Member) and sets the checkedOut date to date, Books ignore issue number
        virtual void Add(shared_ptr<Library> lib, Date date, int number);

        // This function is called by the static function Return
        // The behavior of this function is defined as follows
        //  Members: removes the lib (typed as Asset) from the checkout out list, ignores issue number
        //  Assets: sets checkedOutBy to NULL, Books ignore issue number
        virtual void Remove(shared_ptr<Library> lib, int number);

        LibType Type;
        string Name;
        string ID;

    private:
};

#endif
