#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
int n, m;
vector<card> cards;
card list[10000];

map<char, vector<card>> M;

struct card
{
	char type = ' ';
	int x, y;
	int d = 0;
	card(char c, int _x, int _y)
	{
		this->type = c;
		this->x = _x;
		this->y = _y;
		this->d = pow(x, 2) + pow(y, 2);
	}
};

card zero('0', 0, 0);

int distance(card a, card b)
{
	return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
} 

bool compare2(card& a, card& b)
{

	if (a.d == b.d)
	{
		if (a.y = b.y)
			return a.x > b.x;
		return a.y > b.y;
	}
	return a.d > b.d;
}

int main()
{
	ios::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	while (tcase--)
	{
		cin >> n >> m; // 축의 크기 와 카드의수
		for (int i = 0; i < m; i++)
		{
			char type;
			int x, y;
			cin >> type >> x >> y;
			card newcard(type, x, y);
			cards.push_back(newcard);
		}
	}
	return 0;
}