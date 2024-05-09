#include "BinaryTree.h"

void BinaryTree::addInt(int newData)
{
    if (root == nullptr) {
        // если дерево пустое, то новый элемент станет корнем
        root = new Node(newData);
    }
    else {
        Node* current = root; // начинаем с корня
        Node* newNode = nullptr;
        while (newNode == nullptr) {
            if (current->data >= newData) {
                // если элемент меньше текущего, идем влево
                if (current->leftChild != nullptr) {
                    current = current->leftChild;
                    continue;
                }
                // если левого узла нет, то нашли место для нового элемента
                newNode = new Node(newData, current);
                current->leftChild = newNode;
            }
            else {
                // если элемент меньше текущего, идем вправо
                if (current->rightChild != nullptr) {
                    current = current->rightChild;
                    
                }
                // если правого узла нет, то нашли место для нового элемента
                newNode = new Node(newData, current);
                current->rightChild = newNode;
            }
        }
    }
}

void BinaryTree::printHelper(BinaryTree::Node* node)
{
    if (node != nullptr)
    {
        std::cout << "Data: " << node->data;

        if (node->leftChild != nullptr)
            std::cout << " | Left: " << node->leftChild->data;

        if (node->rightChild != nullptr)
            std::cout << " | Right: " << node->rightChild->data;

        std::cout << std::endl;

        printHelper(node->leftChild);
        printHelper(node->rightChild);
    }
}

void BinaryTree::print()
{
    printHelper(root);
    std::cout << std::endl;
}

BinaryTree::Node* BinaryTree::findNodeByData(int finddata)
{
    Node* current = root;

    while (current != nullptr)
    {
        if (finddata == current->data)
            return current;
        else if (finddata < current->data)
            current = current->leftChild;
        else
            current = current->rightChild;
    }

    return nullptr; // Не найдено
}

BinaryTree::Node* BinaryTree::findMin(Node* node)
{
    if (node == nullptr)
        return nullptr;

    while (node->leftChild != nullptr)
        node = node->leftChild;

    return node;
}

BinaryTree::Node* BinaryTree::Delete(Node* root, int data)
{
    if (root == nullptr)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->leftChild = Delete(root->leftChild, data);
        if (root->leftChild != nullptr)
        {
            root->leftChild->parent = root; // Обновляем указатель на родительский узел
            root->leftChild = nullptr; // Устанавливаем leftChild в nullptr
        }
    }
    else if (data > root->data)
    {
        root->rightChild = Delete(root->rightChild, data);
        if (root->rightChild != nullptr)
        {
            root->rightChild->parent = root; // Обновляем указатель на родительский узел
            root->rightChild = nullptr; // Устанавливаем rightChild в nullptr
        }
    }
    else
    {
        // Case 1: No child
        if (root->leftChild == nullptr && root->rightChild == nullptr)
        {
            if (root->parent != nullptr)
            {
                if (root->parent->leftChild == root)
                    root->parent->leftChild = nullptr;
                else
                    root->parent->rightChild = nullptr;
            }

            delete root;
            return nullptr;
        }
        // Case 2: One child
        else if (root->leftChild == nullptr)
        {
            Node* temp = root;
            root = root->rightChild;
            if (root != nullptr)
            {
                root->parent = temp->parent; // Обновляем указатель на родительский узел
                temp->rightChild = nullptr; // Устанавливаем rightChild в nullptr
            }
            delete temp;
        }
        else if (root->rightChild == nullptr)
        {
            Node* temp = root;
            root = root->leftChild;
            if (root != nullptr)
            {
                root->parent = temp->parent; // Обновляем указатель на родительский узел
                temp->leftChild = nullptr; // Устанавливаем leftChild в nullptr
            }
            delete temp;
        }
        // Case 3: 2 Children
        else
        {
            Node* temp = findMin(root->rightChild);
            root->data = temp->data;
            root->rightChild = Delete(root->rightChild, temp->data);
            if (root->rightChild != nullptr)
            {
                root->rightChild->parent = root; // Обновляем указатель на родительский узел
                temp->rightChild = nullptr; // Устанавливаем rightChild в nullptr
            }
        }
    }
    return root;
}

void BinaryTree::delInt(int deldata)
{
    root = Delete(root, deldata);
}
