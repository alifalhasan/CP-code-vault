#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename temp>using ordered_set = tree<temp, null_type, less_equal<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e6+5;
const int N=2e5+5;
const int mod=1e9+7;
int n,a[M];
set<int>idxs[M];
vector<pair<int,int>>ans;
bool Check(int idx)
    int i,ix,iy,x,y,val=a[n];
    multiset<int>mst;
    ans.clear();
    ans.emplace_back(a[idx],a[n]);
    for(i=1;i<n;i++)
    {
        if(i != idx)mst.insert(a[i]);
    }
    idxs[a[idx]].erase(idx);
    while(!mst.empty())
    {
        y=*(mst.rbegin());
        mst.erase(mst.find(y));
        x=val-y,val=y;
        if(mst.find(x) == mst.end())
        {
            idxs[a[idx]].insert(idx);
            return 0;
        }
        mst.erase(mst.find(x));
        ans.emplace_back(x,y);
        ix=*(idxs[x].begin()),idxs[x].erase(ix);
        iy=*(idxs[y].begin()),idxs[y].erase(iy);
    }
    return 1;
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        n <<= 1;
        for(i=1;i<=n;i++)cin >> a[i],idxs[a[i]].clear();
        for(i=1;i<=n;i++)idxs[a[i]].insert(i);
        sort(a+1,a+n+1);
        for(i=1;i<n;i++)
        {
            if(Check(i))break;
        }
        if(i == n)cout << "NO\n";
        else
        {
            cout << "YES\n" << a[n]+a[i] << '\n';
            for(auto it : ans)cout << it.first << ' ' << it.second << '\n';
        }
    }
    return 0;
}