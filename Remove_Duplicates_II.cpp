#include <bits/stdc++.h>
using namespace std;

int main(){
    list<int> myList;
    while(true){
        int x;cin>>x;
        if(x==-1) break;
        myList.push_back(x);
    }
    myList.sort();
    myList.unique();
    for(int val:myList){
        cout<<val<<" ";
    }
    return 0;
}