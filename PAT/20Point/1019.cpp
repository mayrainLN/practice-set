#include"iostream"
#include"algorithm"
#include"string"
#include"vector"
using namespace std;
    //int 2.17*10^9
    //longlong 范围 9*10^19
typedef long long ll; 
//妈的刚刚写成longlong

int main(){
    ll num,base;
    cin>>num>>base;
    vector<ll> s;
    while(num)
    {
        s.push_back(num%base);
        num=num/base;
    }
    int flag=1;
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-1-i])
        {
        flag=0;
        break;
        }
    }
    if(flag)
    {
        cout<<"Yes"<<endl<<s[s.size()-1];
    }
    else{
        cout<<"No"<<endl<<s[s.size()-1];
    }
    for(int i=s.size()-2;i>=0;i--){
            cout<<" "<<s[i];
    }
    return 0;
}
