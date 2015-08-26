// File: Member.cpp
// Authors: Amandeep Gill
// Contents: This file contains the implementation of the Member class

#include "Member.h"

Member::Member(void) {
    Type = MEMBER;

    address = "";
    city = "";
    state = "";
    zip = "";
    phone = "";
    Name = "";
    ID = "";
}

Member::Member (string name, string id, string Address, string City, string State, string Zip, string Phone) {
    Type = MEMBER;
    Name = name;
    ID = id;
    address = Address;
    city = City;
    state = State;
    zip = Zip;
    phone = Phone;
}

Member::Member(const Member & m) {
    address = m.address;
    city = m.city;
    state = m.state;
    zip = m.zip;
    phone = m.phone;
    Name = m.Name;
    ID = m.ID;
    checkedOut = m.checkedOut;
}

Member & Member::operator=(const Member & m) {
    address = m.address;
    city = m.city;
    state = m.state;
    zip = m.zip;
    phone = m.phone;
    Name = m.Name;
    ID = m.ID;
    checkedOut = m.checkedOut;

    return *this;
}

string Member::GetPhone () const
{
    return phone;
}

vector<shared_ptr<Library> > Member::GetCheckedOut(void) const {
    return checkedOut;
}

void Member::Add(shared_ptr<Library> asset, Date date, int number) {
    checkedOut.push_back(asset);
}

void Member::Remove(shared_ptr<Library> asset, int number) {
    for (unsigned int i = 0; i < checkedOut.size(); ++i) {
        if (checkedOut[i] == asset) {
            checkedOut.erase(checkedOut.begin() + i);
            return;
        }
    }
}

void Member::ReadIn(istream &input) {
    for (string line; input.good(); getline(input, line)) {
        int i = line.find(" ");
        string fieldName = line.substr(0, i);
        string fieldData = line.substr(i+1);

        if (fieldName == "Name:")
            Name = fieldData;

        else if (fieldName == "ID:")
            ID = fieldData;

        else if (fieldName == "Address:")
            address = fieldData;

        else if (fieldName == "City:")
            city = fieldData;

        else if (fieldName == "State:")
            state = fieldData;

        else if (fieldName == "Zip:")
            zip = fieldData;

        else if (fieldName == "Phone_Number:") {
            phone = fieldData;
            return;
        }
    }
}

void Member::WriteOut(ostream &output) {
    output << "Type: " << Library::GetType() << endl;
    output << "Name: " << Name << endl;
    output << "ID: " << ID << endl;
    output << "Address: " << address << endl;
    output << "City: " << city << endl;
    output << "State: " << state << endl;
    output << "Zip: " << zip << endl;
    output << "Phone_Number: " << phone << endl;
    output << "Checked_Out: " << checkedOut.size();

    for (unsigned int i = 0; i < checkedOut.size(); ++i) {
        output << " " << checkedOut[i]->GetID();
    }

    output << endl << endl;
}

