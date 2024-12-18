#ifndef BST_cpp
#define BST_cpp
#include "BST.h"
#include <iostream>

BST::BST() : root(nullptr){};

void BST::clearTree(Node*& root){
    if (root->leftChild) clearTree(root->leftChild);
    if (root->rightChild) clearTree(root->rightChild);
    delete root;
};

BST::~BST(){
    if(root == nullptr){
        return;
    }
    clearTree(root);

}

Node* BST::insert(string& key, int& index){
    if(root == nullptr){
        root = new Node(key);
        root->arrayIndex = index;
        return root;
    }

    Node* currNode = root;
    while(true){
        if(key > currNode->key){    
            if(currNode->rightChild == nullptr){
                currNode->rightChild = new Node(key);
                currNode->rightChild->arrayIndex = index;
                return currNode->rightChild;
            }
            else currNode = currNode->rightChild;
        }
        if(key < currNode->key){   
            if(currNode->leftChild == nullptr){
                currNode->leftChild = new Node(key);
                currNode->leftChild->arrayIndex = index;
                return currNode->leftChild;
            }
            else currNode = currNode->leftChild;
        }
    }
}

bool BST::remove(string key){
    return remove(root, key);
}

bool BST::remove(Node*& root, string key) {
    if (root == nullptr) {
        return false;
    }

    //Node is in left subtree
    if (key < root->key) {
        return remove(root->leftChild, key);
    //Node is in right subtree
    } else if (key > root->key) {
       return remove(root->rightChild, key);
    //Node was found
    } else {
        //Node has no children
        if(root->leftChild == nullptr && root->rightChild == nullptr){
            delete root;
            root = nullptr;
        // Node has two children
        } else if (root->leftChild != nullptr && root->rightChild != nullptr) {
            Node* sucessorNode = root->leftChild;
            while (sucessorNode && sucessorNode->rightChild != nullptr) {
                sucessorNode = sucessorNode->rightChild;
            }
            root->key = sucessorNode->key;
            root->arrayIndex = sucessorNode->arrayIndex;
            return remove(root->rightChild, sucessorNode->key);
        //Node with only one child
        } else {
            Node* child = (root->leftChild != nullptr) ? root->leftChild : root->rightChild;
            Node* temp = root;
            root = child;
            delete temp;
        }
    }
    return root;
}

Node* BST::search(string key){
    Node* currNode = root;
    while(currNode != nullptr){
        if(key > currNode->key){
            currNode = currNode->rightChild;
        } else if(key < currNode->key){
            currNode = currNode->leftChild;
        } else if (key == currNode->key){
            return currNode;
        }
    }
    return nullptr;
}

void inorderRec(Node* root) {
    if (root != nullptr) {
        inorderRec(root->leftChild);
        cout << root->key << endl;
        inorderRec(root->rightChild);
    }
}

#endif