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
//    FAST();
 //    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
     int i,n,x,y,last,ans1=0,ans2=0;
    S("%d %d",&n,&x);
    getchar();
    char s[n+2];
    S("%s",s+1);
    last=x;
    if(x <= n/2)
    {
        for(i=x;i<=n/2;i++)
        {
            if(s[i] != s[n-i+1])
            {
                ans1+=abs(i-last);
                last=i;
                y=abs(s[i]-s[n-i+1]);
                ans1+=min(y,26-y);
            }
        }
        for(i=x-1;i>0;i--)
        {
            if(s[i] != s[n-i+1])
            {
                ans1+=abs(i-last);
                last=i;
                y=abs(s[i]-s[n-i+1]);
                ans1+=min(y,26-y);
            }
        }
        last=x;
        for(i=x;i>0;i--)
        {
            if(s[i] != s[n-i+1])
            {
                ans2+=abs(i-last);
                last=i;
                y=abs(s[i]-s[n-i+1]);
                ans2+=min(y,26-y);
            }
        }
        for(i=x+1;i<=n/2;i++)
        {
            if(s[i] != s[n-i+1])
            {
                ans2+=abs(i-last);
                last=i;
                y=abs(s[i]-s[n-i+1]);
                ans2+=min(y,26-y);
            }
        }
    }
    else
    {
        if((n & 1)  &&  x == (n/2+1))++x;
        for(i=x;i<=n;i++)
        {
            if(s[i] != s[n-i+1])
            {
                ans1+=abs(i-last);
                last=i;
                y=abs(s[i]-s[n-i+1]);
                ans1+=min(y,26-y);
            }
        }
        for(i=x-1;i>n/2+(n & 1);i--)
        {
            if(s[i] != s[n-i+1])
            {
                ans1+=abs(i-last);
                last=i;
                y=abs(s[i]-s[n-i+1]);
                ans1+=min(y,26-y);
            }
        }
        last=x;
        for(i=x;i>n/2+(n & 1);i--)
        {
            if(s[i] != s[n-i+1])
            {
                ans2+=abs(i-last);
                last=i;
                y=abs(s[i]-s[n-i+1]);
                ans2+=min(y,26-y);
            }
        }
        for(i=x+1;i<=n;i++)
        {
            if(s[i] != s[n-i+1])
            {
                ans2+=abs(i-last);
                last=i;
                y=abs(s[i]-s[n-i+1]);
                ans2+=min(y,26-y);
            }
        }
    }
    cout << min(ans1,ans2);
    return 0;
}