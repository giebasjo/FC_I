
// File: hw5.3.cpp
// Author(s):

#include <iostream>
using namespace std;

struct bt_node {
    int value;       // the current values
    bt_node *left;   // lower values to the left
    bt_node *right;  // higher values to the right
};

void put_binary_tree(const bt_node *top)
{
    if (top) {
        put_binary_tree(top->left);
        cout << top->value << " ";
        put_binary_tree(top->right);
    }
}

void binary_tree_insert(bt_node **ptop, int val)
{
    if (*ptop) {  // we are not at the bottom yet
        if (val < (*ptop)->value) // left for less than
            binary_tree_insert(&(*ptop)->left, val);
        else      // right for greater than or equal to
            binary_tree_insert(&(*ptop)->right, val);
    } else {
        *ptop = new bt_node{val, 0, 0};
    }
}

void binary_tree_delete(bt_node **ptop)
{
    if (*ptop) {
        if ((*ptop)->left)
            binary_tree_delete(&(*ptop)->left);
        if ((*ptop)->right)
            binary_tree_delete(&(*ptop)->right);
        delete *ptop;
        *ptop = 0;
    }
}

bool binary_tree_is_empty(const bt_node *top)
{
    return top == 0;    // or top == nullptr;
}

int binary_tree_min(const bt_node *top)
{
    if (binary_tree_is_empty(top))
        return 0;      // a reasonable default?
    for ( ; top->left; top = top->left)
        ;
    return top->value;
}

int main()
{
    bt_node *top = 0;  // tree, initially empty

    binary_tree_insert(&top, 12);  // why &top?
    binary_tree_insert(&top, 7);
    binary_tree_insert(&top, -4);
    binary_tree_insert(&top, 13);
    binary_tree_insert(&top, 9);
    binary_tree_insert(&top, 29);

    put_binary_tree(top);
    cout << "\n";

    cout << "Is binary tree empty? ";
    if (binary_tree_is_empty(top)) {
        cout << "yes!\n";
    }
    else {
        cout << "no\n";
    }

    cout << "Minimum value in binary tree is: " << binary_tree_min(top) << "\n";

    /* code for part (b)
    cout << "binary tree values in reverse:\n";
    put_binary_tree_rev(top);
    cout << '\n';
    */

    /* code for part (c)
    cout << boolalpha;
    cout << "binary tree contains 13: "
         << binary_tree_contains(top, 13) << '\n';
    cout << "binary tree contains -7: "
         << binary_tree_contains(top, -7) << '\n';
    */

    /* code for part (d)
    cout << "pretty binary tree:\n";
    put_binary_tree_pretty(top);
    */

    /* code for first half of part (e)
    cout << "three more 7s:\n";
    binary_tree_insert(&top, 7);
    binary_tree_insert(&top, 7);
    binary_tree_insert(&top, 7);
    put_binary_tree_pretty(top);
    */

    /* code for second half of part (e)
    cout << "new tree, unique values:\n";
    bt_node *top2 = nullptr;
    binary_tree_insert_unique(&top2, 7);
    binary_tree_insert_unique(&top2, 4);
    binary_tree_insert_unique(&top2, 12);
    binary_tree_insert_unique(&top2, 7);
    binary_tree_insert_unique(&top2, 7);
    binary_tree_insert_unique(&top2, 9);
    binary_tree_insert_unique(&top2, 9);
    binary_tree_insert_unique(&top2, 12);
    binary_tree_insert_unique(&top2, 12);
    binary_tree_insert_unique(&top2, 4);
    binary_tree_insert_unique(&top2, 2);
    binary_tree_insert_unique(&top2, 2);
    put_binary_tree_pretty(top2);

      // code for part (f)
      // bt_node *top3 = nullptr;
      // cout << "top size: " << binary_tree_size(top) << "\n";
      // cout << "top2 size: " << binary_tree_size(top2) << "\n";
      // cout << "top3 size: " << binary_tree_size(top3) << "\n";

      // code for part (g)
      // cout << "top sum: " << binary_tree_sum(top) << "\n";
      // cout << "top2 sum: " << binary_tree_sum(top2) << "\n";
      // cout << "top3 sum: " << binary_tree_sum(top3) << "\n";

      // code for part (h)
      // cout << "top mean: " << binary_tree_mean(top) << "\n";
      // cout << "top2 mean: " << binary_tree_mean(top2) << "\n";
      // cout << "top3 mean: " << binary_tree_mean(top3) << "\n";

      // code for part (i)
      // binary_tree_delete_value(&top, 7);
      // binary_tree_delete_value(&top2, 7);
      // cout << "top with 7 deleted:\n";
      // put_binary_tree_pretty(top);
      // cout << "top2 with 7 deleted:\n";
      // put_binary_tree_pretty(top2);
      // 
      // binary_tree_delete(&top3);  // properly deallocate top3


    binary_tree_delete(&top2);
    */

    binary_tree_delete(&top);  // no memory leaks!
}

