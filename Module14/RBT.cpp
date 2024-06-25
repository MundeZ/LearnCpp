#include "RBT.h"
#include <algorithm>

RBT::RBT() : _root(nullptr) {}

RBT::~RBT() {
    deleteTree(_root);
}

void RBT::deleteTree(Node* node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void RBT::insert(int key) {
    Node* z = new Node(key);
    insert(_root, z);
}

void RBT::insert(Node* root, Node* node) {
    Node* currentNode = root;
    Node* parentNode = nullptr;

    while (currentNode != nullptr) {
        parentNode = currentNode;
        if (node->key > currentNode->key)
            currentNode = currentNode->right;
        else
            currentNode = currentNode->left;
    }
    node->parent = parentNode;

    if (parentNode != nullptr) {
        if (node->key > parentNode->key)
            parentNode->right = node;
        else
            parentNode->left = node;
    }
    else {
        root = node;
    }

    node->color = Red;
    InsertFixUp(root, node);
}

void RBT::InsertFixUp(Node*& root, Node* node) {
    Node* parent;
    parent = node->parent;

    while (node != RBT::_root && parent->color == Red) {
        Node* gparent = parent->parent;
        if (gparent->left == parent) {
            Node* uncle = gparent->right;
            if (uncle != nullptr && uncle->color == Red) {
                parent->color = Black;
                uncle->color = Black;
                gparent->color = Red;
                node = gparent;
                parent = node->parent;
            }
            else {
                if (parent->right == node) {
                    leftRotate(root, parent);
                    std::swap(node, parent);
                }
                rightRotate(root, gparent);
                gparent->color = Red;
                parent->color = Black;
                break;
            }
        }
        else {
            Node* uncle = gparent->left;
            if (uncle != nullptr && uncle->color == Red) {
                gparent->color = Red;
                parent->color = Black;
                uncle->color = Black;
                node = gparent;
                parent = node->parent;
            }
            else {
                if (parent->left == node) {
                    rightRotate(root, parent);
                    std::swap(parent, node);
                }
                leftRotate(root, gparent);
                parent->color = Black;
                gparent->color = Red;
                break;
            }
        }
    }
    root->color = Black;
}

Node* RBT::search(int key) {
    return search(_root, key);
}

Node* RBT::search(Node* node, int key) const {
    if (node == nullptr || node->key == key)
        return node;
    else if (key > node->key)
        return search(node->right, key);
    else
        return search(node->left, key);
}

void RBT::remove(int key) {
    Node* deletenode = search(_root, key);
    if (deletenode != nullptr)
        remove(_root, deletenode);
}

void RBT::remove(Node*& root, Node* node) {
    Node* child;
    Node* parent;
    Color color;
    if (node->left != nullptr && node->right != nullptr) {
        Node* replace = node->right;
        while (replace->left != nullptr) {
            replace = replace->left;
        }
        if (node->parent != nullptr) {
            if (node->parent->left == node)
                node->parent->left = replace;
            else
                node->parent->right = replace;
        }
        else {
            root = replace;
        }
        child = replace->right;
        parent = replace->parent;
        color = replace->color;

        if (parent == node) {
            parent = replace;
        }
        else {
            if (child != nullptr)
                child->parent = parent;
            parent->left = child;

            replace->right = node->right;
            node->right->parent = replace;
        }
        replace->parent = node->parent;
        replace->color = node->color;
        replace->left = node->left;
        node->left->parent = replace;
        if (color == Black)
            removeFixUp(root, child, parent);

        delete node;
        return;
    }
    if (node->left != nullptr)
        child = node->left;
    else
        child = node->right;

    parent = node->parent;
    color = node->color;
    if (child) {
        child->parent = parent;
    }
    if (parent) {
        if (node == parent->left)
            parent->left = child;
        else
            parent->right = child;
    }
    else {
        RBT::_root = child;
    }
    if (color == Black && root) {
        removeFixUp(root, child, parent);
    }
    delete node;
}

void RBT::removeFixUp(Node*& root, Node* node, Node* parent) {
    Node* othernode;
    while ((!node) || node->color == Black && node != RBT::_root) {
        if (parent->left == node) {
            othernode = parent->right;
            if (othernode->color == Red) {
                othernode->color = Black;
                parent->color = Red;
                leftRotate(root, parent);
                othernode = parent->right;
            }
            else {
                if (!(othernode->right) || othernode->right->color == Black) {
                    othernode->left->color = Black;
                    othernode->color = Red;
                    rightRotate(root, othernode);
                    othernode = parent->right;
                }
                othernode->color = parent->color;
                parent->color = Black;
                othernode->right->color = Black;
                leftRotate(root, parent);
                node = root;
                break;
            }
        }
        else {
            othernode = parent->left;
            if (othernode->color == Red) {
                othernode->color = Black;
                parent->color = Red;
                rightRotate(root, parent);
                othernode = parent->left;
            }
            else {
                if ((!othernode->left || othernode->left->color == Black) && (!othernode->right || othernode->right->color == Black)) {
                    othernode->color = Red;
                    node = parent;
                    parent = node->parent;
                }
                else {
                    if (!(othernode->left) || othernode->left->color == Black) {
                        othernode->right->color = Black;
                        othernode->color = Red;
                        leftRotate(root, othernode);
                        othernode = parent->left;
                    }
                    othernode->color = parent->color;
                    parent->color = Black;
                    othernode->left->color = Black;
                    rightRotate(root, parent);
                    node = root;
                    break;
                }
            }
        }
    }
    if (node)
        node->color = Black;
}

void RBT::leftRotate(Node*& root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != nullptr) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    }
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RBT::rightRotate(Node*& root, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != nullptr) {
        x->right->parent = y;
    }
}