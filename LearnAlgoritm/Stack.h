#pragma once
#include <iostream>
#include "Node.h"

#define MAX 1000


class Stack
{
private:
    Node* m_root = nullptr;
public:
    bool Push(int x);
    int Pop();
    int Peek();
    bool IsEmpty();
    void Show();
};

