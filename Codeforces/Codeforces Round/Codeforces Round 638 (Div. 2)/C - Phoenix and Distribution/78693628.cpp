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
     int i,k,n,t;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> s;
        sort(s.B,s.E);
        if(k == 1)cout << s << "\n";
        else if(k == n)cout << s.back() << "\n";
        else
        {
            set<char>st;
            for(i=0;i<n;i++)st.insert(s[i]);
            if(st.SZ == 1)
            {
                n=n/k+(n%k > 0);
                for(i=0;i<n;i++)cout << s[0];
                cout << "\n";
            }
            else if(st.SZ == 2)
            {
                if(s[k] == s[0])
                {
                    cout << s[0];
                    for(i=k;i<n;i++)cout << s[i];
                    cout << "\n";
                }
                else if(s[k-1] != s[0])cout << s.back() << "\n";
                else
                {
                    cout << s[0];
                    n-=k;
                    n=n/k+(n%k > 0);
                    while(n--)cout << s.back();
                    cout << "\n";
                }
            }
            else
            {
                if(s[k-1] != s[0])cout << s[k-1] << "\n";
                else
                {
                    cout << s[0];
                    for(i=k;i<n;i++)cout << s[i];
                    cout << "\n";
                }
            }
        }
    }
    return 0;
}