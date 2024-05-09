#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Graph
{
public:
    struct Node {
        Node(string _name) : name(_name), next(nullptr) {}
        string name;
        Node* next;
        ~Node()
        {
            if (next != nullptr)
            {
                delete next;
            }
        }
    };

    Graph()
    {
        root = nullptr;
    }

    ~Graph()
    {
        if (root != nullptr)
            delete root;
    }

    void addName(const string& name);
    void print();
    void findWhoNotFriend();
    void findFriend();

private:
    vector<Node*> nodes;
    Node* root;
};

