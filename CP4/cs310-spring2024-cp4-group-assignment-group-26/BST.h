#pragma once
#ifndef BST_H
#define BST_H
#include "Node.h"
#include <string>
using namespace std;

class BST{
    private:
        Node* root;
        bool remove(Node*& root, string title);
        void clearTree(Node*& root);

    public:
        BST();
        ~BST();
        Node* insert(string& key, int& index);
        bool remove(string title);
        Node* search(string key);

        void inorder();

};

#endif