#include<bits/stdc++.h>
using namespace std;
#define S scanf
#define P printf
#define G getline
#define SZ size()
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define EM empty()
#define V vector
#define Q queue
#define DQ deque
#define PQ priority_queue
#define ST stack
#define FI first
#define SE second
#define PI acos(-1)
#define PS push
#define PP pop()
#define PSF push_front
#define PSB push_back
#define PPF pop_front()
#define PPB pop_back()
#define MP make_pair
#define LL long long int
#define ULL unsigned long long int
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>
#define PLI pair<long long int,int>
#define PLL pair<long long int,long long int>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MLI map<long long int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
     //int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]= {-1,0,1,-1,1,-1,0,1};
//int dy[]= {1,1,1,0,0,-1,-1,-1};
      int main()
{
    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,j,m,n,t,a[105],p[105],x;
    bool mark[105];
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n;i++)mark[i]=false;
        for(i=1;i<=m;i++)cin >> p[i],mark[p[i]]=true;
        for(i=2;i<=n;i++)
        {
            x=a[i];
            j=i-1;
            while(j > 0  &&  x < a[j])
            {
                if(mark[j])swap(a[j],a[j+1]);
                else break;
                j--;
            }
        }
        for(i=2;i<=n;i++)
        {
            if(a[i] < a[i-1])break;
        }
        if(i > n)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}