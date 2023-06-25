#include <bits/stdc++.h>
using namespace std;

int main(){
    list<string> myList;
    string add;
    while(true){
        cin>>add;
        if(add=="end") break;
        myList.push_back(add);
    }
    int sz = myList.size();
    int index;
    int q;cin>>q;
    while(q--){
        string cmnd;
        cin>>cmnd;
        if(cmnd=="visit"){
            cin>>add;
            auto it = find(myList.begin(),myList.end(),add);
            it==myList.end()?cout<<"Not Available"<<endl:cout<<add<<endl;
            if(it!=myList.end()){
                index=distance(myList.begin(),it);
            }
        }
        else if(cmnd=="next"){
            if(index==sz-1){
                cout<<"Not Available"<<endl;
            }
            else{
                index=index+1;
                cout<<*next(myList.begin(),index)<<endl;
            }
        }
        else if(cmnd=="prev"){
            if(index==0){
                cout<<"Not Available"<<endl;
            }
            else{
                index=index-1;
                cout<<*next(myList.begin(),index)<<endl;
            }
        }
        else cout<<"Not Available"<<endl;
    }
    return 0;
}

