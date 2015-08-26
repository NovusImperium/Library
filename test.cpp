#include <iostream>
#include "Date.h"

using namespace std;

int main(void) {
    Date today = Date::Today();
    Date dueBy("08/19/2013");
    cout << today - dueBy << endl;
    dueBy = dueBy + 11;
    cout << dueBy << endl;
    return 0;
}
