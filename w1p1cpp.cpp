#include<iostream>
#include<vector>
using namespace std;
int m, n; // n �����ڱ���,  m ���� ��
vector<string> DNA;
vector<vector<int>> cnt(4);
int main()
{
	int tcase;
	while (tcase--)
	{
		cin >> m >> n;
		for (int i = 0; i < m; i++)
		{
			string s;
			cin >> s;
			DNA.push_back(s);
		}
		//DNA �Է�



		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				char val = DNA[j][i];
				switch (val)
				{
				case 'A':
					cnt[0][i] +=1;
				case 'C':
					cnt[1][i] += 1;
				case 'G':
					cnt[2][i] += 1;
				case 'T':
					cnt[3][i] += 1;
				}
			}

			for (int j = 0; j < m; j++)
			{

			}
		}

	}


	return 0;
}