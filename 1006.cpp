#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Node{
    string name;
    int h,m,s;
    bool operator<(const Node b)const{
        if(h==b.h){
            if(m==b.m){
                return s<b.s;
            }
            else return m<b.m;
        }
        else return h<b.h;
    }
};

vector<Node> Vin,Vout;
int M;

int main(){
    cin>>M;
    for(int i=0;i<M;i++){
        string name;
        string t;
        cin>>name;
        for(int j=0;j<2;j++){
            cin>>t;
            int h,m,s;
            h=stoi(t.substr(0,2));
            m=stoi(t.substr(3,2));
            s=stoi(t.substr(6,2));
            Node temp;temp.name=name;temp.h=h;temp.m=m;temp.s=s;
            if(j==0)Vin.push_back(temp);
            else Vout.push_back(temp);
        }
    }
    sort(Vin.begin(),Vin.end());
    sort(Vout.begin(),Vout.end());
    cout<<Vin[0].name<<" "<<Vout[Vout.size()-1].name;
}