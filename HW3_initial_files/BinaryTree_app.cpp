
//
// File: BinaryTree_app.cpp
// Author(s):
//

// NOTICE THAT NON-STANDARD CLASS HEADER FOLLOWS using DIRECTIVE!!!

#include <iostream>
using namespace std;
#include "BinaryTree.h"


int main()
{
    BinaryTree tree1;

    cout << "tree1 initially contains: [ ";
    tree1.put();
    cout << " ]\n";

    tree1.insert(12);
    tree1.insert(7);
    tree1.insert(-4);
    tree1.insert(13);
    tree1.insert(9);
    tree1.insert(29);
    tree1.insert(12);  // should not be inserted
    tree1.insert(7);   // should not be inserted
    tree1.insert(-4);  // should not be inserted
    tree1.insert(-9);
    tree1.insert(123);
    tree1.insert(22);
    tree1.insert(0);

    cout << "\nTREE1: [ ";
    tree1.put();
    cout << " ]\n";

    // testing .put_to_ostream() method
    cout << "\nTESTING .put_to_ostream() METHOD\n";
    cout << "tree1 contains (using put to ostream): [ ";
    tree1.put_to_ostream(cout);
    cout << " ]\n";

    // Statistical operations
    cout << "\nSTATISTICAL OPERATIONS\n";
    cout << "tree1 min: " << tree1.min() << "\n";
    cout << "tree1 sum: " << tree1.sum() << "\n";
    cout << "tree1 size: " << tree1.size() << "\n";
    cout << "tree1 mean: " << tree1.mean() << "\n";
    cout << "tree1 max: " << tree1.max() << "\n";

    BinaryTree tree2(tree1);

    cout << "\nTREE2: [ ";
    tree2.put();
    cout << " ]\n";

    /*
    // NOTICE how to put " inside of a string literal!
    cout << "\"pretty print\" of tree1:\n";
    tree1.put_pretty();
    cout << "\n";

    cout << "\"pretty print\" of tree2:\n";
    tree2.put_pretty();
    cout << "\n";
    cout << "\ntree1 and tree2 should be identical!\n\n";
    */

    BinaryTree tree3;
    tree3.insert(888);
    tree3.insert(-888);

    /*
    cout << "tree3 initially contains: [ ";
    tree3.put();
    cout << " ]\n";

    tree3 = tree2;
    cout << "after tree3 = tree2, tree3 contains: [ ";
    tree3.put();
    cout << " ]\n";
    */

    // testing .max() method
    cout << "\nTESTING .max() METHOD\n";
    cout << "tree1 max: " << tree1.max() << "\n";

    // part (d)
    BinaryTree tree4;
    tree4.insert(12);  tree4.insert(5);  tree4.insert(30);

    BinaryTree tree5(tree4);

    BinaryTree tree6;
    tree6.insert(30);  tree6.insert(12);  tree6.insert(5);

    // testing .is_identical() method
    cout << "\nTESTING .is_identical() METHOD\n"; 

    if (tree4.is_identical(tree5))
        cout << "tree4 and tree5 are identical\n";
    else
        cout << "tree4 and tree5 are NOT identical\n";

    if (tree4.is_identical(tree6))
        cout << "tree4 and tree6 are identical\n";
    else
        cout << "tree4 and tree6 are NOT identical\n";

    // testing overloaded == operator
    cout << "\nTESTING FOR OVERLOADED == OPERATOR\n";
    
    if (tree4 == tree5)
        cout << "tree4 == tree5\n";
    else
        cout << "tree4 != tree5\n";

    if (tree4 == tree6)
        cout << "tree4 == tree6\n";
    else
        cout << "tree4 != tree6\n";

    if (tree4 == tree1)
        cout << "tree4 == tree1\n";
    else
        cout << "tree4 != tree1\n";

    // testing overloaded != operator
    cout << "\nTESTING OVERLOADED != OPERATOR\n";

    if (tree4 != tree5)
        cout << "tree4 != tree5\n";
    else
        cout << "tree4 == tree5\n";

    if (tree4 != tree6)
        cout << "tree4 != tree6\n";
    else
        cout << "tree4 == tree6\n";

    if (tree4 != tree1)
        cout << "tree4 != tree1\n";
    else
        cout << "tree4 == tree1\n";

    // testing overaloaded << operator
    cout << "\nTESTING OVERLOADED << OPERATOR\n";
    cout << "tree1 contains [ " << tree1 << " ]\n";
    cout << "tree2 contains [ " << tree2 << " ]\n";
    cout << "tree3 contains [ " << tree3 << " ]\n";
    cout << "tree4 contains [ " << tree4 << " ]\n";
    cout << "tree5 contains [ " << tree5 << " ]\n";
    cout << "tree6 contains [ " << tree6 << " ]\n";

    // no memory leaks, automagically
    // thanks to destructor!
}

