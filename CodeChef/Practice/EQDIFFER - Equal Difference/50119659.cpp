#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update
//order_of_key(k)  : Number of items strictly smaller than k.
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=1e6+5;
const int mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,mn,n,t,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        set<int>st;
        map<int,int>mp;
        for(i=0;i<n;i++)cin >> x,st.insert(x),++mp[x];
        if((int)st.size() == n)cout << max(0,n-2) << '\n';
        else
        {
            mn=INT_MAX;
            for(auto it : mp)mn=min(mn,n-it.second);
            cout << mn << '\n';
        }
    }
    return 0;
}