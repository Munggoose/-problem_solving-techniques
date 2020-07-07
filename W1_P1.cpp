#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// A C G T순서

vector<vector<int>> cnt; //2차원 벡터 ACGT 각 열별 갯수 저장용
vector<string> DNA; // 종별 저장
int n, m;

void result()
{
	int total_ham = 0;
	for (int i = 0; i < 4; i++)
	{
		int max = -1;
		int maxIndex = -1;				

		for (int j = 0; j < 4; j++)
		{
			if (max < cnt[j][i]) {
				max = cnt[j][i];
				maxIndex = j;
			}
		}

		total_ham += (m - max);			

		if (maxIndex == 0) {
			printf("A");
		}

		else if (maxIndex == 1) {
			printf("C");
		}

		else if (maxIndex == 2) {
			printf("G");
		}

		else if (maxIndex == 3) {
			printf("T");
		}

	}
	printf("\n");
	printf("%d\n", total_ham);
}

int main()
{
	ios::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	while (tcase--)
	{
		int ham = 0;
		cin >> m >> n;
		 //m: 종의 수 , n 유전자길이
		for (int i = 0; i < 4; i++)
		{
			vector<int> tmp(n);// 0을 n 개 넣어줌
			cnt.push_back(tmp);
		}

		for (int i = 0; i < m; i++)
		{
			string s;
			cin >> s;
			DNA.push_back(s);
		}
		//0: A, 1: C, 2: G, 3: T
		for(int i =0; i < n ; i++)
		{
			for (int j = 0; j < m; j++)
			{
				char  cww = DNA[j][i];
				switch (cww)
				{
				case'A':
					cnt[0][i] += 1;
				case'C':
					cnt[1][i] += 1;
				case'G':
					cnt[2][i] += 1;
				case'T':
					cnt[3][i] += 1;
		
				}
			}
			
		}

		for (int i = 0; i < n; i++)
		{
			int max = 0;
			char cwq;
			for (int j = 0; j < 4; j++)
			{
				if (cnt[j][i] > max) {
					max = cnt[j][i];
					switch (i)
					{
					case 0:
						cwq = 'A';
						break;
					case 1:
						cwq = 'C';
						break;
					case 2:
						cwq = 'G';
						break;
					case 3:
						cwq = 'T';
						break;
					}
				}
			}
			ham += m - max;
			cout << cwq;
		}
		cout << "\n";
		//result();
		cout << ham << "\n";
		cnt.clear();
		DNA.clear();
	}

	return 0;
}