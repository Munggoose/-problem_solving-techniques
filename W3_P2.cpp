#include<iostream>
#include<vector>
using namespace std;

bool check[1001];
int main()
{
	int tcase;
	cin >> tcase;
	while (tcase--)
	{
		int count = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int val;
			cin >> val;
			check[val] = true;
			if (!check[val + 1]) count++;
		}
		cout << count << "\n";
		for (int i = 0; i < 1001; i++)
		{
			check[i] = false;
		}
	}

	return 0;
}