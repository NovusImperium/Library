#ifndef PERIODICAL_H
#define PERIODICAL_H

// File: Periodical.h
// Authors: Amandeep Gill, 
// Contents: This file contains the description of a class called Periodical.

#include <iostream>
#include <vector>
#include <memory>
#include "Asset.h"
#include "Date.h"

using namespace std;

class Periodical : public Asset
{
    public:
        // Enumerated type for Periodical classification.
        enum PeriodicalType {FICTION, NONFICTION};

        // The default constructor creates a new Periodical object.
        Periodical (void);

        // This overloaded constructor sets all the informational data at once
        Periodical (string name, string id, string aType, string issn);

        // This copy constructor will create a new Periodical object identical to the
        // passed Periodical object.
        Periodical (const Periodical & P);

        // This assignment operator will copy the values of one Periodical object
        // to another.
        Periodical & operator = (const Periodical & P);

        // The IsA function will return the appropriate LibType.
        LibType IsA (void) const;

        // This function sets Type based on a string value.
        void SetType (string TypeS);

        // This function returns Type as a string.
        string GetType(void) const;

        // This function returns the checkout dates for all issues (00/00/00 if not checked out)
        vector<Date> GetCheckoutDates(void) const;

        // This function returns the due dates for all issues
        vector<Date> GetDueDates (void);

        // This function returns the list of Members that have Issues checked out
        vector<shared_ptr<Library> > GetCheckedoutBy(void) const;

        // This function adds an issue to the periodical
        void AddIssue(int volume, int volNum, string pubDate);

        // This function reads the state of the Periodical object from input.
        void ReadIn (istream & input);

        // This function writes the state of the Periodical object to output.
        void WriteOut (ostream & output);

    private:
        // This function sets the given issue to CheckedOut to the given member
        void Add(shared_ptr<Library> member, Date checkoutDate, int number);

        // This function returns the CheckedOut state of the given volume
        void Remove(shared_ptr<Library> member, int number);

        // This struct defines what an Issue is
        struct Issue {
            // default constructor for the Issue
            Issue(void);
            
            int Volume;
            int Number;
            string PubDate;
            Date CheckedOut;
            shared_ptr<Library> CheckedOutBy;
        };

        PeriodicalType Type;
        string ISSN;
        vector <Issue> Issues;
};

#endif
