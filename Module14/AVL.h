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

    size_t height(Node* node); // ������� ��� ������ � ������� ���������
    int bfactor(Node* node); // ������� ����� 
    void fix_height(Node* node); // ����������� ������
    Node* rotateRight(Node* node); // ������� �������
    Node* rotateLeft(Node* node); // ������� ������
    Node* balance(Node* const node); // ����������� ������
    const Node* bfs(const int& key); // ����� � ������ (BFS � Breadth-First-Search) 
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

