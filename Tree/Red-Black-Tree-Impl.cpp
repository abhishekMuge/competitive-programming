
#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val)
        : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    //-----------------------------------
    // Left Rotation
    //-----------------------------------
    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;

        if (y->left)
            y->left->parent = x;

        y->parent = x->parent;

        if (!x->parent)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    //-----------------------------------
    // Right Rotation
    //-----------------------------------
    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;

        if (y->right)
            y->right->parent = x;

        y->parent = x->parent;

        if (!x->parent)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;

        y->right = x;
        x->parent = y;
    }

    //-----------------------------------
    // Fix Red-Black violations after insert
    //-----------------------------------
    void fixInsert(Node* node) {
        while (node != root && node->parent->color == RED) {

            Node* parent = node->parent;
            Node* grandparent = parent->parent;

            //-----------------------------------
            // Parent is left child
            //-----------------------------------
            if (parent == grandparent->left) {

                Node* uncle = grandparent->right;

                // Case 1: Uncle is RED
                if (uncle && uncle->color == RED) {
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    grandparent->color = RED;
                    node = grandparent;
                }
                else {
                    // Case 2: Left-Right
                    if (node == parent->right) {
                        node = parent;
                        rotateLeft(node);
                        parent = node->parent;
                    }

                    // Case 3: Left-Left
                    parent->color = BLACK;
                    grandparent->color = RED;
                    rotateRight(grandparent);
                }
            }

            //-----------------------------------
            // Parent is right child
            //-----------------------------------
            else {

                Node* uncle = grandparent->left;

                // Case 1: Uncle is RED
                if (uncle && uncle->color == RED) {
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    grandparent->color = RED;
                    node = grandparent;
                }
                else {
                    // Case 2: Right-Left
                    if (node == parent->left) {
                        node = parent;
                        rotateRight(node);
                        parent = node->parent;
                    }

                    // Case 3: Right-Right
                    parent->color = BLACK;
                    grandparent->color = RED;
                    rotateLeft(grandparent);
                }
            }
        }

        root->color = BLACK;
    }

    //-----------------------------------
    // BST Insert
    //-----------------------------------
    void bstInsert(Node* node) {
        Node* parent = nullptr;
        Node* curr = root;

        while (curr) {
            parent = curr;

            if (node->data < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }

        node->parent = parent;

        if (!parent)
            root = node;
        else if (node->data < parent->data)
            parent->left = node;
        else
            parent->right = node;
    }

    //-----------------------------------
    // Inorder Print
    //-----------------------------------
    void inorder(Node* node) {
        if (!node) return;

        inorder(node->left);

        cout << node->data
             << (node->color == RED ? "(R) " : "(B) ");

        inorder(node->right);
    }

public:
    RedBlackTree() : root(nullptr) {}

    //-----------------------------------
    // Public Insert
    //-----------------------------------
    void insert(int val) {
        Node* node = new Node(val);

        bstInsert(node);
        fixInsert(node);
    }

    //-----------------------------------
    // Display
    //-----------------------------------
    void print() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    RedBlackTree tree;

    int arr[] = {10, 20, 30, 15, 25, 5};

    for (int x : arr)
        tree.insert(x);

    cout << "Inorder Traversal:\n";
    tree.print();

    return 0;
}

