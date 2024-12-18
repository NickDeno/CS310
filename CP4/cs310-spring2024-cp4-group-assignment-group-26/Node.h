#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

class Node {
    public:
        string key; // Key is the Song Title
        Node *leftChild;
        Node *rightChild;
        int arrayIndex;
        Node(string k): key(k), leftChild(nullptr), rightChild(nullptr), arrayIndex(-1){};

};

#endif