#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int data){
        this -> data = data;
        this -> next = nullptr;
    }
    
    static void insertAtHead(Node* &head,int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    
    static void insertAtTail(Node* &tail,int data){
        Node* newNode = new Node(data);
        tail -> next = newNode;
        tail = newNode;
    }
    
    static void printLinkedList(Node* &head){
        Node* curr = head;
        while(curr){
            cout << curr -> data << " ";
            curr = curr -> next;
        }
        cout << endl;
        
    }
    
    static void deleteAtHead(Node* &head){
        cout << "Element with value " << head -> data << " is deleted" << endl;
        head = head -> next;
    }
    static void deleteAtTail(Node* &head,Node* &tail){
        Node* curr = head;
        Node* prev = nullptr;
        while(curr->next){
            prev = curr;
            curr = curr -> next;
        }
        tail = prev;
        tail->next = nullptr;
        cout << "Element with value " << curr -> data << " is deleted" << endl;
        
    }
    
    static void deleteMiddleElement(Node* &head,int data){
        Node* curr = head;
        Node* temp = new Node(0);
        Node* prev = temp;
        if(curr->data == data){
            cout << "Element with value " << curr -> data << " is deleted" << endl;
            head = head->next;
            return;
        }
        while(curr->next){
            if(curr -> next -> data == data){
                cout << "Element with value " << curr -> next -> data << " is deleted" << endl;
                temp->next = curr;
                temp = temp->next;
                temp->next = curr->next->next;
                temp = temp->next;
                head = prev->next;
                return;
            }
            temp->next = curr;
            temp = temp -> next;
            curr = curr -> next;
            
        }
        cout << "Element with value " << curr -> data << " is deleted" << endl;
        head = prev->next;
    }
    
    
};

class DoublyNode{
    public:
    int data;
    DoublyNode* prev;
    DoublyNode* next;
    
    DoublyNode(int data){
        this -> data = data;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
    
    static void insertAtHead(DoublyNode* &head,int data){
        DoublyNode* newNode = new DoublyNode(data);
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }
    
    static void insertAtTail(DoublyNode* &tail,int data){
        DoublyNode* newNode = new DoublyNode(data);
        newNode -> prev = tail;
        tail -> next = newNode;
        tail = newNode;
    }
    
    static void printDoublyLinkedList(DoublyNode* &head){
        DoublyNode* curr = head;
        while(curr){
            cout << curr -> data << " ";
            curr = curr -> next;
        }
        cout << endl;
        
    }
    
    static void deleteMiddleElement(DoublyNode* &head,int data){
        DoublyNode* curr = head;
        DoublyNode* temp = new DoublyNode(0);
        DoublyNode* last = temp;
        if(curr -> data == data){
            head = head->next;
            cout << "Element with value " << curr -> data << " is deleted" << endl;
            return;
        }
        
        while(curr -> next){
            if(curr -> next -> data == data){
                DoublyNode* newNext = curr -> next -> next;
                cout << "Element with value " << curr -> next -> data << " is deleted" << endl;
                if(newNext){
                    temp -> next = curr;
                    temp = temp -> next;
                    newNext -> prev = temp;
                    temp -> next = curr -> next -> next;
                    temp = temp -> next;
                }else{
                    temp -> next = curr;
                    temp = temp -> next;
                    temp -> next = curr -> next -> next;
                    temp = temp -> next;
                }
                head = last -> next;
                return;
            }
            temp -> next = curr;
            temp = temp -> next;
            curr = curr -> next;
        }
        head = last -> next;
        cout << "Element with value " << curr -> data << " is deleted" << endl;
    }
};
int main() {
	
	Node* node = new Node(10);
	Node* head = node;
	Node* tail = node;
	
	DoublyNode* node1 = new DoublyNode(20);
	DoublyNode* head1 = node1;
	DoublyNode* tail1 = node1;
	
	node->insertAtHead(head,12);
	node->insertAtHead(head,15);
	node->printLinkedList(head);
	node->insertAtTail(tail,5);
	node->insertAtTail(tail,8);
	node->printLinkedList(head);
	node->deleteAtHead(head);
	node->deleteAtTail(head,tail);
	node->printLinkedList(head);
	node->deleteMiddleElement(head,12);
	node->printLinkedList(head);
	
	
	node1->insertAtHead(head1,12);
	node1->insertAtHead(head1,15);
	node1->printDoublyLinkedList(head1);
	node1->insertAtTail(tail1,5);
	node1->insertAtTail(tail1,8);
	node1->printDoublyLinkedList(head1);
	cout << head1->next->prev->data << "   " << head1->next->next->data << endl;
	
	
	node1->deleteMiddleElement(head1 , 12);
	node1->printDoublyLinkedList(head1);
}
