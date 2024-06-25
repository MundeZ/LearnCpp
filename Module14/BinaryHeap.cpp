#include "BinaryHeap.h"


void BinaryHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    // провер€ем свойство дл€ левого поддерева
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;

    // провер€ем свойство дл€ правого поддерева
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;

    // если не выполнено, обмениваем, с родителем
    // вызываем снова дл€ индекса, не удовлетвор€ющего условию
    if (smallest != i)
    {
        std::swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}