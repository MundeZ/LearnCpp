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

    size_t height(NodeAVL* node); // ������� ��� ������ � ������� ���������
    int bfactor(NodeAVL* node); // ������� ����� 
    void fix_height(NodeAVL* node); // ����������� ������
    NodeAVL* rotateRight(NodeAVL* node); // ������� �������
    NodeAVL* rotateLeft(NodeAVL* node); // ������� ������
    NodeAVL* balance(NodeAVL* const node); // ����������� ������
    const NodeAVL* bfs(const int& key); // ����� � ������ (BFS � Breadth-First-Search) 
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

