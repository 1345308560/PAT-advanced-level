//11:05 - 11:18 - 22分 (超时)
//      - 11:38 - 22分 (改为优先队列仍超时)
// 膜拜柳神      - 25分
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int N,K;
struct Node{
    char name[10];
    int age,worth;
    bool operator<(Node B){
        if(worth!=B.worth)return worth>B.worth;
        else if(age!=B.age)return age<B.age;
        else return strcmp(name, B.name)<0;
    }
}Nl[100005];
bool cmp (int A,int B){
    if(Nl[A].worth!=Nl[B].worth)return Nl[A].worth>Nl[B].worth;
    else if(Nl[A].age!=Nl[B].age)return Nl[A].age<Nl[B].age;
    else return strcmp(Nl[A].name, Nl[B].name)<0;
}
int book[205]={};
vector<int> V;
int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++)cin>>Nl[i].name>>Nl[i].age>>Nl[i].worth;
    sort(Nl,Nl+N);
    for(int i=0;i<N;i++){
        if(book[Nl[i].age]>100)continue;
        else V.push_back(i);
        book[Nl[i].age]++;
    }
    for(int i=0;i<K;i++){
        int M,Amin,Amax;
        cin>>M>>Amin>>Amax;
        vector<int> temp;
        for(int j=0;j<V.size();j++)
            if(Nl[V[j]].age>=Amin&&Nl[V[j]].age<=Amax)
                temp.push_back(V[j]);
        //sort(temp.begin(), temp.end(),cmp);
        cout<<"Case #"<<i+1<<":\n";
        if(temp.size()==0){cout<<"None\n";continue;}
        for(int j=0;j<M&&j<temp.size();j++) 
            cout<<Nl[temp[j]].name<<' '<<Nl[temp[j]].age<<" "<<Nl[temp[j]].worth<<endl;
    }
}