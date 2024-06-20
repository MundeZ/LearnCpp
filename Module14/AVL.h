#pragma once
#include <iostream>
#include <queue>

struct Node {
    int key;
    Node* left;
    Node* right;
    size_t height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(0) {}
};

class AVL {
public:
    AVL() : _root(nullptr) {}

    size_t height(Node* node); // обертка для работы с пустыми деревьями
    int bfactor(Node* node); // разница высот 
    void fix_height(Node* node); // исправление высоты
    Node* rotateRight(Node* node); // Поворот направо
    Node* rotateLeft(Node* node); // Поворот налево
    Node* balance(Node* const node); // Балансируем дерево
    const Node* bfs(const int& key); // Поиск в ширину (BFS — Breadth-First-Search) 
    void insert(int key);
    Node* insert(Node* root, Node* const node);
    Node* removemin(Node* node);
    Node* findmin(Node* node);
    void delete_node(const int& key);
    Node* delete_node(Node* node, const int& key);
    void print_data();
private:
    Node* _root;
};

