#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    bool ok;
    ll a,dc,dm,hc,hm,i,k,tdc,thc,w;
    cin >> t;
    while(t--)
    {
        cin >> hc >> dc >> hm >> dm >> k >> w >> a;
        ok=0;
        for(i=0;i<=k;i++)
        {
            tdc=dc+i*w, thc=hc+(k-i)*a;
            ok |= ((hm+tdc-1)/tdc <= (thc+dm-1)/dm);
        }
        if(ok)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}