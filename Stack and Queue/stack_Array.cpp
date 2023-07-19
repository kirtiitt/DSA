#include <iostream>
#define size 50
using namespace std;

int stack[size], top= -1;

void push(int no) {
    if(top== size)
        cout<<"Stack overflow "<<endl;
    else
        stack[++top]= no;
}

void pop() {
    if(top== -1)
        cout<<"Stack underflow "<<endl;
    else
        cout<<stack[top--]<<" is popped "<<endl;
}

void display() {
    if(top== -1)
        cout<<"Stack undeflow "<<endl;
    else {
        int temp= top;
        while(temp>-1)
            cout<<stack[temp--]<<endl;
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
