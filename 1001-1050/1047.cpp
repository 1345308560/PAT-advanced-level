//17:59 - 18:05 - 17分
//膜拜柳神 
// strcmp比string类快
// scanf和printf加速
#include<vector>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
char name[40005][5];
vector<int> V[2505];
bool cmp(int a,int b){
    return strcmp(name[a],name[b])<0;
}
int N,K;
int main(){
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++){
        int C;
        scanf("%s %d",name[i],&C);
        for(int j=0;j<C;j++){
            int num;
            scanf("%d",&num);
            V[num].push_back(i);
        }
    }
    for(int i=1;i<=K;i++){
        printf("%d %d\n",i,V[i].size());
        sort(V[i].begin(),V[i].end(),cmp);
        for(int j=0;j<V[i].size();j++){
            printf("%s",name[V[i][j]]);
            printf("\n");
        }
    }
}