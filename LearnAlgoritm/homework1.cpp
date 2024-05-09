#include "homework1.h"


void Graph::addName(const string& name)
{
    Node* newNode = new Node(name);

    if (root == nullptr)
    {
        root = newNode;
    }
    else
    {
        Node* lastNode = root;
        while (lastNode->next != nullptr)
        {
            lastNode = lastNode->next;
        }

        lastNode->next = newNode;
    }
}

void Graph::findWhoNotFriend()
{   
    if (root != nullptr)
    {
        Node* currentNode = root;
        while (currentNode != nullptr)
        {
            Node* secondNode = currentNode->next->next->next->next;
            if (secondNode != nullptr)
            {
                cout << currentNode->name << " не знаком с: " << secondNode->name << endl;
            }
            else break;
            currentNode = currentNode->next;
        }
        cout << endl;
    }
}

void Graph::findFriend()
{
    if (root != nullptr)
    {
        Node* currentNode = root;
        while (currentNode != nullptr)
        {
            Node* secondNode = currentNode->next;
            Node* thirdNode = currentNode->next->next;
            Node* fourthNode = currentNode->next->next->next;
            cout << currentNode->name << " знаком с: ";
            if (secondNode != nullptr)
            {
                cout << secondNode->name << " ";
                if (thirdNode != nullptr)
                {
                    cout << thirdNode->name << " ";
                    if (fourthNode != nullptr)
                    {
                        cout << fourthNode->name << " ";
                    }
                    else break;
                }
                else break;
            }
            else break;
            cout << endl;
            currentNode = currentNode->next;
        }
    }
}

void Graph::print()
{
    if (root != nullptr)
    {
        cout << root->name << endl;  

        Node* currentNode = root->next;
        while (currentNode != nullptr)
        {
            cout << currentNode->name << endl;  
            currentNode = currentNode->next;
        }
    }
}