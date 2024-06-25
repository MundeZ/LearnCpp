#include "AVL.h"

void AVL::insert(int key) {
    NodeAVL* node = new NodeAVL(key);
    _root = insert(_root, node);
}

NodeAVL* AVL::insert(NodeAVL* root, NodeAVL* const node) {
    if (!root)
        return node;

    if (node->key < root->key)
        root->left = insert(root->left, node);
    else
        root->right = insert(root->right, node);

    return balance(root);
}

NodeAVL* AVL::removemin(NodeAVL* node) {
    if (!node->left) {
        return node->right;
    }

    node->left = removemin(node->left);

    return balance(node);
}

NodeAVL* AVL::findmin(NodeAVL* node) {
    return node->left ? findmin(node->left) : node;
}

void AVL::delete_node(const int& key) {
    _root = delete_node(_root, key);
}

NodeAVL* AVL::delete_node(NodeAVL* node, const int& key) {
    if (!node)
        return nullptr;

    if (key < node->key)
        node->left = delete_node(node->left, key);
    else if (key > node->key)
        node->right = delete_node(node->right, key);
    else //  k == p->key
    {
        NodeAVL* q = node->left;
        NodeAVL* r = node->right;
        node->left = nullptr;
        node->right = nullptr;
        delete node;

        if (!r)
            return q;

        NodeAVL* min = findmin(r);
        min->right = removemin(r);
        min->left = q;
        return balance(min);
    }

    return balance(node);
}

size_t AVL::height(NodeAVL* node) {
    return node ? node->height : 0;
}

int AVL::bfactor(NodeAVL* node) {
    return height(node->right) - height(node->left);
}

void AVL::fix_height(NodeAVL* node) {
    size_t h_left = height(node->left);
    size_t h_right = height(node->right);

    node->height = (h_left > h_right ? h_left : h_right) + 1;
}

NodeAVL* AVL::rotateRight(NodeAVL* node)
{
    NodeAVL* q = node->left;

    node->left = q->right;
    q->right = node;
    fix_height(node);
    fix_height(q);

    return q;
}

NodeAVL* AVL::rotateLeft(NodeAVL* node)
{
    NodeAVL* q = node->right;

    node->right = q->left;
    q->left = node;
    fix_height(node);
    fix_height(q);

    return q;
}

NodeAVL* AVL::balance(NodeAVL* node) {
    // вычисляем правильную высоту для узла
    fix_height(node);

    // Балансируем дерево в зависимости от фактора балансировки
    if (bfactor(node) == 2) {
        if (bfactor(node->right) < 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    if (bfactor(node) == -2) {
        if (bfactor(node->left) > 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // балансировка не нужна
    return node;
}

const NodeAVL* AVL::bfs(const int& key) {
    if (_root == nullptr) {
        return nullptr;
    }

    std::queue<NodeAVL*> q;

    q.push(_root);

    while (!q.empty()) {
        NodeAVL* node = q.front();
        q.pop();

        if (node->key == key) {
            return node;
        }

        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }

    return nullptr;
}

void AVL::print_data() {
    if (_root == nullptr) {
        std::cout << "Tree is empty" << std::endl;
        return;
    }

    std::queue<NodeAVL*> q;
    q.push(_root);

    while (!q.empty()) {
        NodeAVL* node = q.front();
        q.pop();

        std::cout << "node key " << node->key << std::endl;

        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
}