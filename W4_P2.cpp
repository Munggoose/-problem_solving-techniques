#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int dx[8] = { 2,2,-2,-2,1,1,-1,-1 };
int dy[8] = { 1,-1,1,-1,2,-2,2,-2 };

bool visit[500][500];
int l;
int startx, starty;
int desx, desy;

void init()
{
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			visit[i][j] = false;
		}
	}
}

struct node
{
	int x, y;
	node(int a, int b)
	{
		x = a;
		y = b;
	}
};

int bfs(node start)
{
	queue<node> q;
	q.push(start);
	int level = 0;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			node tmp = q.front();
			q.pop();
			if (tmp.x == desx && tmp.y == desy)return level;

			for (int j = 0; j < 8; j++)
			{
				int x = tmp.x+dx[j];
				int y = tmp.y+dy[j];
				if (0 <= x && x < l && 0 <= y && y < l)
				{
					if (!visit[y][x])
					{
						visit[y][x] = true;
						node addnode(x, y);
						q.push(addnode);
					}
				}
			}
		}
		level++;
	}
	return level;
}

int main()
{
	int tcase;
	cin >> tcase;
	while (tcase--)
	{
		cin >> l;
		cin >> startx >> starty;
		cin >> desx >> desy;
		node nod(startx, starty);
		cout << bfs(nod) << "\n";
		init();
	}


	return 0;
}