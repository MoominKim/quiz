#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > v;
vector<int> LIS;
vector<int> lisi;
int parent[100100];
int now[100100];
int chk[100100];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end());
	int Max = 0;
	int Maxidx = 0;
	for (int i = 0; i < N; i++)
	{
		if (LIS.empty())
		{
			LIS.push_back(v[i].second);
			lisi.push_back(i);
			now[i] = -1;
			parent[i] = 1;
		}
		else
		{
			int p = upper_bound(LIS.begin(), LIS.end(), v[i].second) - LIS.begin();
			if (p == LIS.size())
			{
				LIS.push_back(v[i].second);
				lisi.push_back(i);
			}
			else
			{
				LIS[p] = v[i].second;
				lisi[p] = i;
			}
			if (p == 0)
			{
				now[i] = 0;
				parent[i] = 1;
			}
			else
			{
				now[i] = lisi[p - 1];
				parent[i] = parent[now[i]] + 1;
			}
		}
		
		if (parent[i] > Max)
		{
			Max = parent[i];
			Maxidx = i;
		}
	}
	while (Maxidx != -1)
	{
		chk[Maxidx] = 1;
		Maxidx = now[Maxidx];
	}
	cout << N - Max << '\n';
	for (int i = 0; i < N; i++)
	{
		if (chk[i] == 0)
		{
			cout << v[i].first << '\n';
		}
	}
}