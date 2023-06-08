#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=998244353;
ll fact[M];
bool mark[M];
long long BigMod(long long val,long long pow)
    long long res = 1;
    val = val % mod;
    while(pow > 0)
    {
        if(pow & 1)res = (res*val) % mod;
        pow = pow >> 1;
        val = (val*val) % mod;
    }
    return res;
ll nCr(int n,int r)
{
    return (fact[n]*BigMod(fact[r]*fact[n-r],mod-2))%mod;
}
 void PreCal()
{
    int i;
    fact[0]=1;
    for(i=1;i<M;i++)fact[i]=(fact[i-1]*i)%mod;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,l,t,cnt0,cnt1;
    cin >> t;
    PreCal();
    while(t--)
    {
        cin >> l >> s;
        cnt0=cnt1=0;
        for(i=0;i<l;i++)
        {
            mark[i]=0;
            cnt0+=(s[i] == '0');
        }
        for(i=1;i<l;i++)
        {
            if(s[i] == '1')
            {
                if(s[i-1] == '1'  &&  !mark[i-1])++cnt1,mark[i]=1;
            }
        }
        cout << nCr(cnt0+cnt1,cnt1) << '\n';
    }
    return 0;
}