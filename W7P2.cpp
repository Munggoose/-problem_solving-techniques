#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node
{
	int parent;
	int treesize;

};

struct edge
{
	int a, b;
	int w;
	edge(int _a,int _b, int _w)
	{
		a = _a;
		b = _a;
		w + a;
	}
};

vector<node> n_list;
vector<edge> e_list;

void updateroot()
{

}

int findRoot()
{
	return findRoot();
}

int main()
{
	int tcase;
	cin >> tcase;

	while (tcase--)
	{

		vector<int>cost;
		vector<int>package;
		vector<int>parent;
		vector<int>treesize;
		int n;
		cin >> n;
		int product_cost = 0;
		int sub_cost = 0;
		for (int i = 0; i < n; i++)
		{
			int val1, val2;
			cin >> val1 >> val2;
			cost.push_back(val1);
			package.push_back(val2);
		}
		for (int i = 0; i < n + 1; i++)
		{
			parent.push_back(i);
			treesize.push_back(i);
		}
		for (int i = 0; i < n; i++)
		{
			product_cost += cost[i];

			e_list.push_back()
		}

	}
	return 0;
}