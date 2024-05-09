#pragma once
#include "Node.h"

class Queue
{
private:
    Node* m_front;
    Node* m_rear;
public:
    Queue() : m_front(nullptr), m_rear(nullptr) {}
    void enQueue(int x);
    void deQueue();
    int peek();
};

