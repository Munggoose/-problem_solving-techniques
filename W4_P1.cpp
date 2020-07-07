#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int person[10001];
bool visit[10001];
bool finish[10001];
int cnt = 0;
void dfs(int idx)
{
	visit[idx] = true;
	int next = person[idx];
	if (!visit[next]) dfs(next);
	else if (!finish[next])
	{
		//한반퀴돌고 또도는구조
		while (next != idx)
		{
			cnt++;
			next = person[next];
		}
		cnt++;
	}
	finish[idx] = true;
}


int main()
{
	int tcase;
	cin >> tcase;
	while (tcase--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int val;
			cin >> val;
			person[i] = val;
		}
		for (int i = 1; i <= n; i++)
		{
			if(finish[i])continue;
			dfs(i);
		}
		cout << n - cnt << "\n";
		cnt = 0;
		for (int i = 0; i < 1001; i++)
		{
			person[i] = 0;
			visit[i] = false;
			finish[i] = false;
		}
	}
	return 0;
}