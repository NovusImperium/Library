// File: Asset.cpp
// Author: Amandeep Gill
// Contents: This file contains the implementation of the Asset class

#include "Asset.h"

Asset::Asset(void) {
}

void Asset::SetType (string TypeS)
{
        if (TypeS == "SHORT") 
            Type = SHORT;

        else if (TypeS == "LITERARY") 
            Type = LITERARY;

        else if (TypeS == "MYSTERY") 
            Type = MYSTERY;

        else if (TypeS == "SCIFI") 
            Type = SCIFI;

        else if (TypeS == "SELFHELP") 
            Type = SELFHELP;

        else if (TypeS == "BIOGRAPHY") 
            Type = BIOGRAPHY;

        else if (TypeS == "COOKING") 
            Type = COOKING;

        else if (TypeS == "SPORTS") 
            Type = SPORTS;

        else 
            cout << "Not a valid LibType" << endl;
}

string Asset::GetType () const
{
    switch (Type)
    {
        case SHORT: return "SHORT";
        case LITERARY: return "LITERARY";
        case MYSTERY: return "MYSTERY";
        case SCIFI: return "SCIFI";
        case SELFHELP: return "SELFHELP";
        case BIOGRAPHY: return "BIOGRAPHY";
        case COOKING: return "COOKING";
        case SPORTS: return "SPORTS";
        default: return "";
    }
}
