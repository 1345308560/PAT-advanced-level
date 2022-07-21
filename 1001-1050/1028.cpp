// 13：41 - 13:48 AC
#include <iostream>
#include <algorithm>
using namespace std;
struct Node{
    string ID,name;
    int grade;
}Nl[100005];
bool cmp1(Node A,Node B){
    return A.ID<B.ID;
}
bool cmp2(Node A,Node B){
    if(A.name!=B.name) return A.name<B.name;
    else return A.ID<B.ID;
}
bool cmp3(Node A,Node B){
    if(A.grade!=B.grade)return A.grade<B.grade;
    else return A.ID<B.ID;
}
int N,C;
int main(){
    cin>>N>>C;
    for(int i=0;i<N;i++){
        cin>>Nl[i].ID>>Nl[i].name>>Nl[i].grade;
    }
    if(C==1)sort(Nl,Nl+N,cmp1);
    else if(C==2)sort(Nl,Nl+N,cmp2);
    else sort(Nl,Nl+N,cmp3);
    for(int i=0;i<N;i++){
        cout<<Nl[i].ID<<" "<<Nl[i].name<<" "<<Nl[i].grade;
        if(i<N-1)cout<<endl;
    }
}