//Greedy Algorithm

#include<iostream>
#include<algorithm>
using namespace std;
int tcase = 0;
int n, k;
int thing[501];
int price[501];
pair<int,int> value[501];

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first > b.first;
}

int main()
{
	cin >> tcase;
	while(tcase--)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> thing[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> price[i];
		}
		for (int i = 0; i < n; i++)
		{
			value[i].first = price[i] / thing[i];
			value[i].second = i;
		}
		sort(value, value + n, compare);
		int result = 0;
		int limit = k;
		for (int i = 0; i < n; i++)
		{
			int idx = value[i].second;
			if (limit >= thing[idx])
			{
				result += price[idx];
				limit -= thing[idx];
			}
			else
			{
				result += limit * value[i].first;
				break;
			}
		}
		cout << result << "\n";
	}


	return 0;
}