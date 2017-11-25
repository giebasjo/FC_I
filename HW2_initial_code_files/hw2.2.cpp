
// File: hw2.2.cpp
// Author(s):

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const double pi(3.1415926535897932);
    const double *ppi{&pi};

    cout << fixed << setprecision(15);

    cout << "pi:    " << pi << '\n';
    cout << "&pi:   " << &pi << '\n';
    cout << "ppi:   " << ppi << '\n';
    cout << "*ppi:  " << *ppi << '\n';

    /* code for part (b)
    const double e;
    */

    /* code for part (c)
    const double e(2.7182818284590452);
    cout << "e:     " << e << '\n';
    */

    /* code for part (d)
    double *pe(&e);  // pe points to e
    */

    /* code for part (e)
    double *pe((double *)&e);  // force pe to point to e
    cout << "pe:    " << pe << '\n';    // address of e
    cout << "*pe:   " << *pe << '\n';   // value of e
    */

    /* code for part (f)
    *pe = pi;		// change e to pi?
    cout << "*pe:   " << *pe << '\n';   // is e now pi?
    */

    /* code for part (g)
    cout << "e:     " << e << '\n';    // is e now pi?
    cout << "&e:    " << &e << '\n';   // address of e
    cout << "pe:    " << pe << '\n';   // same as address of e?
    cout << "*pe:   " << *pe << '\n';  // value of e?
    */

    return 0;
}

