#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *link;
} *top= NULL;

void push (int no) {
    Node *p= new Node;
    p->data= no;
    if (top== NULL)
        top=p;
    else {
        p->link=top;
        top=p;
    }
}

void pop () {
    Node *temp;
    if (top== NULL)
        cout<<"Stack underflow "<<endl;
    else {
        temp= top;
        cout<<top->data<<" is popped "<<endl;
        top= top->link;
        delete temp;
    }
}

void display() {
    Node *temp;
    if(top== NULL)
        cout<<"Stack underflow "<<endl;
    else {
        temp= top;
        while (temp!=NULL) {
            cout<<temp->data<<endl;
            temp=temp->link;
        }
    }
}

int main() {
    int ch, no, con;
    do {
        cout<<"Choose one: \n1. Display \n2. Push \n3. Pop\n";
        cin>>ch;
        switch(ch) {
            case 1: display();
                    break;
            case 2: cout<<"Enter number ";
                    cin>>no;
                    push(no);
                    cout<<"Push successful \n";
                    break;
            case 3: pop();
                    break;
        }
        cout<<"Continue? (0/1) ";
        cin>>con;
    } while(con==1);
    return 0;
}
