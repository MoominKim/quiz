#include <bits/stdc++.h>

using namespace std;

vector<int> sub[51];
queue<int> q;
int dp[51];
int parent[51];
int t[51];

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for(int i=0;i<N;i++)
    {
        int tmp;
        cin>>tmp;
        if(i==0)continue;
        sub[tmp].push_back(i);
        parent[i]=tmp;
        t[tmp]++;
    }

    for(int i=0;i<N;i++)
        if(sub[i].size()==0) 
            q.push(i);

    while(!q.empty())
    {
        
    }

    cout<<dp[0]<<'\n';

}