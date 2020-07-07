//������ �ƴ� 200������ ������ ���� ����(d�����ȿ�) ��������°��� ����� �߰��Ǵ°��� ���ϴ°����� ����
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> expend;
int n, d;

float cal_median(int cnt[], int d)
{
	if (d % 2 != 0)
	{
		int med = d / 2;
		int count = 0;
		int idx;
		for (int i = 0; i < 201; i++)
		{
			count += cnt[i];
			if (count > med)
			{
				idx = i;
				break;
			}
		}
		return idx;
	}
	else
	{
		int med = d / 2;
		float count = 0;
		float firstIdx = 0;
		float secondIdx = 0;
		for (int i = 0; i < 201; i++)
		{
			count += cnt[i];
			if ((count >= med ) && firstIdx == 0)
			{
				firstIdx = i;
			}
			if ((count >= (med+1)) && secondIdx == 0)
			{
				secondIdx = i;
				break;
			}
		}

		return (secondIdx + firstIdx) / 2.0;
	}
	

	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	while (tcase--)
	{
		int cnt[201] = {0,};
		int alarm = 0;
		float med; //d���� ¦���϶� �Ҽ����� ���ü� �����Ƿ� 
		cin >> n >> d;
		for (int i = 0; i < n; i++)
		{
			int val;
			cin >> val;
			expend.push_back(val);
		}

		for (int i = 0; i < d; i++)
		{
			cnt[expend[i]] += 1;
		}

		for (int i = d; i < n; i++)
		{
			 med = cal_median(cnt, d);
			if ((2 * med) <= expend[i])
			{
				alarm++;
			}
			cnt[expend[i]] += 1;
			cnt[expend[i - d]] -= 1;
		}
		cout << alarm << "\n";
		expend.clear();
	}
	return 0;
}