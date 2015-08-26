#ifndef LIBRARYIO_H
#define LIBRARYIO_H

// File: LibraryIO.h
// Authors: Amandeep Gill, Marshall Jankovsky
// Contents: This file contains the function prototypes for inputing and outputing Library objects

#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <map>
#include <iostream>
#include <exception>

#include "Library.h"
#include "Book.h"
#include "Periodical.h"
#include "Member.h"

using namespace std;

// Comparison operators for dealing with shared_ptr's 
// equality
template<class T> inline bool operator==(const shared_ptr<T> lhs, const shared_ptr<T> rhs) {
    return *lhs == *rhs;
}

// lessthan
template<class T> inline bool operator<(const shared_ptr<T> lhs, const shared_ptr<T> rhs) {
    return *lhs < *rhs;
}

// equality with one shared_ptr
template<class T, class U> inline bool operator==(const shared_ptr<T> lhs, const U &rhs) {
    return *lhs == rhs;
}

template<class T, class U> inline bool operator<(const shared_ptr<T> lhs, const U &rhs) {
    return *lhs < rhs;
}

// struct to hold the checkout information while the Library objects are being read in
struct COAsset {
    // Constructor
    inline COAsset(void) {
        assetName = "";
        assetID = "";
        coBy = "";
        coDate = Date("00/00/00");
        issueNum = 0;
    }

    // overloaded equality operator
    inline bool operator==(const string &id) {
        return assetID == id;
    }

    inline bool operator==(const COAsset &coa) {
        if (assetID == coa.assetID) {
            if ((issueNum != 0 && coa.issueNum == 0) || (issueNum == 0 && coa.issueNum != 0))
                return true;
            else 
                return issueNum == coa.issueNum;
        }
        return false;
    }

    // overloaded output operator for COAsset
    inline friend ostream & operator<<(ostream &output, const COAsset &coa) {
        output << "assetID = " << coa.assetID << endl;
        output << "coBy = " << coa.coBy << endl;
        output << "coDate = " << coa.coDate << endl;
        output << "issueNum = " << coa.issueNum << endl;

        return output;
    }

    // Name of the asset that is checked out
    string assetName;
    // ID of the asset that is checked out
    string assetID;
    // who checked-out the asset
    string coBy;
    // checkout date
    Date coDate;
    // issue num; 0 if asset is not a periodical
    int issueNum;
};

// function to a COAsset vector by the date
inline bool sortByDate(const COAsset &lhs, const COAsset &rhs) {
    return lhs.coDate < rhs.coDate;
}

// function to load the library from the backup file specified by the user
void loadLib(vector<shared_ptr<Library> > &L) throw(const string);

// function to write the library to a backup file specified by the user
void saveLib(vector<shared_ptr<Library> > &L);

// function to allow the user to add a member to the library manually
void addMember(vector<shared_ptr<Library> > &L);

// function to read in and create a member from input stream
shared_ptr<Library> readMember(istream &infile, map<string, vector<shared_ptr<COAsset> > > &checkout);

// function to allow the user to manually add an asset, (book or periodical)
void addAsset(vector<shared_ptr<Library> > &L);

// function to read in and create a periodical asset from input stream
shared_ptr<Library> readPeriodical(istream &infile, map<string, vector<shared_ptr<COAsset> > > &checkout);

// function to read in and create a book asset from input stream
shared_ptr<Library> readBook(istream &infile, map<string, vector<shared_ptr<COAsset> > > &checkout);

// function to connect Members and Assets from the map of member and asset IDs
void checkoutAll(vector<shared_ptr<Library> > &L, map<string, vector<shared_ptr<COAsset> > > &m);

// Function to allow the user to manually remove an item from the library. All assets
// are returned before deletion of either member or asset, so no relationships are
// shown between objects that no longer exist.
void removeItem(vector<shared_ptr<Library> > &L, string id) throw(const string);

// function to check out an asset to a member
void checkoutAsset(vector<shared_ptr<Library> > &L, string memberID, string assetID, Date date, int number = 0) throw(const string);

// function currently does not do anything
void returnAsset(vector<shared_ptr<Library> > &L, string memberID, string assetID, int number = 0) throw(const string);

// function to create a report from the given library
void makeReport(const vector<shared_ptr<Library> > &L);

// Creates a report of overdue assets, sorted by due date.
void overdueAssetList(const vector<shared_ptr<Library> > &L, Date & today);

// Creates a report of members with overdue assets as well as the assets that are overdue for each member
void overdueMemberList(const vector<shared_ptr<Library> > &L, const Date today);

// Creats a report of members in a specific area code
void areaCodeList (const vector<shared_ptr<Library> > &L, const Date today);

// This function compares library pointers based on their IDs
bool IDSort (shared_ptr<Library> L1, shared_ptr<Library> L2);

// This function compares library pointers based on days overdue
bool OverdueSort (shared_ptr<COAsset> L1, shared_ptr<COAsset> L2);

#endif  // LIBRARYIO_H
