#include<iostream>
#include<map>
using namespace std;
int N,M,Heap[1005],heap_size=0,num;
map<int,int> Mp;
string str,ans="";
void Insert(int val){
    int pos=heap_size;
    Heap[pos]=val;
    while(pos>=0&&Heap[pos]>Heap[(pos-1)/2]){
        swap(Heap[pos],Heap[(pos-1)/2]);
        pos=(pos-1)/2;
    }
    heap_size++;
}
void check1(int n){
    //cout<<"check1"<<endl;
    int n2;
    string t1,t2;
    cin>>n2>>t2>>t1;
    if(Mp.count(n2)==0||Mp.count(n)==0)ans+='0';
    else if(Mp[n2]==Mp[n])ans+='0';
    else if((Mp[n2]-1)/2==(Mp[n]-1)/2)ans+='1';
    else ans+='0';
}
void check2(int n){
    //cout<<"check2"<<endl;
    if(Mp.count(n)==0)ans+='0';
    else if(Heap[0]==n)ans+='1';
    else ans+='0';
}
void check3(int n){
    //cout<<"check3"<<endl;
    int n2;
    string t;
    cin>>t>>n2;
    if(Mp.count(n2)==0||Mp.count(n)==0)ans+='0';
    else if(Mp[n2]==Mp[n])ans+='0';
    else if((Mp[n2]-1)/2==Mp[n])ans+='1';
    else ans+='0';
}
void check4(int n){
    //cout<<"check4"<<endl;
    string t1,t2;
    int n2;
    cin>>t1>>t2>>n2;
    if(Mp.count(n2)==0||Mp.count(n)==0)ans+='0';
    else if(Mp[n2]==Mp[n])ans+='0';
    else if(Mp[n2]*2+1==Mp[n])ans+='1';
    else ans+='0';
}
void check5(int n){
    //cout<<"check5"<<endl;
    string t1,t2;
    int n2;
    cin>>t1>>t2>>n2;
    if(Mp.count(n2)==0||Mp.count(n)==0)ans+='0';
    else if(Mp[n2]==Mp[n])ans+='0';
    else if(Mp[n2]*2+2==Mp[n])ans+='1';
    else ans+='0';
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>num;
        Insert(num);
    }
    for(int i=0;i<heap_size;i++)
        Mp[Heap[i]]=i;
    for(int i=0;i<M;i++){
        cin>>num>>str;;
        if(str[0]=='a')check1(num);
        else{
            string t1,t2,t3;
            cin>>t1>>t3;
            if(t3[0]=='r'&&t3[1]=='o')check2(num);
            else if(t3[0]=='p')check3(num);
            else if(t3[0]=='l')check4(num);
            else check5(num);
        }
    }
    cout<<ans<<endl;
}