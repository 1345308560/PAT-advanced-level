//23:18 - 13:27 - 25分
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,g1,g2;
struct Node{
    string name,cls;
    int grade;
    bool operator<(Node other){
        if(grade<g1||grade>g2)return false;
        else return grade>other.grade;
    }
};
vector<Node> V,V2;
int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        Node temp;
        cin>>temp.name>>temp.cls>>temp.grade;
        V2.push_back(temp);
    }
    cin>>g1>>g2;
    for(auto i:V2)if(i.grade>=g1&&i.grade<=g2)V.push_back(i);
    sort(V.begin(),V.end());
    if(V.size()==0){
        cout<<"NONE";
        return 0;
    }
    else{
        for(auto i:V){
            if(i.grade>=g1&&i.grade<=g2)cout<<i.name<<' '<<i.cls;
            cout<<endl;
        }
    }
}