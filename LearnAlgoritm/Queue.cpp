#include "Queue.h"

void Queue::enQueue(int x) // добавление в конец очереди
{
    Node* temp = new Node(x);

    if (m_rear == nullptr) {
        m_front = m_rear = temp;
        return;
    }

    m_rear->m_next = temp;
    m_rear = temp;
}

void Queue::deQueue() // Удаление с конца очереди
{
    if (m_front == nullptr)
    {
        return;
    }
    Node* temp = m_front;
    m_front = m_front->m_next;
    if (m_front == nullptr)
    {
        m_rear == nullptr;
    }
    delete temp;
}

int Queue::peek()
{
    if (m_front == nullptr)
    {
        return 0;
    }
    return m_front->m_data;
}