#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
    int h1,m1,s1,h2,m2,s2;
    int t1,t2;
    bool operator<(const Node& other){
        return t2<other.t2;
    }
}Np[2005];
vector<int> ans;
int N;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d:%d:%d",&Np[i].h1,&Np[i].m1,&Np[i].s1);
        Np[i].t1=Np[i].h1*3600+Np[i].m1*60+Np[i].s1;
        scanf("%d:%d:%d",&Np[i].h2,&Np[i].m2,&Np[i].s2);
        Np[i].t2=Np[i].h2*3600+Np[i].m2*60+Np[i].s2;
    }
    sort(Np,Np+N);
    for(int i=0;i<N;i++){
        if(ans.size()==0)ans.push_back(Np[i].t2);
        else if(Np[i].t1>=ans[ans.size()-1]){
            ans.push_back(Np[i].t2);
        }
        // printf("%d:%d:%d ",Np[i].h1,Np[i].m1,Np[i].s1);
        // printf("%d:%d:%d\n",Np[i].h2,Np[i].m2,Np[i].s2);
    }
    printf("%d",ans.size());
}