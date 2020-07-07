// Arithmetic expression tree
// 중위 표기법 infix notation
//bit mask
//infix to postfix algorithm(+.x)에 한정된 알고리즘
// stack
#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cmath>
#include<stack>
using namespace std;
char compare[2] = { '+','*' };
char num[50];
vector<int> result;

int precedence(char a)
{
	int priority = -1;
	if (a == '*') priority = 2;
	if (a == '+') priority = 1;
	return priority;
}
string infixToPostfix(string infix)
{
	string postfix = "";
	stack<char> st;
	for (int i = 0; i < infix.length();i++)
	{
		
		if (infix[i] != '+' && infix[i] != '*')postfix += (infix[i]);
		else
		{
			if (st.empty()) st.push(infix[i]);
			else
			{
				if (infix[i] == '*' && st.top() == '+') st.push(infix[i]);
				else
				{
					while (!st.empty() && (precedence(infix[i]) <= precedence(st.top())))
					{
						postfix += st.top();
						st.pop();
						
					}
					st.push(infix[i]);
				}
				
			}
		}
	}
	while (!st.empty())
	{
		postfix += st.top();
		st.pop();
	}

	return postfix;
}

int evaluate(string postfix)
{
	int result = 0;
	stack<int> st;
	for (int i = 0; i < postfix.length(); i++)
	{
		try 
		{
		
		if (postfix[i] != '*' && postfix[i] != '+')
		{
			st.push(postfix[i]-'0');
		}
		else
		{
			if (postfix[i] == '+')
			{
				int a, b;
				a = st.top();
				st.pop();
				b = st.top() ;
				st.pop();
				st.push(a + b);
			}
			else
			{
				int a, b;
				a = st.top();
				st.pop();
				b = st.top();
				st.pop();
				st.push(a * b);
			}
		}
		}
		catch (exception error)
		{
			cout << "error\n";
		}
	}
	result = st.top();
	st.pop();
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	while (tcase--)
	{
		int m, n;
		cin >> m >> n;
		
		for(int j =0; j< m;j++)
		{
			for (int i = 0; i < n; i++)
			{
				cin >> num[i];
			}
			int right;
			cin >> right;
			bool flag = false;
			int op_set = pow(2, n - 1) - 1;
			string infix;
			for (int i = 0; i < n; i++)
			{  
				 infix += num[i];
				 if (i != n - 1)
				 {
					 infix += " ";
				 }
			}
			while (op_set >= 0)
			{
				int mask = 1 << 0;
				for (int i = 0; i < n - 1; i++)
				{
					if (op_set & mask) infix[i * 2 + 1] = '+';
					else  infix[i * 2 + 1] = '*';
					mask = mask << 1;
				}
				string postfix = infixToPostfix(infix);
				int result = evaluate(postfix);
				if (result == right) 
				{
					flag = true;
					break;
				}
				op_set--;
			}
			if (flag == true) {
				result.push_back(1);
			}
			else { result.push_back(0); }
			
		}
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
		result.clear();
	}


	return 0;
}