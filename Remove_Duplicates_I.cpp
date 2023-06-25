#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
void insert_at_tail(Node* &head,Node* &tail,int v){
    Node* newNode = new Node(v);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;
}
void delete_duplicates(Node* &head) {
    if(head==NULL) return;
    Node* tmp=head;
    while(tmp->next!=NULL){
        if(tmp->val==tmp->next->val){
            tmp->next = tmp->next->next;
        }
        if(tmp->next==NULL) break;
        else if(tmp->val!= tmp->next->val){
            tmp=tmp->next;
        }
    }
}
void sort_list(Node* &head){
    Node* tmp1=head;
    Node* tmp2=NULL;
    while(tmp1->next!=NULL){
        tmp2=tmp1->next;
        for(Node* i=tmp2;tmp2!=NULL;tmp2=tmp2->next){
            if(tmp1->val>tmp2->val){
                swap(tmp1->val,tmp2->val);
            }
        }
        tmp1=tmp1->next;
    }
}
void print(Node* head){
    Node* tmp = head;
    while(tmp!=NULL){
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    while(true){
        int x;
        cin>>x;
        if(x==-1) break;
        insert_at_tail(head,tail,x);
    }
    sort_list(head);
    delete_duplicates(head);
    print(head);
    return 0;
}