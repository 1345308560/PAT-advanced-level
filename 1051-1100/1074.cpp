// 9:30 - 10:03 - 25分
#include<iostream>
#include<map>
#include<vector>
#include<stack>
using namespace std;
string beg;
stack<int> St;
vector<int> ans;
int N,K;
map<string,int> M1;
struct Node{
    string address,next;
    int data;
}Nl[100005];
int main(){
    cin>>beg>>N>>K;
    for(int i=0;i<N;i++){
        cin>>Nl[i].address>>Nl[i].data>>Nl[i].next;
        M1[Nl[i].address]=i;
    }
    while(beg!="-1"){
        int id=M1[beg];
        St.push(id);
        if(St.size()>=K){
            while(!St.empty()){
                ans.push_back(St.top());
                St.pop();
            }
        }
        beg=Nl[id].next;
    }
    if(St.size()>0){
        stack<int> temp;
        while(!St.empty()){temp.push(St.top());St.pop();}
        while(!temp.empty()){ans.push_back(temp.top());temp.pop();}
    }
    for(int i=0;i<ans.size();i++){
        if(i<ans.size()-1)
            cout<<Nl[ans[i]].address<<" "<<Nl[ans[i]].data<<" "<<Nl[ans[i+1]].address<<endl;
        else
            cout<<Nl[ans[i]].address<<" "<<Nl[ans[i]].data<<" -1";
    }
}