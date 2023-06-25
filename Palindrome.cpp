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
void print(Node* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
void reverse(Node* &head, Node *cur){
    if(cur->next==NULL){
        head=cur;
        return;
    }
    reverse(head,cur->next);
    cur->next->next=cur;
    cur->next=NULL;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    while(true){
        int x;cin>>x;
        if(x==-1) break;
        insert_at_tail(head,tail,x);
    }
    Node* tmp = head;
    Node* newHead = NULL;
    Node* newTail = NULL;
    while(tmp!=NULL){
        insert_at_tail(newHead,newTail,tmp->val);
        tmp=tmp->next;
    }
    reverse(newHead,newHead);
    bool flag = false;
    // print(head);
    // print(newHead);
    tmp = head;
    Node* tmp2 = newHead;
    while(tmp!=NULL){
        if(tmp->val!=tmp2->val){
            flag = true;
        }
        tmp=tmp->next;
        tmp2=tmp2->next;
    }
    flag?cout<<"NO":cout<<"YES";
    return 0;
}