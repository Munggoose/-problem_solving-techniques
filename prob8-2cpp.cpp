//DP
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


int DP[1001][1001];
int main()
{
	ios::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	while (tcase--)
	{
		string str1;
		string str2;

		cin >> str1;
		cin >> str2;


		int tt = 1;
		for (int i = 1; i <= str1.length(); i++)
		{
			
			for (int j = 1; j <= str2.length(); j++)
			{
				if (str1.at(i - 1) == str2.at(j - 1))
				{
					DP[i][j] = DP[i - 1][j - 1] + 1;
				}
				else
				{
					DP[i][j] = max(DP[i][j-1],DP[i-1][j]);
				}

			}
		}
		cout << DP[str1.length()][str2.length()]<<"\n";
	}



	return 0;
}