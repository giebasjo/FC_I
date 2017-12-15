
// File: hw4.1.cpp
// Authors:

#include <iostream>
#include <vector>              // an improved dynamic array
#include <forward_list>        // singly linked list
#include <list>                // doubly linked list
#include <stack>               // stack
#include <queue>               // queue and priority_queue
#include <set>                 // self-balanced binary search tree (red-black or similar)
#include <unordered_set>       // hash table
#include <ctime>               // time(), time_t
using namespace std;

//////////////////////////
// c
//////////////////////////
void display_int_vector(const vector<int>& rvi){
	cout << "The vector contains " << rvi.size() << " elements\n";
	for (int i(0); i < rvi.size(); ++i)
		cout << rvi[i] << ' ';
	cout << '\n';
}


//////////////////////////
// e
//////////////////////////

size_t flc_size(forward_list<char>& ll) {
	
	size_t temp = 0;
	for (auto it = ll.begin(); it != ll.end(); ++it)
		temp++;
	return temp;
}

int main()
{
    // part (a)
	cout << "____________PART A____________\n";
    cout << "hello, world\n";

    
    // part (b)
	cout << "____________PART B____________\n";
    vector<int> v1;   // empty vector-of-int

    v1.push_back(3);
    cout << "v1 contains " << v1.size() << " elements\n";
    for (int i(0); i < v1.size(); ++i)
        cout << v1[i] << ' ';
    cout << '\n';

    v1.push_back(-7);
    v1.push_back(0);
    v1.push_back(9);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(6);
    cout << "v1 contains " << v1.size() << " elements\n";
    for (int i(0); i < v1.size(); ++i)
        cout << v1[i] << ' ';
    cout << '\n';

    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    cout << "v1 contains " << v1.size() << " elements\n";
    for (int i(0); i < v1.size(); ++i)
        cout << v1[i] << ' ';
    cout << '\n';

    v1.push_back(-2);
    v1.push_back(5);
    v1.push_back(1);
    cout << "v1 contains " << v1.size() << " elements\n";
    for (int *pi = &v1[0]; pi < &v1[0] + v1.size(); ++pi)
        cout << *pi << ' ';
    cout << '\n';
    

    // part (c)
	cout << "____________PART C____________\n";
    v1.push_back(3);
    v1.push_back(13);
    v1.push_back(6);
    display_int_vector(v1);

    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    display_int_vector(v1);


	// part (d)
	cout << "____________PART D____________\n";
    forward_list<char> fl1;  // empty forward_list-of-char

    fl1.push_front('n');
    fl1.push_front('o');
    fl1.push_front('s');
    fl1.push_front('s');
    fl1.push_front('e');
    fl1.push_front('l');
    cout << "fl1 contains: ";
    for (auto it = fl1.begin(); it != fl1.end(); ++it)
        cout << *it;
    cout << '\n';

    fl1.pop_front();
    fl1.pop_front();
    fl1.pop_front();
    fl1.pop_front();
    cout << "fl1 contains: ";
    for (auto it = fl1.begin(); it != fl1.end(); ++it)
        cout << *it;
    cout << '\n';
    

    // part (e)
	cout << "____________PART E____________\n";
    fl1.push_front('r');
    fl1.push_front('T');
    cout << "fl1 contains "
         << flc_size(fl1) << " characters:\n";
    for (auto it = fl1.begin(); it != fl1.end(); ++it)
        cout << *it;
    cout << '\n';

    
    // part (f)
	cout << "____________PART F____________\n";
    list<char> lc1;  // empty list-of-char

    lc1.push_front('a');
    lc1.push_back('l');
    lc1.push_front('i');
    lc1.push_front('d');
    lc1.push_back('o');
    lc1.push_back('g');
    cout << "lc1 contains " << lc1.size() << " chars:\n";
    for (auto it = lc1.begin(); it != lc1.end(); ++it)
        cout << *it;
    cout << '\n';

    lc1.pop_front();
    lc1.pop_front();
    lc1.push_back('y');
    lc1.pop_front();
    lc1.push_front('o');
    lc1.push_front('i');
    lc1.push_front('b');
    cout << "lc1 contains " << lc1.size() << " chars:\n";
    for (auto it = lc1.begin(); it != lc1.end(); ++it)
        cout << *it;
    cout << '\n';
    

    // part (g)
	cout << "____________PART G____________\n";
    stack<int> si1;  // empty stack-of-int
    cout << "si1 contains " << si1.size() << " ints\n";
    cout << "si1 is" << (si1.empty() ? "" : " not")
         << " empty\n";

    for (int i(0); i < 10; ++i)
        si1.push(i);

    cout << "si1 contains " << si1.size() << " ints\n";
    cout << "si1 is" << (si1.empty() ? "" : " not")
         << " empty\n";

    cout << "popping from si1:\n";
    while (!si1.empty()) {
        cout << si1.top() << ' ';
        si1.pop();
    }
    cout << '\n';

    cout << "after pops, si1 contains "
         << si1.size() << " ints\n";
    


    // part (h)
	cout << "____________PART H____________\n";
    queue<int> qi1;  // empty queue-of-int
    cout << "qi1 contains " << qi1.size() << " ints\n";
    cout << "qi1 is" << (qi1.empty() ? "" : " not")
        << " empty\n";

    for (int i(0); i < 10; ++i)
        qi1.push(i);

    cout << "qi1 contains " << qi1.size() << " ints\n";
    cout << "qi1 is" << (qi1.empty() ? "" : " not")
         << " empty\n";

    cout << "popping from qi1:\n";
    while (!qi1.empty()) {
        cout << qi1.front() << ' ';
        qi1.pop();
    }
    cout << '\n';

    cout << "after pops, qi1 contains "
         << qi1.size() << " ints\n";

    

     // part (i)
	cout << "____________PART I____________\n";
    set<int> sti1;  // empty set-of-int
    cout << "sti1 contains " << sti1.size() << " ints\n";
    cout << "sti1 is" << (sti1.empty() ? "" : " not")
        << " empty\n";

    sti1.insert(12);
    sti1.insert(-4);
    sti1.insert(9);
    sti1.insert(17);
    sti1.insert(4);
    sti1.insert(4);  // duplicate ignored
    sti1.insert(8);

    cout << "sti1 contains " << sti1.size() << " ints\n";
    cout << "sti1 is" << (sti1.empty() ? "" : " not")
        << " empty\n";
    for (auto it(sti1.begin()); it != sti1.end(); ++it)
        cout << *it << ' ';
    cout << '\n';

    sti1.erase(12);
    sti1.erase(-4);
    sti1.erase(0);

    cout << "after erases, sti1 contains:\n";
    for (auto it(sti1.begin()); it != sti1.end(); ++it)
        cout << *it << ' ';
    cout << '\n';

    if (sti1.find(9) != sti1.end())
        cout << "9 is found\n";
    if (sti1.find(3) == sti1.end())
        cout << "3 is NOT found\n";
   

    
    // part (j)
	cout << "____________PART J____________\n";
    unordered_set<int> usi1;  // empty unordered_set-of-int
    cout << "usi1 contains " << usi1.size() << " ints\n";
    cout << "usi1 is" << (usi1.empty() ? "" : " not")
        << " empty\n";

    usi1.insert(12);
    usi1.insert(-4);
    usi1.insert(9);
    usi1.insert(17);
    usi1.insert(4);
    usi1.insert(4);  // duplicate ignored
    usi1.insert(8);

    cout << "usi1 contains " << usi1.size() << " ints\n";
    cout << "usi1 is" << (usi1.empty() ? "" : " not")
        << " empty\n";
    for (auto it(usi1.begin()); it != usi1.end(); ++it)
        cout << *it << ' ';
    cout << '\n';

    usi1.erase(12);
    usi1.erase(-4);
    usi1.erase(0);

    cout << "after erases, usi1 contains:\n";
    for (auto it(usi1.begin()); it != usi1.end(); ++it)
        cout << *it << ' ';
    cout << '\n';

    if (usi1.find(9) != usi1.end())
        cout << "9 is found\n";
    if (usi1.find(3) == usi1.end())
        cout << "3 is NOT found\n";
    
    
    // part (k)
    cout << "____________PART K____________\n";



    /* n = 10,000: list_time = 15s, set_time = 4s, uset_time = 0s
       n = 20,000: list_time = 33s, set_time = 5s, uset_time = 0s
       n = 40,000: list_time = 62s, set_time = 6s, uset_time = 0s
       n = 80,000: list_time = 117s, set_time = 7s, uset_time = 0s
       n = 160,000: list_time = 232s, set_time = 8s, uset_time = 0s
       n = 320,000: list_time = 467s, set_time = 9s, uset_time = 0s

    */

        vector<int> nVal_vec;
        vector<time_t> list_timeVec;
        vector<time_t> bst_timeVec;
        vector<time_t> uset_timeVec;

    for ( int i = 1; i <= 10; i++  ) {

    list<int> li2;
    set<int> si2;
    unordered_set<int> usi2;
    int n_values = 10'000*i;
    const int two_n_values = 2 * n_values;
    int n_searches = 100'000;

    nVal_vec.push_back(n_values);

    cout << "n_values: " << n_values
    << ", n_searches: " << n_searches << '\n';

    // insert the same values
    for (int i(0); i < n_values; ++i) {
        li2.push_back(i);
        si2.insert(i);
        usi2.insert(i);
    }

	cout << "searching";

    // search the list<int>
    time_t li2_start = time(0);
    for (int j(0); j < n_searches; ++j) {
        //int val(j % two_n_values);
		int val(j % 2 ? j : 2'000'000'000);
        // we should find about 50% of these computed values
        for (auto it(li2.begin());
                        it != li2.end() && *it != val; ++it)
            ;
            // when we get here, either we found val or
            // val is not in the list
    }
    time_t li2_stop = time(0);
    cout << "list search took " << (li2_stop - li2_start) << " seconds\n";

    list_timeVec.push_back(li2_stop - li2_start);

    // search the set<int>
    time_t si2_start = time(0);
    for (int j(0); j < n_searches; ++j) {
        int val(j % two_n_values);
        // we should find about 50% of these computed values
        auto it = si2.find(val);  // found, or not: don't care
    }
    time_t si2_stop = time(0);
    cout << "set (balanced BST) search took " << (si2_stop - si2_start) << " seconds\n";

    bst_timeVec.push_back(si2_stop-si2_start);

    // search the unorder_set<int>
    time_t usi2_start = time(0);
    for (int j(0); j < n_searches; ++j) {
        int val(j % two_n_values);
        // we should find about 50% of these computed values
        auto it = usi2.find(val);  // found, or not: don't care
    }
    time_t usi2_stop = time(0);
    cout << "set (balanced BST) search took " << (usi2_stop - usi2_start) << " seconds\n";

    uset_timeVec.push_back(usi2_stop-usi2_start);

}


for ( auto indx = 1; indx <= 10; indx++ ) {

    cout << "n: " << nVal_vec[indx] << ", list time: " << list_timeVec[indx] << ", bst time: " << bst_timeVec[indx] 
         << ", unordered set time: " << uset_timeVec[indx] << endl;

}



}
