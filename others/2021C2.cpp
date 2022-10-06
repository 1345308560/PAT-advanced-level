#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int N;
vector<int> h1,h2,p1;
map<int,int> mp1,mp2,mp3;
int main(){
    cin>>N;
    h1.resize(N);p1.resize(N);
    for(int i=0;i<N;i++)cin>>h1[i];
    for(int i=0;i<N;i++){
        cin>>p1[i];
        mp3[p1[i]]=i+1;
    }
    h2=h1;
    sort(h2.begin(),h2.end());
    sort(p1.begin(),p1.end());
    for(int i=0;i<N;i++){
        mp1[h2[i]]=i+1;
        mp2[i+1]=p1[i];
    }
    for(int i=N-1;i>=0;i--){
        cout<<mp3[mp2[mp1[h1[i]]]];
        if(i>0)cout<<' ';
    }
}