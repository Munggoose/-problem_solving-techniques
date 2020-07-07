// tolower , toupper
// 대문자-> 소문자
// 알파벳 갯수는 26개이다
// 양쪽끝에서 비교 front rear
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


bool check(char a)
{
	switch (a)
	{
	case 'a': return true;
	case 'b': return true;
	case 'c': return true;
	case 'd': return true;
	case 'e': return true;
	case 'f': return true;
	case 'g': return true;
	case 'h': return true;
	case 'i': return true;
	case 'j': return true;
	case 'k': return true;
	case 'l': return true;
	case 'm': return true;
	case 'n': return true;
	case 'o': return true;
	case 'p': return true;
	case 'q': return true;
	case 'r': return true;
	case 's': return true;
	case 't': return true;
	case 'u': return true;
	case 'v': return true;
	case 'w': return true;
	case 'x': return true;
	case 'y': return true;
	case 'z': return true;
	}
	return false;
}


int main()
{
	int tcase;
	cin >> tcase;
	while (tcase--)
	{
		string str;
		cin >> str;
		int rear = str.length()-1;
		int front = 0;
		bool result = true;
		while (front <= rear)
		{
			char f, r;
			f = tolower(str[front]);
			r = tolower(str[rear]);
			if (!check(f)){
				front++;
				continue;
			}
			if (!check(r))
			{
				rear--;
				continue;
			}

			if (f != r)
			{
				result = false;
				break;
			}
			front++, rear--;
		}

		if (result) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}