
//
// File: BinaryTree.h
// Author(s):
//

/* --------- the definition of the BinaryTree class -------- */

/* THIS IS ALL THAT APPLICATION WRITERS GET TO SEE ABOUT BinaryTree */

struct bt_node;      // we promise this exists somewhere!

class BinaryTree {
public:
    BinaryTree();
    BinaryTree(const BinaryTree&);
    BinaryTree& operator=(const BinaryTree&);
    ~BinaryTree();
    void insert(int);
    void put();
    void put_pretty();
    int min();
    int sum();
    int size();
    double mean();
private:
    bt_node *top;
};
