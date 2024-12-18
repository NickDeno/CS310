#ifndef Array_H
#define Array_H
#include<iostream>
using namespace std;

template <typename T>
class Array{
    public:
        T *arr;
        int limit;
        int length;

        Array();
        ~Array();
        int insert(T val);
        void remove(int index);
        void resize();
        int size();
        void sort();
        T& at(int i);
        
};

template <typename T>
Array<T>::Array(){
    length = 0;
    limit = 10;
    arr = new T[limit];
}

template <typename T>
Array<T>::~Array(){
    delete arr;
}

template <typename T>
int Array<T>::insert(T val){
    if(length == limit){
        this->resize();
    }
    arr[length] = val;
    this->sort();
    return length++;
}

template <typename T>
void Array<T>::remove(int index){
    if (index >-1 && index < length){
        arr[index] = arr[length-1];
        length--;
    }
    T* temparr = new T[limit];
    for (int i=0; i < length; i++){
        temparr[i] = arr [i];
    }
    delete[] arr;
    arr = temparr;  
}

template <typename T>
T& Array<T>::at(int i){
    return arr[i];
}

template <typename T>
int Array<T>::size(){
    return length;
}

template <typename T>
void Array<T>::resize(){
    T* resize_arr = new T[limit*2];
    for(int i = 0; i < limit; i++){
        resize_arr[i] = arr[i];
    }
    limit*=2;
    delete[] arr;
    arr = resize_arr;    
}

template <typename T>
void Array<T>::sort(){
    for (int i = length-1; i > 0; i--){
        if(arr[i] < arr[i-1]){
            T temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
            
        }
    }
    return;
}


#endif
