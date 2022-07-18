#include<iostream>
#include<map>
using namespace std;
int pos[35],in[35],N;
map<int,int> level;
void f(int root,int start,int end,int index){
    if(start>end)return;
    int i=start;
    while(i<end&&in[i]!=pos[root])i++;
    level[index] = pos[root];
    f(root - 1 - end + i,start,i-1,index*2+1);
    f(root-1,i+1,end,index*2+2);
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>pos[i];
    for(int i=0;i<N;i++)cin>>in[i];
    f(N-1,0,N-1,0);
    int j=0;
    for(auto i:level){
        cout<<i.second;
        if(j<N-1)cout<<' ';
        j++;
    }
}