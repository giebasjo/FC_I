#include <iostream>
using namespace std;

/*
 * Various add functions
 * Should just template them
 */

int add(char c1, char c2) {
    return (((int)c1) + ((int)c2));
}

int add(int i1, int i2) { 
    return (i1+i2);
}

double add(double x1, double x2) {
    return (x1 + x2);
}

double add(double x1, double x2, double x3) {
    return add(add(x1,x2),x3);
}

int add(int i1, int i2, int i3, int i4) {
    return add(add(i1,i2),add(i3,i4));
}

/*
 * Various swap functions
 */

void swap(int *pi, int *pj) {
    int temp = *pi;
    *pi = *pj;
    *pj = temp;
}

void swap(double *px, double *py) {
    double temp = *px;
    *px = *py;
    *py = temp;
}

void swap(int &ri, int &rj) {
    int temp = ri;
    ri = rj;
    rj = temp;
}

void swap(double &rx, double &ry) {
    double temp = rx;
    rx = ry;
    ry = temp;
}

/*
 * Various max_of functions
 */

char max_of(char c1, char c2) {
    return ((c1>c2) ? c1 : c2);
}

int max_of(int i1, int i2) {
    return ((i1>i2) ? i1 : i2);
}

double max_of(double d1, double d2) {
    return ((d1>d2) ? d1 : d2);
}


int main()
{
    // part (a)
    cout << "hello, world\n";

    // part (b)
    cout << fixed;  // display decimal point for double
    cout << add('a', '\n') << '\n'; // compiled, res 107
    cout << add(5, 9) << '\n'; // compiled, res 14
    // cout << add('A', 32) << '\n'; // will not compile, we don't have a add function that takes mixed parameters as such
    // cout << add(9, 3.3) << '\n'; // won't compile, 9 is ambiguous 
    cout << add(3.5, 4.2) << '\n'; // compiled, res 7.700
    cout << add(1.1, 2.2, 3.3) << '\n'; //compiled, res 6.60000
    cout << add(1, 2, 3, 4) << '\n'; //compiled, res 10
    // cout << add(5, 4, 3, 2, 1) << '\n'; // will not compile, we don't have
    // this function specified
    cout << add(1, 2, 3) << '\n'; // compiles, res 6.000000
    cout << add(1.1, 2.2, 3.3, 4.4) << '\n'; // compiles 
    cout << add('A', 2.2, 1) << '\n'; // will compile, but implicit conversion happening

    // part (c)
    int i(7), j(13);
    double x(3.14), y(2.18);

    cout << "before swap: i: " << i << ", j: " << j << '\n';
    swap(&i, &j);    // pass pointers
    cout << "after swap:  i: " << i << ", j: " << j << '\n';

    cout << "before swap: i: " << i << ", j: " << j << '\n';
    swap(i, j);      // pass references
    cout << "after swap:  i: " << i << ", j: " << j << '\n';

    cout << "before swap: x: " << x << ", y: " << y << '\n';
    swap(&x, &y);    // pass pointers
    cout << "after swap:  x: " << x << ", y: " << y << '\n';

    cout << "before swap: x: " << x << ", y: " << y << '\n';
    swap(x, y);      // pass references
    cout << "after swap:  x: " << x << ", y: " << y << '\n';
    
    // part (d)
    cout << "max_of('a', 'b'): " << max_of('a', 'b') << '\n';
    cout << "max_of(-4, 8):    " << max_of(-4, 8) << '\n';
    cout << "max_of(2.2, 3.3): " << max_of(2.2, 3.3) << '\n';


}
