#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

char area[20][20];


int keyval(char c)
{
	int val = 0;
	if (c == 'a') { val = 1 << 0; }
	if (c == 'b') { val = 1 << 1; }
	if (c == 'c') { val = 1 << 2; }
	if (c == 'd') { val = 1 << 3; }
	if (c == 'e') { val = 1 << 4; }
	if (c == 'f') { val = 1 << 5; }
	return val;
}

bool check_key(char c)
{
	if (c == 'a') return true;
	if (c == 'b')return true;
	if (c == 'c') return true;
	if (c == 'd') return true;
	if (c == 'e')return true;
	if (c == 'f')return true;

	return false;
}

bool openroom(char c, int key)
{
	if (c == 'A') { if (key & keyval('a')) return true; }
	if (c == 'B') { if (key & keyval('b')) return true; }
	if (c == 'C') { if (key & keyval('d')) return true; }
	if (c == 'D') { if (key & keyval('c')) return true; }
	if (c == 'E') { if (key & keyval('e')) return true; }
	if (c == 'F') { if (key & keyval('f')) return true; }
	return false;
}
struct node
{
	int x, y;
	int key;
	node(int a, int b, int k)
	{
		x = a;
		y = b;
		key = k;
	}
};



int bfs(node no, int goal)
{
	bool visit[20][20][64];
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			for (int q = 0; q < 64; q++)
			{
				visit[i][j][q] = false;
			}
		}
	}
	queue<node> Q;
	Q.push(no);
	int level = -1;
	while (!Q.empty())
	{
		level++;
		int size = Q.size();
		for (int i = 0; i < size; i++)
		{
			node tmp = Q.front();
			Q.pop();
			if (tmp.key == goal)
			{
				return level;
			}

			for (int j = 0; j < 4; j++)
			{
				int x, y, key;
				x = tmp.x + dx[j];
				y = tmp.y + dy[j];
				key = tmp.key;
				if (0 <= x && x < n && 0 <= y && y < m)
				{
					char data = area[y][x];
					if (data == '#') continue;
					if (data == '*' && !visit[y][x][key])
					{
						visit[y][x][key] = true;
						node newnode(x, y, key);
						Q.push(newnode);
						continue;
					}
					if (data == '@' && !visit[y][x][key])
					{
						visit[y][x][key] = true;
						node newnode(x, y, key);
						Q.push(newnode);
						continue;
					}
					if (!visit[y][x][key] && openroom(data, key))
					{
						visit[y][x][key] = true;
						node newnode(x, y, key);
						Q.push(newnode);
						continue;
					}
					if (check_key(data) && !visit[y][x][key])
					{
						visit[y][x][key] = true;
						int newkey = key;
						newkey |= keyval(data);
						if (!visit[y][x][newkey])
						{
							visit[y][x][newkey] = true;
							node newnode(x, y, newkey);
							Q.push(newnode);
						}


					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	int tcase;
	cin >> tcase;
	while (tcase--)
	{
		//ют╥б
		cin >> m >> n;
		int startx = 0;
		int starty = 0;
		int goal = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> area[i][j];
				if (area[i][j] == '@')
				{
					startx = j;
					starty = i;
				}
				goal |= keyval(area[i][j]);
			}
		}
		node start(startx, starty, 0);
		cout << bfs(start, goal) << "\n";

	}

	return 0;
}