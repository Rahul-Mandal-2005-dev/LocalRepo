#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class CircularQueues
{
    Node *tail;
    Node *head;

public:
    CircularQueues()
    {
        head = tail = NULL;
    }
    void push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
    void pop()
    {
        Node *temp = head;
        cout<<"Pop: "<< temp->data<<endl;
        head = head->next;
        tail->next = head;
        delete temp;
    }
    void display()
    {
        Node *temp = head;
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << temp->data << endl;
    }
};

int main()
{
    CircularQueues c1;
    c1.push(10);
    c1.push(20);
    c1.push(30);
    c1.push(40);
    c1.push(50);
    c1.display();   
    c1.pop();
    c1.display();   
    return 0;
}
