#include<iostream>
#include<vector>
using namespace std;
int area[16][16];

// 검정 1 흰색 2 공백 0;
int main()
{
	int tcase;
	cin >> tcase;
	while (tcase--)
	{
		for (int i = 1; i <= 225; i++)
		{
			int x, y;
			cin >> x >> y;
			int val = 5;
			int stone;
			if (i % 2 == 1) stone = 1;
			else stone = 0;
				
			area[y][x] = stone;
		}

	}
	return 0;
}