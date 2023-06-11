#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
inline uint64_t mulmodu64(uint64_t a, uint64_t b, uint64_t m) {
    #if defined(__GNUC__) && defined(__x86_64__)
        uint64_t q, r;
        asm("mulq %3;"
            "divq %4;"
            : "=a"(q), "=d"(r)
            : "a"(a), "d"(b), "rm"(m)
            : "cc");
        return r;
    #else
        a %= m;
        b %= m;
        // No overflow possible.
        if (a == 0) return 0;
        if (b <= std::numeric_limits<uint64_t>::max() / a) return (a*b) % m;
        uint64_t res = 0;
        while (a != 0) {
            if (a & 1) {
                if (b >= m - res) res -= m;
                res += b;
            }
            a >>= 1;
            if (b >= m - b) b += b - m;
            else            b += b;
        }
        return res;
    #endif
}
inline uint64_t powmod(uint64_t b, uint64_t e, uint64_t m) {
    uint64_t r = 1;
    b %= m;
    while (e) {
        if (e % 2 == 1) r = mulmodu64(r, b, m);
        b = mulmodu64(b, b, m);
        e >>= 1;
    }
    return r;
}
int kth_digit_frac(uint64_t a, uint64_t b, uint64_t k) {
    return 10 * mulmodu64(a, powmod(10, k, b), b) / b;
}
int main()
{
    FAST();
    int i,n,t;
    LL p,q,x,ans;
    cin >> t;
    while(t--)
    {
        ans=0;
        cin >> n >> p >> q;
        for(i=0;i<n;i++)ans+=kth_digit_frac(p,q,i);
        cout << ans << '\n';
    }
    return 0;
}