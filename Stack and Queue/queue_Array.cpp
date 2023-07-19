#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *link;
} *front= NULL, *rear= NULL;

void enqueue (int no) {
    Node *p= new Node;
    p->data=no;
    if(front== NULL)
        front= rear= p;
    else {
        rear->link= p;
        rear= p;
    }
}

void dequeue() {
    Node *temp;
    if(front== NULL)
        cout<<"Queue is empty "<<endl;
    else {
        temp= front;
        cout<<front->data<<" is deleted "<<endl;
        front= front->link;
        delete temp;
    }
}

void display() {
    Node *temp;
    if(front== NULL)
        cout<<"Queue is empty "<<endl;
    else {
        temp= front;
        while(temp!=NULL) {
            cout<<temp->data<<endl;
            temp=temp->link;
        }
    }
}

int main() {
    int ch, no, con;
    do {
        cout<<"Choose one: \n1. Display \n2. Enqueue \n3. Dequeue\n";
        cin>>ch;
        switch(ch) {
            case 1: display();
                    break;
            case 2: cout<<"Enter number ";
                    cin>>no;
                    enqueue(no);
                    cout<<"Insert successful \n";
                    break;
            case 3: dequeue();
                    break;
        }
        cout<<"Continue? (0/1) ";
        cin>>con;
    } while(con==1);
    return 0;
}
