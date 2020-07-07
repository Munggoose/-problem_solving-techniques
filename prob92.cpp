//DP
#include<iostream>
#include<algorithm>
using namespace std;
int tcase = 0;
int n, k; // 물건의 수, 무게제한
int thing[501];
int price[501];
int DP[500][100000];
int result[501];

int updatedp(int idx,int weight)
{
	return max(DP[idx - 1][weight], DP[idx - 1][weight - thing[idx]] + price[idx]);
}

int main()
{
	cin >> tcase;
	while (tcase--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> thing[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> price[i];
		}
	
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= k; j++)
			{
				if(thing[i] > j) 
				{
					DP[i][j] = DP[i - 1][j];
				}
				else
				{
					DP[i][j] = updatedp(i, j);
				}
			}
			result[i-1] = DP[i][k];
		}
	
		sort(result, result + n);
		cout << result[n - 1]<<"\n";
		
	}


	return 0;
}