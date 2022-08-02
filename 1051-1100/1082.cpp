//18:40 - 19:09 - 16分
//      - 19:18 - 21分
//      - 19:36 - 25分
#include<iostream>
#include<vector>
using namespace std;
string pin[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
vector<string> ans;
long N;
void f(int num,int flag){
    long a=num/1000,b=(num/100)%10,c=(num/10)%10,d=num%10;
    if(a>0){ans.push_back(pin[a]);ans.push_back("Qian");}
    else if(ans.size()>0&&ans[ans.size()-1]!="ling"&&ans[ans.size()-1]!="Fu")ans.push_back("ling");
    if(b>0){ans.push_back(pin[b]);ans.push_back("Bai");}
    else if(ans.size()>0&&ans[ans.size()-1]!="ling"&&ans[ans.size()-1]!="Fu")ans.push_back("ling");
    if(c>0){ans.push_back(pin[c]);ans.push_back("Shi");}
    else if(ans.size()>0&&ans[ans.size()-1]!="ling"&&ans[ans.size()-1]!="Fu")ans.push_back("ling");
    if(d>0){ans.push_back(pin[d]);}
    while(ans.size()>0&&ans[ans.size()-1]=="ling")ans.pop_back();
    if(num>0&&flag)ans.push_back("Wan");
}
int main(){
    cin>>N;
    if(N==0){
        cout<<"ling";
        return 0;
    }
    if(N<0){ans.push_back("Fu");N*=-1;}
    if(N/100000000>0){
        long num=N/100000000;
        if(num<10)ans.push_back(pin[N/100000000]);
        else{
            ans.push_back(pin[num/10]);
            ans.push_back("Shi");
            if(num%10>0)ans.push_back(pin[num%10]);
        }
        ans.push_back("Yi");
    }
    f((N/10000)%10000,1);
    f(N%10000,0);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i<ans.size()-1)cout<<' ';
    }
}
