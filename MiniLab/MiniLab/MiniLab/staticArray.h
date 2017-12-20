#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

#include <iostream>
#include <cassert>

template <class Type>
class staticArrayIterator
{
public:
    staticArrayIterator();
    
    staticArrayIterator(Type* ptr);
    
    Type operator*();
    
    staticArrayIterator<Type> operator++();
    
    bool operator==(const staticArrayIterator<Type>& right) const;
    bool operator!=(const staticArrayIterator<Type>& right) const;
    
private:
    Type *mainPtr;
};

template <class Type>
staticArrayIterator<Type>::staticArrayIterator() {
    mainPtr = NULL;
}

template <class Type>
staticArrayIterator<Type>::staticArrayIterator(Type* ptr) {
    mainPtr = ptr;
}

template <class Type>
Type staticArrayIterator<Type>::operator*() {
    return *mainPtr;
}

template <class Type>
staticArrayIterator<Type> staticArrayIterator<Type>::operator++() {
    mainPtr = ++mainPtr;
    return *this;
}

template <class Type>
bool staticArrayIterator<Type>::operator==
(const staticArrayIterator<Type>& right) const {
    return (mainPtr == right.mainPtr);
}

template <class Type>
bool staticArrayIterator<Type>::operator!=
(const staticArrayIterator<Type>& right) const {
    return (mainPtr != right.mainPtr);
}



template <class Type>
class staticArray
{
public:
    // default constructor
    // set all 10 values to 0
    staticArray();
    
    // set static array
    // parameters:
    //  position -> where in the static array
    //  value -> value inbetween 0 -> 100 to input
    void setStaticArray(int position, const Type value);
    
    // returns first element
    staticArrayIterator<Type> beginStaticArray();
    
    // returns last element
    staticArrayIterator<Type> endStaticArray();
    
private:
    static const int MAX = 10;
    Type array[MAX];
};

template <class Type>
staticArray<Type>::staticArray() {
    for (int i = 0; i < MAX; i++) {
        array[i] = 0;
    }
}

template <class Type>
void staticArray<Type>::setStaticArray(int position, const Type value) {
    if (position >= 0 && position < 10) {
        if (value >= 0 && value < 101){
            array[position] = value;
        } else {
            std::cout << "Value out of range" << std::endl;
        }
    } else {
        std::cout << "Position out of range" << std::endl;
    }
}

template <class Type>
staticArrayIterator<Type> staticArray<Type>::beginStaticArray() {
    Type *firstArray = &(array[0]);
    staticArrayIterator<Type> begin(firstArray);
    return begin;
}

template <class Type>
staticArrayIterator<Type> staticArray<Type>::endStaticArray() {
    Type *endArray = &(array[MAX-1]);
    staticArrayIterator<Type> end(endArray);
    return end;
}

#endif
