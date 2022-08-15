// 21:51 - 22:03 - 25分
// 段错误
//       - 22:16 - 30分
// 改成BFS不超时
#include<iostream>
#include<queue>
#include<map>
using namespace std;
int M,N,L,T,cnt=2,ans=0;
int mp[65][1290][130];
int px[6]={1,-1,0,0,0,0};
int py[6]={0,0,1,-1,0,0};
int pz[6]={0,0,0,0,1,-1};
map<int,int> Mc;
struct Node{
    int x,y,z;
    Node(int xx,int yy,int zz){
        x=xx;y=yy;z=zz;
    }
};
bool check(int x,int y,int z){
    return x>=0&&x<L&&y>=0&&y<M&&z>=0&&z<N;
}
void BFS(int x,int y,int z,int color){
    Node temp2(x,y,z);
    queue<Node> Q;
    Q.push(temp2);
    mp[temp2.x][temp2.y][temp2.z] = color;
    Mc[color]++;
    while(!Q.empty()){
        Node temp=Q.front();
        Q.pop();
        for(int i=0;i<6;i++){
            if(check(temp.x+px[i],temp.y+py[i],temp.z+pz[i]))
                if(mp[temp.x+px[i]][temp.y+py[i]][temp.z+pz[i]]==1){
                    Q.push(Node(temp.x+px[i],temp.y+py[i],temp.z+pz[i]));
                    mp[temp.x+px[i]][temp.y+py[i]][temp.z+pz[i]] = color;
                    Mc[color]++;
                }
        }
    }
}
int main(){
    cin>>M>>N>>L>>T;
    for(int i=0;i<L;i++){
        for(int j=0;j<M;j++)
            for(int k=0;k<N;k++)
                cin>>mp[i][j][k];
    }
    for(int i=0;i<L;i++){
        for(int j=0;j<M;j++)
            for(int k=0;k<N;k++)
                if(mp[i][j][k]==1){
                    BFS(i,j,k,cnt);
                    if(Mc[cnt]>=T)ans+=Mc[cnt];
                    cnt++;
                }
    }
    cout<<ans;
}