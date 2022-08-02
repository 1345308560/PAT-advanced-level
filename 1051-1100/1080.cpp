// 15:53 - 16:57 - 22分
//       - 17:10 - 24分 格式错误
//       - 17:11 - 30分
// 错误1 没有对id进行转化
// 错误2 每行结束都需要endl
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,K;
struct School{
    int maxSize=0;
    vector<int> V;  // student list
}Sch[105];
struct Student{
    int id,Ge,Gi,applications[6];
}Stu[40005];
bool cmp(Student &a,Student &b){
    if(a.Ge+a.Gi!=b.Ge+b.Gi)
        return a.Ge+a.Gi>b.Ge+b.Gi;
    else return a.Ge>b.Ge;
}
bool isEqual(int a,int b){
    return Stu[a].Ge==Stu[b].Ge&&Stu[a].Gi==Stu[b].Gi;
}
bool cmp2(int a,int b){
    return Stu[a].id<Stu[b].id;
}
int main(){
    cin>>N>>M>>K;
    for(int i=0;i<M;i++)cin>>Sch[i].maxSize;
    for(int i=0;i<N;i++){
        Stu[i].id=i;
        cin>>Stu[i].Ge>>Stu[i].Gi;
        for(int j=0;j<K;j++)cin>>Stu[i].applications[j];
    }
    sort(Stu,Stu+N,cmp);
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            int app=Stu[i].applications[j];
            if(Sch[app].V.size()<Sch[app].maxSize){
                Sch[app].V.push_back(i);
                break;
            }
            else if(Sch[app].V.size()>0&&isEqual(i,Sch[app].V[Sch[app].V.size()-1])){
                Sch[app].V.push_back(i);
                break;
            }
        }
    }
    for(int i=0;i<M;i++){
        sort(Sch[i].V.begin(),Sch[i].V.end(),cmp2);
        for(int j=0;j<Sch[i].V.size();j++){
            cout<<Stu[Sch[i].V[j]].id;
            if(j<Sch[i].V.size()-1)cout<<' ';
        }
        cout<<endl;
    }
}