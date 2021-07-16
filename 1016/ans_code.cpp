#include <iostream>
#define MAXN 1000000
#define ll long long
#define int ll
using namespace std;

int mu[MAXN];

void buildmu()
{
    mu[1] = 1;
    for(int i = 1; i <= MAXN; i++) 
    {
        for(int j = 2 * i; j <= MAXN; j += i) 
        {
            mu[j] -= mu[i];
        }
    }

}

ll sqn(ll N)
{
    int ans = 0;
    for (int i = 1; i*i<=N; i++) 
        ans += (mu[i]*(N/(i*i))); 
    return ans;

}

signed main()
{

    buildmu();

    int l,r;
    cin>>l>>r;

    cout<<sqn(r)-sqn(l-1)<<'\n';
}
