#include<iostream>
#include<map>
using namespace std;

int N,M,data2[10005],cnt=0,ROOT=-1,cnt2=0;
int root[10005];
int num1,num2;
map<int,int> Mp1;
void find_root(int l,int r){
    if(l>=r)return ;
    int lp=-1,rp=-1;
    for(int i=l+1;i<=r;i++){
        if(data2[i]<data2[l]&&lp==-1)lp=i;
        if(data2[i]>data2[l]&&rp==-1){
            rp=i;
            break;
        }
    }
    if(lp!=-1)root[lp]=l;
    if(rp!=-1)root[rp]=l;
    if(lp==-1||rp==-1)find_root(l+1,r);
    else{
        find_root(lp,rp-1);
        find_root(rp,r);
    }
}
void check(int num1,int num2){
    if(Mp1.count(num1)==0&&Mp1.count(num2)==0)
        cout<<"ERROR: "<<num1<<" and "<<num2<<" are not found.\n";
    else if(Mp1.count(num1)==0)
        cout<<"ERROR: "<<num1<<" is not found.\n";
    else if(Mp1.count(num2)==0)
        cout<<"ERROR: "<<num2<<" is not found.\n";
    else{
        int cnt[10005]={};
        int p1=Mp1[num1],p2=Mp1[num2];
        while(p1!=-1){
            if(data2[p1]==num2){
                cout<<num2<<" is an ancestor of "<<num1<<".\n";
                return;
            }
            cnt[p1]=1;
            p1=root[p1];
        }
        while(p2!=-1){
            if(data2[p2]==num1){
                cout<<num1<<" is an ancestor of "<<num2<<".\n";
                return;
            }
            if(cnt[p2]>0){
                cout<<"LCA of "<<num1<<" and "<<num2<<" is "<<data2[p2]<<".\n";
                return;
            }
            p2=root[p2];
        }
    }
}
int main(){
    cin>>M>>N;
    for(int i=0;i<N;i++){
        cin>>data2[i];
        Mp1[data2[i]]=i;
    }
    fill(root,root+N,-1);
    find_root(0,N-1);
    // for(int i=0;i<N;i++)cout<<root[i]<<' ';
    for(int i=0;i<M;i++){
        cin>>num1>>num2;
        check(num1,num2);
    }
}