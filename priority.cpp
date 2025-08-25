#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    int priority;
    Node *next;
};

class Priority
{
    Node *head;

public:
    Priority()
    {
        head =NULL;
    }
    void push(int value, int pri)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->priority = pri;
        newNode->next = NULL;

        if (head == NULL || pri < head->priority)
        {
            Node *temp = head;
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL && temp->next->priority <= pri)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void display()
    {
        Node*temp = head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main()
{
    Priority p1;
    p1.push(10,2);
    p1.push(20,1);
    p1.push(30,4);
    p1.push(40,3);
    p1.display();
    return 0;
}