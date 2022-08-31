// 17:05 - 24分
// 17:07 - 27分
#include<iostream>
#include<map>
#include<stack>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Record{
    string name,status;
    int h,m,s,t;
}R[10005];
vector<int> V[10005],length,Vf,num;
vector<string> ans;
map<string,int> Mp;
int N,M,cnt=0,max_l=-1;
bool cmp(int a,int b){
    return R[a].t<R[b].t;
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>R[i].name;
        scanf("%2d:%2d:%2d",&R[i].h,&R[i].m,&R[i].s);
        R[i].t=R[i].h*3600+R[i].m*60+R[i].s;
        cin>>R[i].status;
        if(Mp.count(R[i].name)==0)
            Mp[R[i].name]=cnt++;
        V[Mp[R[i].name]].push_back(i);
    }
    length.resize(cnt);
    for(int i=0;i<cnt;i++){
        sort(V[i].begin(),V[i].end(),cmp);
        length[i]=0;
        for(int j=0;j<V[i].size();j++)
            if(R[V[i][j]].status=="in")
                if(j+1<V[i].size())
                    if(R[V[i][j+1]].status=="out"){
                        Vf.push_back(V[i][j]);
                        Vf.push_back(V[i][j+1]);
                        int l=R[V[i][j+1]].t-R[V[i][j]].t;
                        length[i]+=l;
                    }
    }
    sort(Vf.begin(),Vf.end(),cmp);
    num.resize(Vf.size());
    for(int i=0;i<Vf.size();i++)
        if(i==0)num[i]=1;
        else{
            num[i]=num[i-1];
            if(R[Vf[i]].status=="in")num[i]++;
            else num[i]--;
        }
    int pos=0;
    for(int i=0;i<M;i++){
        int hh,mm,ss,tt;
        scanf("%2d:%2d:%2d",&hh,&mm,&ss);
        tt=hh*3600+mm*60+ss;
        if(tt<R[Vf[0]].t)cout<<0<<endl;
        else if(tt>R[Vf[Vf.size()-1]].t)cout<<0<<endl;
        else{
            for(int j=pos;j<Vf.size();j++)
                if(tt>=R[Vf[j]].t&&tt<R[Vf[j+1]].t){
                    cout<<num[j]<<endl;
                    pos=j;
                    break;
                }
        }
    }
    for(int i=0;i<cnt;i++){
        if(max_l<length[i]){
            max_l=length[i];
            ans.clear();
            ans.push_back(R[V[i][0]].name);
        }
        else if(max_l==length[i])ans.push_back(R[V[i][0]].name);
    }
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
    printf("%02d:%02d:%02d",max_l/3600,(max_l%3600)/60,max_l%60);
}