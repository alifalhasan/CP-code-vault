#pragma GCC optimize("Ofast")
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <chrono>
#include <random>
#include <vector>
#include <climits>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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
 int ans[M];
bool ache[M];
 void Solve()
{
    int n;cin >> n;
    for(int i=1;i<=n;i++)ache[i]=0;
    for(int i=1;i<=n/2;i++)cin >> ans[i+i], ache[ans[i+i]]=1;
    ordered_set<int>ost;
    for(int i=1;i<=n;i++)
    {
        if(!ache[i])ost.insert(i);
    }
    for(int i=2;i<=n;i+=2)
    {
        if(!ost.order_of_key(ans[i]))
        {
            cout << "-1\n";
            return;
        }
        ans[i-1]=*ost.find_by_order(ost.order_of_key(ans[i])-1);
    }
    for(int i=n-1;i>=1;i-=2)
    {
        int small=ost.order_of_key(ans[i]+1);
        if(!small)
        {
            cout << "-1\n";
            return;
        }
        ans[i]=*ost.find_by_order(small-1), ache[ans[i]]=1, ost.erase(ost.find_by_order(small-1));
    }
    for(int i=1;i<=n;i++)
    {
        if(!ache[i])
        {
            cout << "-1\n";
            return;
        }
    }
    for(int i=1;i<=n;i++)cout << ans[i] << ' ';
    cout << '\n';
}
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--)Solve();
    return 0;
}