// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
private:
    T arr[100];
    int peak;

public:
    TStack() :peak(-1) { }
    T get() const {
        return arr[peak];
    }
    void pop() {
        if (!isEmpty())
            peak--;
    }
    void push(T value) {
        if (isFull())
            throw "Full!!!";
        else
            arr[++peak] = value;
    }
    //пустой
    bool isEmpty() const {
        return peak == -1;
    }
    //переполненный
    bool isFull() const {
        return peak == size - 1;
    }
};
#endif  // INCLUDE_TSTACK_H_
