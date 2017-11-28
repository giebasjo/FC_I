
//
// File: BinaryTree.cpp
// Author(s):
//
 
#include <iostream>
#include <cfloat>
using namespace std;
#include "BinaryTree.h"

/* --------- bt_node structure "helper" function declarations -------- */

bt_node *mk_binary_tree_copy(bt_node *top);
void binary_tree_insert_unique(bt_node **ptop, int);
void binary_tree_delete(bt_node **ptop);
void put_binary_tree(bt_node *top);
void put_binary_tree_pretty(bt_node *top);
int binary_tree_min(bt_node *top);
int binary_tree_sum(bt_node *top);
int binary_tree_size(bt_node *top);
double binary_tree_mean(bt_node *top);
int binary_tree_max(bt_node *top);
void put_btree_to_os(bt_node *top, ostream& os);
bool helper_is_identical(bt_node *root, bt_node *other_root);
int make_array(bt_node *node, int arr[], int i);
bool res(int arr1[], int sz1, int arr2[]);

/* --------- the definition of the bt_node structure -------- */

struct bt_node {
    int value;       // the current values
    bt_node *left;   // lower values to the left
    bt_node *right;  // higher values to the right
};

/* --------- BinaryTree member function definitions --------- */
// default constructor
BinaryTree::BinaryTree()
: top(0)
{}

// copy constructor
BinaryTree::BinaryTree(const BinaryTree& other)
: top(mk_binary_tree_copy(other.top))
{
}

// assignment operator
BinaryTree& BinaryTree::operator=(const BinaryTree& other)
{
    if (this == &other)
        return *this;    // assign a tree to itself: nothing to do

    binary_tree_delete(&this->top);  // free the existing nodes

    this->top = mk_binary_tree_copy(other.top);

    return *this;
}

// destructor
BinaryTree::~BinaryTree()
{
    binary_tree_delete(&top);
}

bool res(int arr1[], int sz1, int arr2[])
{

    for (int k{0}; k < sz1; k++) 
    {
        if ( arr1[k] != arr2[k]  )
        {
            return false;
        }
    }

    return true;

}

bool BinaryTree::operator==(const BinaryTree& other)
{
    // retrieve sizes to dynamically store array
    int curr_size = (*this).size();
    const int other_size = other.const_size();

    if ( curr_size != other_size)
    {
        return false;
    }
    else 
    {
        // initialize arrays
        int* curr_arr = new int [curr_size];
        int* other_arr = new int [other_size];

        // make the arrays using the helper function make_array
        int i{0}; int j{0};
        int x = make_array((*this).top, curr_arr, i);
        int y = make_array(other.top, other_arr, j);

        bool result = res(curr_arr, curr_size, other_arr);

        delete [] curr_arr;
        delete [] other_arr;

        return result;
    }

}

void BinaryTree::insert(int value)
{
    binary_tree_insert_unique(&top, value);
}

void BinaryTree::put()
{
    put_binary_tree(top);
}

void BinaryTree::put_pretty()
{
    put_binary_tree_pretty(top);
}

int BinaryTree::min()
{
    return binary_tree_min(top);
}

int BinaryTree::sum()
{
    return binary_tree_sum(top);
}

int BinaryTree::size()
{
    return binary_tree_size(top);
}

double BinaryTree::mean()
{
    return binary_tree_mean(top);
}

int BinaryTree::max()
{
    return binary_tree_max(top);
}

void BinaryTree::put_to_ostream(ostream& os)
{
    put_btree_to_os(top, os);
}

bool BinaryTree::is_identical(const BinaryTree& bt)
{
    return helper_is_identical((*this).top, bt.top);
}


/* --------- functions for interacting with the tree -------- */

// put_binary_tree does NOT change the tree, so we only
// need to pass it a COPY of the top pointer from main
void put_binary_tree(bt_node *top)
{
    if (top) {
        put_binary_tree(top->left);
        cout << top->value << " ";
        put_binary_tree(top->right);
    }
}

void put_binary_tree_pretty_with_indent(bt_node *top, int level)
{
    if (!top)
        return;

    put_binary_tree_pretty_with_indent(top->right, level + 1);
    for (int i(0); i < level; ++i)
        cout << '\t';
    cout << top->value << '\n';
    put_binary_tree_pretty_with_indent(top->left, level + 1);
}

void put_binary_tree_pretty(bt_node *top)
{
    if (!top)
        return;

    put_binary_tree_pretty_with_indent(top, 0);
}

void put_binary_tree_rev(bt_node *top)
{
    if (top) {
        put_binary_tree_rev(top->right);
        cout << top->value << " ";
        put_binary_tree_rev(top->left);
    }
}

int binary_tree_min(bt_node *top)
{
    if (!top)
        return 0;

    int min(top->value);
    for (bt_node *p(top->left); p; p = p->left)
        min = p->value;

    return min;
}

int binary_tree_sum(bt_node *top)
{
    if (!top)
        return 0;

    return binary_tree_sum(top->left)
           + top->value
           + binary_tree_sum(top->right);
}

int binary_tree_size(bt_node *top)
{
    if (!top)
        return 0;

    return binary_tree_size(top->left)
           + 1
           + binary_tree_size(top->right);
}

int helper_const_size(bt_node* top)
{
    if (!top) {
        return 0;
    }

    return helper_const_size(top->left) + helper_const_size(top->right) + 1;
}

int BinaryTree::const_size() const
{

    return helper_const_size(top);

}

double binary_tree_mean(bt_node *top)
{
    if (!top)
        return DBL_MIN;

    return 1.0 * binary_tree_sum(top) / binary_tree_size(top);
}

bt_node *mk_binary_tree_copy(bt_node *top)
{
    if (!top)
        return nullptr;

    return new bt_node{ top->value,
                        mk_binary_tree_copy(top->left),
                        mk_binary_tree_copy(top->right) };
}

// binary_tree_insert_unique DOES change the tree, so we must pass
// in a POINTER to the top pointer.  That is, ptop is a
// pointer-to pointer-to-bt_node.
// (d) MODIFIED TO AVOID DUPLICATE VALUE INSERTS
void binary_tree_insert_unique(bt_node **ptop, int val)
{
    if (*ptop) {  // we are not at the bottom yet
        if (val < (*ptop)->value) // left for <
            binary_tree_insert_unique(&(*ptop)->left, val);
        else if (val > (*ptop)->value)  // right for >
            binary_tree_insert_unique(&(*ptop)->right, val);
    } else {
        *ptop = new bt_node{val, nullptr, nullptr};
    }
}


// binary_tree_delete DOES change the tree (by deleting all
// the individual nodes) so we must pass in a POINTER to the
// top pointer.  That is, ptop is a pointer-to
// pointer-to-bt_node.
void binary_tree_delete(bt_node **ptop)
{
    if (*ptop) {
        binary_tree_delete(&(*ptop)->left);
        binary_tree_delete(&(*ptop)->right);
        delete *ptop;
        *ptop = 0;
    }
}

// binary_tree_max is a accessor, not a mutator. 
// It simply returns the max element from the tree
int binary_tree_max(bt_node *top)
{
    if (!top)
        return 0;

    int max(top->value);
    for (bt_node *p(top->right); p; p = p->right)
        max = p->value;

    return max;
}

void put_btree_to_os(bt_node *top, ostream& os)
{
    if (top) {
        put_binary_tree(top->left);
        os << top->value << " ";
        put_binary_tree(top->right);
    }
}

bool helper_is_identical(bt_node *root, bt_node *other_root)
{

    if ( root == nullptr && other_root == nullptr  ) 
    {
        return true;
    }
    else if ( root != nullptr && other_root != nullptr  ) 
    {
        if ( root->value == other_root->value  ) 
        {
            return (helper_is_identical(root->right, other_root->right) && helper_is_identical(root->left, other_root->left));
        }
        return false;
    }
    else 
    {
        return false;
    }

}

int make_array(bt_node *node, int arr[], int i)
{

    if ( node == nullptr ) {
        return i;
    }

    arr[i] = node->value; i++;
    if (node->left != nullptr)
    {
        i = make_array(node->left, arr, i);
    }
    if (node->right != nullptr)
    {
        i = make_array(node->right, arr, i);
    }

    return i;

}











