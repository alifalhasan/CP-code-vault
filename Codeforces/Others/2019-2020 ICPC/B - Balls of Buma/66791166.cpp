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
     int i,l,cnt=0;
    string s;
    char c;
    V<pair<char,int> >v;
    cin >> s;
    l=s.SZ,c=s[0];
    for(i=0;i<l;i++)
    {
        if(c == s[i])++cnt;
        else
        {
            v.PSB({c,cnt});
            cnt=1,c=s[i];
        }
    }
    v.PSB({c,cnt});
    l=v.SZ;
    for(i=0;i<l/2;i++)
    {
        if(v[i].FI != v[l-i-1].FI  ||  v[i].SE+v[l-i-1].SE < 3)
        {
            cout << "0";
            return 0;
        }
    }
    if(v[l/2].SE == 1)
    {
        cout << "0";
        return 0;
    }
    cout << v[l/2].SE+1;
    return 0;
}