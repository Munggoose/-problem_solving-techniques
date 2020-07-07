#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int calminlen(string s, string r)
{
	int minlen = s.size()+1;
	int start = 0, end = 0;
	
	for (int i = 0; i < s.size(); i++)
	{	
		end = i;
		vector<bool> check(r.size());
		bool flag = true;
		for (int j = start; j <= end; j++)
		{
			
			for (int k = 0; k < r.size(); k++)
			{
				if (check[k]) continue;
				if (s[j] == r[k]) { 
					check[k] = true;
					break;
				}
			}
	
		}
		for (int k = 0; k < r.size(); k++)
		{
			if (!check[k])
			{
				flag = false;
			}
		}
		if (flag)
		{
			if (minlen == 0)
			{
				minlen = end - start;
			}
			else if ((end - start) < minlen)
			{
				minlen = end - start;
			}
		}
		else
		{
			break;
		}
	
	}
	if (minlen == s.size() + 1)minlen = 0;
	return minlen;
}

int calminlen2(string s, string r)
{
	int min = s.length() + 1;
	int start=0, end = 0;
	while (end < s.length())
	{

	}


	if (min == s.size() + 1) min = 0;
	return min;
}

int main()
{

	int tcase;
	cin >> tcase;
	while (tcase--)
	{
		string s;
		string r;
		cin >> s >> r;

		cout << calminlen2(s,r) << "\n";
	}




	return 0;
}