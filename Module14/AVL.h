#pragma once
#include <iostream>
#include <queue>

struct NodeAVL {
    int key;
    NodeAVL* left;
    NodeAVL* right;
    size_t height;

    NodeAVL(int k) : key(k), left(nullptr), right(nullptr), height(0) {}
};

class AVL {
public:
    AVL() : _root(nullptr) {}

    size_t height(NodeAVL* node); // обертка для работы с пустыми деревьями
    int bfactor(NodeAVL* node); // разница высот 
    void fix_height(NodeAVL* node); // исправление высоты
    NodeAVL* rotateRight(NodeAVL* node); // Поворот направо
    NodeAVL* rotateLeft(NodeAVL* node); // Поворот налево
    NodeAVL* balance(NodeAVL* const node); // Балансируем дерево
    const NodeAVL* bfs(const int& key); // Поиск в ширину (BFS — Breadth-First-Search) 
    void insert(int key);
    NodeAVL* insert(NodeAVL* root, NodeAVL* const node);
    NodeAVL* removemin(NodeAVL* node);
    NodeAVL* findmin(NodeAVL* node);
    void delete_node(const int& key);
    NodeAVL* delete_node(NodeAVL* node, const int& key);
    void print_data();
private:
    NodeAVL* _root;
};

