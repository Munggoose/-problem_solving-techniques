//mod 연사 string 으로 받기
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	int tcase;
	cin >> tcase;
	while (tcase-- )
	{
		string a;
		int b;
		cin >> a >> b;
		int x = 0;
		for (int i = 0; i < a.size(); i++)
		{
			x *= 10;
			x += a[i] - '0';
			x %= b;
		}
		if (x == 0) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}