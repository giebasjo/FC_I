// File: hw1.2.cpp
// Author(s):
// Jordan Giebas
// Daniel Rojas Coy

#include <iostream>
#include <iomanip>
using namespace std;

struct Stock {
    char ticker[8];  // leave some extra space
    int id;          // my firm's ID for this stock
    double price;
};

struct Portfolio {
    Stock *stocks;   // the "array" of Stocks
    int *num_owned;  // can sell short, so int
    size_t nstocks;  // number of stocks, >= 0
};

void put_Stock(Stock *ps) {
    cout << setw(8) << ps->ticker << setw(4) << (*ps).id
         << setw(10) << ps[0].price;
}

// Part(e): the below function
void put_Portfolio_and_value ( Portfolio *pptr ) {

    cout << setw(8) << "Stock" << setw(6) << "ID" << setw(7) << "Price" 
         << setw(11) << "Position" << setw(10) << "Value" << endl;

    double port_tot(0.0);
    for ( int i(0); i < pptr->nstocks; ++i ) {
       
       cout << setw(8) << (pptr->stocks + i)->ticker << setw(6) << (pptr->stocks + i)->id 
            << setw(7) << (pptr->stocks + i)->price << setw(9) << pptr->num_owned[i]
            << setw(12) << (pptr->stocks + i)->price * pptr->num_owned[i] << endl;

        port_tot += (pptr->stocks + i)->price * pptr->num_owned[i];

    }

    cout << setw(36) << "Portfolio Total: " << port_tot;

}


int main()
{
    Stock apple{ "AAPL", 0, 162.45 },
          vmware{ "VMW", 1, 120.08 },
          ibm{ "IBM", 2, 153.72 },
          alcoa{ "AA", 3, 47.71 },
          mattel{ "MAT", 4, 15.58 },
          amd{ "AMD", 5, 10.98 },
          macy{ "M", 6, 18.84 },
          dish{ "DISH", 7, 48.39 },
          ford{ "F", 4, 12.07 };
    Portfolio p1{ new Stock[6]{ apple, ibm, ford, macy, amd, dish},
                  new int[6]{ 20, 10, -5, 15, 10, 5 },
                  6 };

    Portfolio *pp(&p1 + 2);
    Stock *ppf(p1.stocks + 1);

    put_Portfolio_and_value(&p1);

    // Part(c): The data type of the argument passed to the put_Stock function
    // is "Stock", although it itself is a pointer-to Stock

/*
    cout << "Portfolio:\n";
    for (int i(0); i < p1.nstocks; ++i) {
        //cout << "i: " << i << endl;
        put_Stock(p1.stocks + i);
        cout << setw(10) << p1.num_owned[i] << '\n';
    }
*/
    // Part(d): During the first iteration of the above for loop, the value of
    // the argument passed to put_Stock is the address of the first stock in the
    // array of stocks. 

    // Part(g): The value of apple.ticker is "AAPL"
    // Part(h): The datatype of apple.ticker is an array of 8 characters
    // Part(i): apple.ticker[3], value is "L" and datatype is char
    // Part(j): p1.stocks + 1, value is address and datatype is pointer-to-Stock
    // Part(k): sizeof ford.ticker, value is 8 and dataype is unsigned int
    // Part(l): sizeof vmware.price, value is 8 and the datatype is unsigned int
    // Part(m): sizeof p1.num_owned, value is 8 and the datatype is unsigned int
    // Part(n): *p1, datatype is pointer-to-portfolio, value is mem address 
    // Part(o): (p1.stocks+1)->name[3], value is ??? what is name
    // Part(p): (*p1.stocks).name + 3, value is ??? what is name
    // Part(q): p1.stocks[2].id, value is 2 and datatype is int
    // Part(r): (*&p1).num_owned[1]-3, value is __ and datatype is __    
    
    // Part(t): ID of FORD stock / equivalent expression
    cout << ppf[1].id << endl;
    cout << (ppf+1)->id << endl;
    
    // Part(u): IBM Stock.... same thing pretty much
    cout << ppf->id << endl;
    cout << ppf[0].id << endl;

    // Part(v): Six expresssions for "P" in Apple's ticker
    cout << p1.stocks[0].ticker[2] << endl;
    cout << (*&p1).stocks->ticker[2] << endl;
    cout << p1.stocks->ticker[2] << endl;
    cout << (*&p1).stocks[0].ticker[2] << endl;

    *(p1.num_owned + 2) -= 10;

    cout << "\nModified portfolio:\n";
    for (int i(0); i < p1.nstocks; ++i) {
        put_Stock(p1.stocks + i);
        cout << setw(10) << p1.num_owned[i] << '\n';
    }

    delete[] p1.stocks;
    delete[] p1.num_owned;

}

