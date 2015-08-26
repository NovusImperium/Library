// File: Library.cpp
// Author: Kyle Janssen, Amandeep Gill
// Contents: This file contains the implementation of a class called Library.

#include <iostream>
#include "Library.h"
using namespace std;

Library::Library (void) {
    Type = LIBRARY;
}

Library::Library (string id) {
    ID = id;
}

Library::Library (const shared_ptr<Library> S) {
    Type = S->Type;
    Name = S->Name;
    ID = S->ID;
}

shared_ptr<Library> Library::operator = (const shared_ptr<Library> S) {
    Type = S->Type;
    Name = S->Name;
    ID = S->ID;

    return shared_ptr<Library>(this);
}

Library::LibType Library::IsA (void) const {
    return Type;
}


istream & operator >> (istream & ins, const shared_ptr<Library> S) {
    S->ReadIn(ins);
    return ins;
}


ostream & operator << (ostream & outs, const shared_ptr<Library> S) {
    S->WriteOut(outs);
    return outs;
}

void Library::SetType (string TypeS) {
    if (TypeS == "LIBRARY") 
        Type = LIBRARY;

    else if (TypeS == "MEMBER") 
        Type = MEMBER;
    
    else if (TypeS == "ASSET") 
        Type = ASSET;
    
    else if (TypeS == "BOOK") 
        Type = BOOK;
    
    else if (TypeS == "PERIODICAL") 
        Type = PERIODICAL;
    
    else 
        cout << "Not a valid LibType" << endl;
}

string Library::GetType (void) const {
    switch (Type)
    {
        case LIBRARY: return "LIBRARY";
        case MEMBER: return "MEMBER";
        case ASSET: return "ASSET";
        case BOOK: return "BOOK";
        case PERIODICAL: return "PERIODICALa";
        default: return "";
    }
}

vector<Date> Library::GetCheckoutDates (void) const {
    return vector<Date>();
}

vector<shared_ptr<Library> > Library::GetCheckedoutBy(void) const {
    debug << "Library::GetCheckedoutBy()\n";
    return vector<shared_ptr<Library> >();
}

void Library::CheckOut (shared_ptr<Library>member, shared_ptr<Library>asset, Date date, int number) {
    member->Add(asset, date, number);
    asset->Add(member, date, number);
}


void Library::Return (shared_ptr<Library>member, shared_ptr<Library>asset, int number) {
    member->Remove(asset, number);
    asset->Remove(member, number);
}

void Library::AddIssue(int volume, int number, string pubDate) {
}

void Library::ReadIn (istream & input) {
}


void Library::WriteOut (ostream & output) {
    output << "Type: LIBRARY" << endl;
    output << "Name: " << Name << endl;
    output << "ID: "   << ID   << endl;
}

string Library::GetPhone(void) const {
    return "";
}

vector<shared_ptr<Library> > Library::GetCheckedOut (void) const {
    return vector<shared_ptr<Library> >();
}

vector<Date> Library::GetDueDates (void)
{
    return vector<Date>();
}

string Library::GetID(void) {
    return ID;
}

string Library::GetName(void) const {
    return Name;
}

void Library::Add(shared_ptr<Library> lib, Date dueDate, int number) {
}

void Library::Remove(shared_ptr<Library> lib, int number) {
}

bool Library::operator==(const Library &lib) {
    return ID == lib.ID;
}

bool Library::operator==(const string &id) {
    return ID == id;
}

bool operator==(const shared_ptr<Library> lib, string id) {
    return *lib == id;
}

bool Library::operator<(const Library &lib) {
    return ID < lib.ID;
}

