#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

#define PI acos(-1)
#define ll long long

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=3e5+5;
const int N=2e6+5;
const int mod=1e9+7;

int a[M];
string s[M];
ll cntX[M],digitSum[M];

bool compare(int i,int j)
{
    return digitSum[i]*cntX[j] < digitSum[j]*cntX[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> s[i], a[i]=i;
        for(char &c : s[i])
        {
            if(c == 'X')++cntX[i];
            else digitSum[i] += (c-'0');
        }
    }
    sort(a+1,a+n+1,compare);
    string fs="";
    for(int i=1;i<=n;i++)fs += s[a[i]];
    ll ans=0, xCnt=0;
    for(char &c : fs)
    {
        if(c == 'X')++xCnt;
        else ans += (c-'0')*xCnt;
    }
    cout << ans;
    return 0;
}
