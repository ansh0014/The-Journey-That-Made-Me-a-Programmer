// #include<iostream>
// using namespace std;
// class Node{
// public:
// int data;
// Node* next;
// Node(int value){
//     data=value;
//     next=NULL;

// }
// };
// int main(){
//     Node* head=new Node(10);
//     Node* second =new Node(20);
//     Node* third = new Node(30);
//     head->next=second;
//     second->next=third;
//     Node* temp=head;
//     while(temp!=NULL){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
// }
#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node(int value){
    data=value;
    next=NULL;
}
};
int main(){
    Node*head=new Node(1);
    Node* second=new Node(2);
    Node* third=new Node(3);
    head->next=second;
    second->next=third;
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}