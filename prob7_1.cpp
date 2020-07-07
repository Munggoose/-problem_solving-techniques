//next_permutation
//long 데이터타입문제
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
long n, a, b, k;
vector<long> NN;

long solve(vector<long> v, long xval, long _size)
{
	long answer = 0;

	for (long i = 0; i < _size ; i++)
	{
		long p = v[i] * pow(xval, i);
		long tmp = p % 1013;
		answer += tmp;
	}
	return answer % 1013;
}

int main()
{
	long tcase = 0;
	cin >> tcase;
	while (tcase--)
	{
		vector<long> result;
		cin >> n;
		for (long i = 0; i < n; i++)
		{
			long val;
			cin >> val;
			NN.push_back(val);
		}
		
		cin >> a >> b >> k;
		sort(NN.begin(), NN.end());
		result.push_back(solve(NN, k,n));
		while (true)
		{
			if (next_permutation(NN.begin(), NN.end()) == false)break;
			result.push_back(solve(NN, k,n));
		}
		
		long count = 0;
		long asize = result.size();
		for (long i = 0; i < asize; i++)
		{
			if (result[i] >= a && result[i] <= b) count++;
		}
		cout << count << "\n";
		result.clear();
		NN.clear();
	}

	return 0;
}