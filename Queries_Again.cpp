#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* prev;
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
int size(Node* &head){
    int cnt = 0;
    Node* tmp = head;
    while(tmp!=NULL){
        cnt++;
        tmp=tmp->next;
    }
    return cnt;
}
void insert_at_list(Node* &head,Node* &tail,int x,int v){
    Node* newNode = new Node(v);
    int sz = size(head);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    else if(x==0){
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        return;
    }
    else if(x==sz){
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
        return;
    }
    else{
        Node* tmp = head;
        for(int i=1;i<=x;i++){
            tmp=tmp->next;
        }
        newNode->next=tmp;
        newNode->prev=tmp->prev;
        tmp->prev->next=newNode;
        tmp->prev=newNode;
        return;
    }
}

void print_left_to_right(Node* &head){
    Node* tmp = head;
    while(tmp!=NULL){
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
}
void print_right_to_left(Node* &tail){
    Node* tmp = tail;
    while(tmp!=NULL){
        cout<<tmp->val<<" ";
        tmp=tmp->prev;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    int q;cin>>q;
    while(q--){
        int x,v;cin>>x>>v;
        int sz = size(head);
        if(x>sz){
            cout<<"Invalid"<<endl;
        }
        else{
            insert_at_list(head,tail,x,v);
            cout<<"L -> ";
            print_left_to_right(head);
            cout<<endl;
            cout<<"R -> ";
            print_right_to_left(tail);
            cout<<endl;
        }
    }

    return 0;
}