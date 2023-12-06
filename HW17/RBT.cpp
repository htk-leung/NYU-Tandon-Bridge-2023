/*
INSTRUCTIONS
In this assignment, it is required that you fill out areas under comments 
labeled as "TODO" appropriately based on the accompanying directions. 
You are also required to follow any directions accompanying comments such as "NOTE".
You can add/modify code anywhere, with the exception of the provided "main" (which we will use for testing).
You can use the constants RED and BLACK, instead of the ints 0 and 1, when appropriate.
*/

#include <iostream>
#include <math.h> // for asserting height
#include <queue>
#include <cassert>

using namespace std;

#define RED 0
#define BLACK 1

template <class T>
class RBT;

// swapColor swaps the color from red to black and vice versa
int swapColor(int c) {
    return (c==0)?1:0;
}

template <class T>
class RBTNode {
    RBTNode<T> *parent; 
    RBTNode<T> *left;
    RBTNode<T> *right;
    T data;
    int color;

public:
    RBTNode(T data)
        : data(data),
          color(RED),
          parent(nullptr),
          left(nullptr),
          right(nullptr) {}
    friend class RBT<T>;
    void prettyPrint(int indent) const;

    template <class T1>
    friend void swapColor(RBTNode<T1> *);
    template <class T1>
    friend int getColor(RBTNode<T1> *);

    int height() const;
};

template <class T>
int RBTNode<T>::height() const {
    int left_h = 0;
    if (left != nullptr) {
        left_h = left->height();
    }
    int right_h = 0;
    if (right != nullptr) {
        right_h = right->height();
    }
    return 1 + max(left_h, right_h);
}

template <class T>
void RBTNode<T>::prettyPrint(int indent) const {
    if (right != nullptr) {
        right->prettyPrint(indent + 1);
    }
    int margin = indent * 2;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "DATA: " << data << endl;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;
    if (left != nullptr) {
        left->prettyPrint(indent + 1);
    }
}

template <class T>
void swapColor(RBTNode<T> *node) {
    if (node != nullptr) {
        node->color = swapColor(node->color);
    }
}

// getColor handles null nodes
template <class T>
int getColor(RBTNode<T> *node) {
    if (node != nullptr) {
        return node->color;
    }
    return BLACK;
}

template <class T>
class RBT {
    RBTNode<T> *root;
    void singleCCR(RBTNode<T> *&point);
    void doubleCR(RBTNode<T> *&point);
    void singleCR(RBTNode<T> *&point);
    void doubleCCR(RBTNode<T> *&point);

public:
    RBT() : root(nullptr) {}

    void insert(const T &);
    void insert(const T &, RBTNode<T> *&point, RBTNode<T> *parent);
    void balanceTree(RBTNode<T> *curr_node);
    void prettyPrint() const { root->prettyPrint(0); }

    int height() const { return root->height(); }
};

template <class T>
void RBT<T>::doubleCCR(RBTNode<T> *&point) {
    singleCR(point->right);
    singleCCR(point);
}

template <class T>
void RBT<T>::doubleCR(RBTNode<T> *&point) {
    singleCCR(point->left);
    singleCR(point);
}

template <class T>
void RBT<T>::singleCR(RBTNode<T> *&point) {
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->left;
    // TODO: ADD ROTATION CODE HERE
    grandparent->left = parent->right;                  // rootL = parentR
    if(grandparent->left != nullptr)
        grandparent->left->parent = grandparent;
    
    if(grandparent == root) {
        root = parent;
        parent->parent = nullptr;
    } 
    else {
        if(grandparent->parent->left == grandparent) {  // grantparent-parent-(L / R?) = parent
            grandparent->parent->left = parent;
            parent->parent = grandparent->parent;
        } else {
            grandparent->parent->right = parent;
            parent->parent = grandparent->parent;
        }
    }
    parent->right = grandparent;                        // parentR = grandparent
    grandparent->parent = parent;
}

template <class T>
void RBT<T>::singleCCR(RBTNode<T> *&point) {
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->right;
    // TODO: ADD ROTATION CODE HERE
    grandparent->right = parent->left;                  // rootR = parentL
    if(grandparent->right != nullptr)
        grandparent->right->parent = grandparent;

    if(grandparent == root) {
        root = parent;
        parent->parent = nullptr;
    } else {
        if(grandparent->parent->left == grandparent) {  // grantparent-parent-(L / R?) = parent
            grandparent->parent->left = parent;
            parent->parent = grandparent->parent;
        } else {
            grandparent->parent->right = parent;
            parent->parent = grandparent->parent;
        }
    }
    parent->left = grandparent;                         // parentL = grandparent
    grandparent->parent = parent;
}

template<class T>
void RBT<T>::balanceTree(RBTNode<T> *curr_node) {
    RBTNode<T> *parent = curr_node->parent;
    RBTNode<T> *grandparent = parent->parent;
    RBTNode<T> *uncle;
    // red node red parent
    while(getColor(curr_node->parent) == RED && getColor(curr_node) == RED) { 
        parent = curr_node->parent;
        grandparent = curr_node->parent->parent;

        if(parent == grandparent->left) {               // parent is Left 
            uncle = grandparent->right;                 // uncle

            if(getColor(uncle) == RED) {                // 1. red uncle
                swapColor(parent);
                swapColor(uncle);
                swapColor(grandparent);
                curr_node = grandparent;
            }
            else if(curr_node == parent->left) {        // 2. black uncle A - LL
                singleCR(grandparent);
                swapColor(parent);
                swapColor(grandparent);
                curr_node = parent;   
            }
            else if(curr_node == parent->right) {       // 3. black uncle B = LR
                doubleCR(grandparent);
                swapColor(curr_node);
                swapColor(grandparent);
            }
        }
        else {                                          // parent is right
            uncle = grandparent->left ;                 // uncle is left

            if(getColor(uncle) == RED) {                // 4. red uncle
                swapColor(parent);
                swapColor(uncle);
                swapColor(grandparent);
                curr_node = grandparent;
            }
            else if(curr_node == parent->right) {       // 5. black uncle C - RR
                singleCCR(grandparent);
                swapColor(parent);
                swapColor(grandparent);
                curr_node = parent;   
            }
            else if(curr_node == parent->right) {       // 6. black uncle D = RL
                doubleCCR(grandparent);
                swapColor(curr_node);
                swapColor(grandparent);
            }
        }
          
        if(getColor(root) == RED)
            swapColor(root);
    }
}

template <class T>
void RBT<T>::insert(const T &toInsert, RBTNode<T> *&point, RBTNode<T> *parent) {
    if (point == nullptr) {                             // leaf location is found so insert node
        point = new RBTNode<T>(toInsert);               // modifies the pointer itself since *point
                                                        // is passed by reference
        point->parent = parent;

        RBTNode<T> *curr_node = point;                  // curr_node will be set appropriately when walking up the tree
        // TODO: ADD RBT RULES HERE
        if(point == root) {
            root = point;
            swapColor(root);
        } else {

            if(curr_node->data < parent->data) {        // if smaller, insert left
                parent->left = curr_node;
            } else 
                parent->right = curr_node;              // if data is larger than parent, insert right

            balanceTree(curr_node);
        }
    } else if (toInsert < point->data) {                // recurse down the tree to left to find correct leaf location
        insert(toInsert, point->left, point);
    } else {                                            // recurse down the tree to right to find correct leaf location
        insert(toInsert, point->right, point);
    }
}

template <class T>
void RBT<T>::insert(const T &toInsert) {
    insert(toInsert, root, nullptr);
}

// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int count = 10;
    for (int i = 0; i < count; i++) {
        b.insert(i);
    }
    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */
    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    assert(height <= 2 * log2(count));
    cout<<endl;
    cout<<"---------------------"<<endl;
    cout<<endl;
    RBT<int> c;
    count = 5;
    for (int i = count; i > 0; i--) {
        c.insert(i);
    }
    c.prettyPrint();
    /* EXPECTED OUTPUT:
                    Data: 5
                    COLOR: BLACK
    Data: 4
    COLOR: BLACK
                                    Data: 3
                                    COLOR: RED
                    Data: 2
                    COLOR: BLACK
                                    Data: 1
                                    COLOR: RED
    */
    height = c.height();
    assert(height <= 2 * log2(count));
}