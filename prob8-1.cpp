//�׳� ǰ
#include<iostream>
#include<algorithm>
using namespace std;
int slot[100];
int point[100];
int n, limit;

int main()
{
	ios::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	while (tcase--)
	{
		int result = 0;
		cin >> n >> limit;
		for (int i = 0; i < n; i++)
		{
			cin >> point[i];
		}

		for (int i = 0; i < n; i++)
		{
			int idx, value;
			cin >> value >> idx;
			slot[idx - 1] = value;
		}
		//---������� �Է¹޴°�


		for (int i = 0; i < n; i++)
		{
			
			if (slot[i] == -1) continue; // �̹� �ٸ� ���Ӽ��� ���Խ� -1 �� ������������� an��
			int next = i + 1;
			int val = 0;
			int max = slot[i]; ////���ӵ� ���� ù��°��
			for (int j = i+1; j < n; j++)
			{
				//
				if (slot[j] > max)
				{
					val++;
					max = slot[j];
					slot[j] = -1;	
				}
				else
				{
					next = j;
					break;
				}	
			}
			slot[i] = val;
			result += point[val];
			i = next - 1;
		}

		cout << result<<"\n";
	}

	return 0;
}