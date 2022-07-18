// 16:14 - 16:40 AC
#include<iostream>
#include<map>
using namespace std;
struct Node{
    int cnt;
    string next;
};
map<string,Node> M;
int main(){
    string s,e;
    int N;
    cin>>s>>e>>N;
    for(int i=0;i<N;i++){
        string t1,t2;
        char c;
        cin>>t1>>c>>t2;
        Node temp;
        temp.cnt = 0;
        temp.next = t2;
        M[t1]=temp;
    }
    while(s!="-1"){
        M[s].cnt=1;
        s=M[s].next;
    }
    while(e!="-1"){
        if(M[e].cnt==1){
            cout<<e;
            return 0;
        }
        e=M[e].next;
    }
    cout<<"-1";
}