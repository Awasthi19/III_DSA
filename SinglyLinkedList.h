#include <iostream>
using namespace std;
class Node {
    public:
        int data;
        Node *next;

        Node(int value) {
            data = value;
            next = nullptr;
        }

};
void addToHead(Node* &head,int value){
    Node* temp = new Node(value);
    temp->next = head;
    head=temp;
}
void removeFromHead(Node* &head){
    Node* temp=head;
    head=head->next;
    temp->next=nullptr;
    delete temp;
    return;
}
void printList(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"    |"<<endl;
}
