#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int value) {
            data = value;
            next = NULL;
        }

};

//traversing the list
void printList(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//adding a node to the head of the list
void addToHead(Node* &head,int value){
    Node* temp = new Node(value);
    temp->next = head;
    head=temp;
}

//adding a node to the tail of the list
void addToTail(Node* &tail,int value){
    Node* temp=new Node(value);
    tail->next=temp;
    tail=temp;//tail=tail->next;
}

//adding a node to the list at a specific position
void addToPosition(Node* &head,Node* &tail,int position,int value){
    //adding to head
    if (position==1){
        addToHead(head,value);
        return;
    }
    Node* temp=head;
    int count=1;
    while(count<position-1){
        count++;
        temp=temp->next;
    }
    //adding to tail
    if(temp->next==NULL){
        addToTail(tail,value);
        return;
    }
    Node* newNode = new Node(value);
    newNode->next=temp->next;
    temp->next=newNode;

}


//deleting a node from the list with position
void deleteNodeAtPosition(Node* &head,Node* &tail,int position){
    //deleting first position
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    //deleting from middle and last
    else{
        Node* curr=head;
        Node* prev=NULL;
        int count=1;
        while(count<position){
            count++;
            prev=curr;
            curr=curr->next;
        }
        if(curr->next==NULL){
            //deleting last node
            prev->next=NULL;
            tail=prev;
            delete curr;
            return;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        
    }
        
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    n1->next=n2;
    Node* n3 = new Node(3);
    n2->next=n3;
    Node* head=n1;
    Node* tail=n3;
    cout<<"----------------------------------------------\n";
    cout<<"| Initial List:            ";
    printList(head);
    addToHead(head,5);
    addToHead(head,4);
    cout<<"| After adding to head:    ";
    printList(head);
    addToTail(tail,9);
    addToTail(tail,10);
    cout<<"| After adding to tail:    ";
    printList(head);
    addToPosition(head,tail,3,25);
    cout<<"| After adding to middle:  ";
    printList(head);
    deleteNodeAtPosition(head,tail,8);
    cout<<"| After deleting at  :     ";
    printList(head);
    addToTail(tail,12);
    cout<<"| After adding to tail:    ";
    printList(head);
    cout<<"----------------------------------------------\n";
    return 0;
}




