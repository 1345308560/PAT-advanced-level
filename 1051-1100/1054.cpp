//15:35 - 15:38 - 20分 AC
#include<iostream>
#include<map>
using namespace std;
map<int,int> Mp;
int N,M,num;
int MAX=-1,MAX_color=-1;
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            cin>>num;
            Mp[num]++;
            if(Mp[num]>MAX){
                MAX=Mp[num];
                MAX_color=num;
            }
        }
    cout<<MAX_color;
}