#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
struct Node{
    int id,M,A;
}Np[1005];
struct Node2{
    int min_id,M=0,A=0,f_n=0;
    bool operator<(const Node2 other){
        int A1=(int)(1.0*A/f_n*1000);
        int A2=(int)(1.0*other.A/other.f_n*1000);
        if(A1!=A2)return A1>A2;
        else return min_id<other.min_id;
    }
}Nf[10005];
map<int,int> Mp;
int N,k,father,mother,child;
int root[10005];
int vis[10005]={};
int find_root(int n){
    if(root[n]!=n)
        root[n]=find_root(root[n]);
    return root[n];
}
void m_union(int a,int b){
    int ra=find_root(a),rb=find_root(b);
    if(ra==rb)return;
    root[ra]=rb;
}
int main(){
    cin>>N;
    for(int i=0;i<10005;i++)root[i]=i;
    for(int i=0;i<N;i++){
        cin>>Np[i].id>>father>>mother;
        vis[Np[i].id]=vis[father]=vis[mother]=1;
        if(father!=-1)m_union(Np[i].id,father);
        if(mother!=-1)m_union(Np[i].id,mother);
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>child;
            vis[child]=1;
            m_union(child,Np[i].id);
        }
        cin>>Np[i].M>>Np[i].A;
    }
    int cnt=0;
    for(int i=0;i<10005;i++)
        if(vis[i])
            if(Mp.count(find_root(i))==0){
                Mp[find_root(i)]=cnt;
                Nf[cnt].min_id=i;
                Nf[cnt].f_n++;
                cnt++;
            }
            else Nf[Mp[find_root(i)]].f_n++;
    for(int i=0;i<N;i++){
        int f_id=Mp[find_root(Np[i].id)];
        Nf[f_id].A+=Np[i].A;
        Nf[f_id].M+=Np[i].M;
    }
    sort(Nf,Nf+cnt);
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
        printf("%04d %d %.3f %.3f\n",Nf[i].min_id,Nf[i].f_n,1.0*Nf[i].M/Nf[i].f_n,1.0*Nf[i].A/Nf[i].f_n);
    
}