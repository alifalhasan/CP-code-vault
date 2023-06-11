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
const int M=2e5+5;
const int N=1e6+5;
const int mod=1e9+7;
int phi[N];
void EulerPhi()
{
    int i,j;
    phi[1]=1;
    for(i=2;i<N;i++)phi[i]=i-1;
    for(i=2;i<N;i++)
    {
        for(j=2*i;j<N;j+=i)phi[j]-=phi[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,t;
    ll ans,n,tmp;
    cin >> t;
    EulerPhi();
    while(t--)
    {
        cin >> n;
        ans=n*n;
        for(i=2;i<=n;i++)
        {
            tmp=n/i;
            ans+=2ll*tmp*tmp*phi[i];
        }
        cout << ans << '\n';
    }
    return 0;
}