#pragma GCC optimize("Ofast")
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
vector<int>ans[M];
int a[M],b[M],cnt[M];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++)cnt[i]=0, ans[i].clear();
        int mx=0;
        for(int i=0;i<n;i++)cin >> a[i], b[i]=a[i], ++cnt[a[i]], mx=max(mx, cnt[a[i]]);
        sort(b,b+n);
        for(int i=0;i<n;i++)ans[b[i]].emplace_back(b[(i+mx)%n]);
        for(int i=0;i<n;i++)cout << ans[a[i]].back() << ' ', ans[a[i]].pop_back();
        cout << '\n';
    }
    return 0;
}