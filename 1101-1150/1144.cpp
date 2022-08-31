#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int N,num;
map<int,bool> Mp;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num;
        if(num>0)Mp[num]=true;
    }
    for(int i=1;i<100005;i++){
        if(Mp.count(i)==0){
            cout<<i;
            break;
        }
    }
}