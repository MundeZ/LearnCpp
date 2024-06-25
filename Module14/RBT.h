#pragma once

enum Color { Black, Red };

struct Node {
    int key;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int k) : key(k), color(Red), parent(nullptr), left(nullptr), right(nullptr) { }
};

class RBT {
public:
    RBT();
    ~RBT();
    void insert(int key);
    Node* search(int key);
    void remove(int key);

private:
    void insert(Node* root, Node* node);
    void InsertFixUp(Node*& root, Node* node);
    Node* search(Node* node, int key) const;
    void remove(Node*& root, Node* node);
    void removeFixUp(Node*& root, Node* node, Node* parent);
    void leftRotate(Node*& root, Node* x);
    void rightRotate(Node*& root, Node* y);
    void deleteTree(Node* node);

    Node* _root;
};
