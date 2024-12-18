#pragma once
#ifndef GLL_H
#define GLL_H
#include <iostream>
#include <stdlib.h>
using namespace std;

template<typename T>
class GLL {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    Node* tail;
    Node* current;
    bool contains(const T& value) const;
    
public:
    GLL();
    ~GLL();
    
    bool isEmpty() const;
    bool flush();
    bool prepend(const T& item);
    bool append(const T& item);
    bool merge(GLL &other);
    GLL<T>& operator+=(const GLL<T>& other);
    GLL<T>& operator-=(const GLL<T>& other);
    int purgeGoofy();
    int keepGoofy();
    bool demoteGoofy();
    bool reset();
    bool finished();
    T proceed();
};

#include "GLL.cpp"

#endif // GLL_H
