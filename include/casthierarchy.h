#include "stdinc.h"
#include "type.h"

constexpr void insert_node(Node* root, Node* ins){
    if (root->val > ins->val) {
        if (root->left) {
            insert_node(root->left, ins);
        } else {
            root->left = ins;
        }
    } else {
        if (root->right) {
            insert_node(root->right, ins);
        } else {
            root->right = ins;
        }
    }
};

Node CastTree[] = {11, 4, 50, 3, 2, 8, 99, 12, 6, 10};
struct Node {
    constexpr Node(int val) : left(nullptr), right(nullptr), val(val) {
        if (CastTree != this) {
            insert_node(CastTree, this);
        }
    }
    Node *left;
    Node *right;
    int val;
};

void helper(Node* t, uint tab){
    std::cout << t->val << std::endl;
}

void printCastTree(Node* tree){
}