#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class Stack{
    Node* top;
    public:
    Stack(){
        top=NULL;
    }
    void push(int x);
    int pop();
    void Display();
    void peek(int pos);
};
void Stack::push(int x){
    Node*t =new Node();
    if(t==NULL){
cout<<"Stack overflow"<<endl;
    }
    t->data=x;
    t->next=top;
    top=t;
    

}
void Stack::Display(){
    Node* p=top;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
}
int Stack::pop(){
    int x=-1;
    if(top==NULL){
        cout<<"Stack underflow"<<endl;
    }
    else{
        Node* p=top;
        top=top->next;
        x=p->data;
        delete p;
    }
    return x;
}
void Stack::peek(int pos){
    Node* p=top;
    for(int i=0;p!=NULL && i<pos-1;i++){
        p=p->next;
    }
    if(p!=NULL){
        cout<<"Element at position "<<pos<<" is: "<<p->data<<endl;
    }
    else{
        cout<<"Error"<<endl;
    }
}
int man(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.Display();
    cout<<"Popped element is: "<<st.pop()<<endl;
    st.peek(2);
    return 0;
}