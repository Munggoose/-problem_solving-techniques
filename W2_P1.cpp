#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
vector<string> codeword;
vector<string> target;
char alphabet[26] = { 'A', 'B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
int n, m; // n : 알파벳 갯수, m :  코드워드의 비트수

char compare(string s)
{
	char result;
	int minham = -1;
	int idx;
	for (int i = 0; i < codeword.size(); i++)
	{
		int ham = 0;
		for (int j = 0; j < m; j++)
		{
			if (s[j] != codeword[i][j]) ham++;
		}
		if (minham == -1)
		{
			minham = ham;
			idx = i;
		}
		else if(minham > ham)
		{
			minham = ham;
			idx = i;
		}
	}
	result = alphabet[idx];
	return result;
}

int main()
{
	int tcase;
	cin >> tcase;

	while (tcase--)
	{
		ios::sync_with_stdio(false);
		
		cin >> n >> m;
		//코드워드 입력
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			codeword.push_back(s);
		}
		int bitlen;
		cin >> bitlen;
		string bitstream;
		cin >> bitstream;
		int num = bitlen / m;

		for (int i = 0; i < num; i++)
		{
			string slice;
			for (int j = i * m; j < (i + 1) * m; j++)
			{
				slice += bitstream[j];
			}
			target.push_back(slice);
		}
		
		for (int i = 0; i < target.size(); i++)
		{
			cout << compare(target[i]);
		}
		cout << "\n";
		codeword.clear();
		target.clear();
	}

	return 0;
}