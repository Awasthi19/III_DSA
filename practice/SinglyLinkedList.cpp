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

void addToMid(Node* &head,Node* &tail,int value){
    Node* temp=head;
    while (temp!=NULL){
        if(temp->data==value){
            Node* newNode = new Node(value);
            newNode->next=temp->next;
            temp->next=newNode;
            return;
        }
        temp=temp->next;
    }
    
}

void deleteNode(Node* &head, Node* &tail, int value) {
    // Handle the case where the list is empty
    if (head == nullptr) {
        std::cout << "List is empty. Cannot delete " << value << std::endl;
        return;
    }

    // Handle the case where the node to delete is the head
    if (head->data == value) {
        Node* toDelete = head;
        head = head->next;
        if (toDelete == tail) { // If it was the only node in the list
            tail = nullptr;
        }
        delete toDelete;
        std::cout << value << " removed from the list." << std::endl;
        return;
    }

    // Search for the node to delete
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }

    // If the node was not found in the list
    if (current == nullptr) {
        std::cout << value << " not found in the list." << std::endl;
        return;
    }

    // Unlink the node from the list
    prev->next = current->next;
    if (current == tail) { // If it was the last node
        tail = prev;
    }
    delete current;

    std::cout << value << " removed from the list." << std::endl;
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


//searching a value in the list
bool searchList(Node* &head,int value){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==value){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

//retrieving a value from the list at a specific position
int retrieveData(Node* &head,int position){
    Node* temp=head;
    int count=1;
    while(count<position){
        count++;
        temp=temp->next;
    }
    return temp->data;
}

//traversing and printing the list
void printList(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
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
    deleteNodeAtPosition(head,tail,4);
    cout<<"| After deleting at  :     ";
    printList(head);
    addToTail(tail,12);
    cout<<"| After adding to tail:    ";
    printList(head);
    cout<<"----------------------------------------------\n";
    return 0;
}




