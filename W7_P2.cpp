//mst 최소 신장트리 
//사이클확인
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct edge
{
	int w;
	int prev, next;
	edge(int a, int b, int _w)
	{
		w = _w;
		prev = a;
		next = b;
	}
};

struct node
{
	node* parent = this;
	vector<edge> e;
	int i;
	node(int idx)
	{
		i = idx;
	}
};

vector<edge> e_list;
vector<node> n_list;

node c(-1);
bool cycle(edge& e)
{
	node A = n_list[e.next];
	node B(0);
	if (e.prev == -1)
	{
		 B = c;
	}
	else
	{
		 B = n_list[e.prev];
	}
	node* tmp = A.parent;
	while (true)
	{
		if (tmp == tmp->parent)
		{
			break;
		}
	}

	node* tmp2 = B.parent;
	while (true)
	{
		if (tmp2 == tmp2->parent)
		{
			break;
		}

	}
	if (tmp2 == tmp) return true;
	
	return false;
}
bool compare(edge& a, edge& b)
{
	return a.w >= b.w;
}

int main()
{
	ios::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	while (tcase--)
	{
		vector<int> price;
		vector<int>pack;
		int result = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int w, p;
			cin >> w >> p;
			result += w;
			price.push_back(w);
			pack.push_back(p);
			node newnode(i);
			n_list.push_back(newnode);
			edge e( -1,i, p);
			e_list.push_back(e);
			if (i != 0 && i != n - 1)
			{
				edge e2(i - 1, i,pack[i-1]);
				e_list.push_back(e2);
			}
		}
		sort(e_list.begin(), e_list.end(),compare);
		for (int i = 0; i < e_list.size(); i++)
		{
			edge& e = e_list[i];
			if (!cycle(e))
			{
				node* child = &n_list[e.next];
				node* parent = &c;
				if (e.prev == -1)
				{
					parent = &c;
				}
				else 
				{
					parent = &n_list[e.prev];
				}
				child->parent = parent;
				result += e.w;
			}
		}
		cout << result << "\n";
		e_list.clear();
		n_list.clear();
		c = node(-1);
	}

	return 0;
}