
// File: hw2.1.cpp
// Author(s):

#include <iostream>
#include <iomanip>
using namespace std;

   // clist structure definition

struct cl_node {
    char data;
    cl_node *next;
};

// clist creation functions

cl_node *mk_clist_from_Cstring(const char *s)
{
    cl_node *first(nullptr);
    cl_node *last(nullptr);
    for ( ; *s; ++s) {
        cl_node *pnew = new cl_node{*s, nullptr};
        if (!last) {
            last = first = pnew;
        }
        else {
            last = last->next = pnew;
        }
    }
    return first;
}

// clist access functions

size_t clist_size(const cl_node *cl)
{
    size_t size(0);
    for ( ; cl; cl = cl->next)
        size += 1;
    return size;
}

void clist_display_to_cout(const cl_node *cl)
{
    for ( ; cl; cl = cl->next)
        cout << cl->data;
}

// clist element modification functions

void clist_to_uppercase(cl_node *cl)
{
    // assumes ASCII character set
    for ( ; cl; cl = cl->next) {
        if ('a' <= cl->data && cl->data <= 'z') {
            cl->data -= 'a' - 'A';
        }
    }
}

// clist deletion function (a shape modifying function)

void clist_delete(cl_node **p_cl)
{
    while (*p_cl) {
        cl_node *tmp = *p_cl;
        *p_cl = (*p_cl)->next;
        delete tmp;
    }
}

cl_node* mk_copy_clist( cl_node* ptr ) {

    cout << "\n TESTING mk_copy_clist \n" << endl;


    


    cout << "successs" << endl;



    return ptr;

}



int main()
{
    cl_node *bob = mk_clist_from_Cstring("Bob");
    clist_display_to_cout(bob);    // Bob
    cout << '\n';
    cout << "list is " << clist_size(bob) << " chars long\n";
    clist_to_uppercase(bob);
    clist_display_to_cout(bob);    // BOB
    cout << '\n';
    clist_delete(&bob);
    clist_display_to_cout(bob);    // (empty -- no memory leak)


    // code for part (b)

    cl_node *hello = mk_clist_from_Cstring("hello");
    clist_display_to_cout(hello); cout << '\n';  // hello
    cl_node *hello2 = mk_copy_clist(hello);



    /*
    clist_display_to_cout(hello2); cout << '\n'; // hello
    clist_to_uppercase(hello2);
    clist_display_to_cout(hello); cout << '\n';  // hello
    clist_display_to_cout(hello2); cout << '\n'; // HELLO
    clist_delete(&hello);
    clist_delete(&hello2);
    clist_display_to_cout(hello);  // (empty)
    clist_display_to_cout(hello2); // (empty)

    */

    /* code for part (c)

    string s("howdy");
    cl_node *howdy = mk_clist_from_string(s);
    clist_display_to_cout(howdy); cout << '\n';  // howdy
    clist_delete(&howdy);
    clist_display_to_cout(howdy);  // (empty)

    */

    /* code for part (d)

    cl_node *cl = mk_clist_from_Cstring("Bell");
    clist_display_to_cout(cl); cout << '\n';     // Bell
    clist_append_char(&cl, 'a');
    clist_display_to_cout(cl); cout << '\n';     // Bella
    clist_delete(&cl);
    clist_display_to_cout(cl);                   // (empty)
    clist_append_char(&cl, 'X');
    clist_display_to_cout(cl); cout << '\n';     // X
    clist_delete(&cl);
    clist_display_to_cout(cl);                   // (empty)

    */

    /* code for part (e)

    cl_node *cl2 = mk_clist_from_Cstring("Mississippi");
    clist_display_to_cout(cl2); cout << '\n';    // Mississippi
    cout << clist_count_char(cl2, 'i') << '\n';  // 4

    */

    /* code for part (f)

    clist_display_to_cout(cl2); cout << '\n';    // Mississippi
    clist_delete_dups(&cl2);
    clist_display_to_cout(cl2); cout << '\n';    // Misisipi
    clist_delete(&cl2);
    clist_display_to_cout(cl2); cout << '\n';    // (empty)

    */

    /* code for part (g)

    cl_node *cl3 = mk_clist_from_Cstring("national");
    cl_node *cl4 = mk_clist_from_Cstring("ive fic");
    clist_insert_clist(&cl3, cl4, 2);
    clist_display_to_cout(cl3); cout << '\n'; // naive fictional
    clist_display_to_cout(cl4); cout << '\n'; // ive fic
    clist_delete(&cl3);
    clist_delete(&cl4);

    */

    /* code for part (h)

    cl_node *cl5 = mk_empty_clist();
    clist_display_to_cout(cl5); cout << '\n'; // (empty)
    clist_append_char(&cl5, 'h');
    clist_append_char(&cl5, 'i');
    clist_display_to_cout(cl5); cout << '\n'; // hi
    clist_delete(&cl5);

    */

}

