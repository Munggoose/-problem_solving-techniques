#include <iostream>
#include <vector>
using namespace std;

float CalcMedian(int CntArray[], int D) {   //CntArray[] �ʿ� �迭�ּҰ� �Ѿ��. ���� �迭�� ���⼭ �����ϸ� main�� �迭�� �����
    if (D % 2 != 0) {   // Ȧ���� ���
        int median = D / 2;      // D�� int �̹Ƿ� �̷��� �����ָ� �Ҽ����� ���ŵȴ�.
        int count = 0;
        int index;
        for (int i = 0; i < 201; i++) {      // for�� ���ؼ� CntArray ��ü�� ���ǵ� �� CalcMedian �Լ��� ȣ���ϱ����� CntArray���� D�� ��ŭ�� 1�� ä���� �����Ƿ� �� for������ break �ɾ��ָ� �ȴ�.
            count += CntArray[i];
            if (count > median) {      // �� ��ó���� ���⸦ count == median���� �ߴµ� �̷����ϸ� ������ ���ڰ� ������ ���� ��� ex) 2 3 3 4 5 �̷��� ���� ��� count�� �ٷ� 3���� �پ������ �� if���� �ɸ��� �ʰ� ��
                                 // ���� count >= median ���� ������� ������� d=5�϶� 2��° ĭ������ +1 ���൵ ���� count = 2�� �ǹ����� �ᱹ �ι�° ĭ�� �ε����� �����ع���.
                                 // �̶� 3��° ĭ�� �ε����� �����ؾ� �ϹǷ� count > median���� �����ؾ���
                index = i;
                break;
            }
        }
        return index;      // index�� �� expenditure�� �� �ִ� ���� �ǹ���
    }

    else {      // ¦���� ���
        int median = D / 2;
        int count = 0;
        float firstIndex = 0;
        float secondIndex = 0;
        for (int i = 0; i < 201; i++) {
            count += CntArray[i];
            if ((count >= median) && firstIndex == 0) {
                firstIndex = i;
            }

            if ((count >= median + 1) && secondIndex == 0) {      // �ι�°�� ���ػ��� �� ���� ã�Ҵٸ� 
                                                   // 
                secondIndex = i;
                break;
            }
        }

        return (firstIndex + secondIndex) / 2.0;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;

    vector<int> Expenditure;


    for (int i = 0; i < T; i++) {
        int D, N, temp;
        float median;            // �̰� �� !!!! float�� ����!!!! �׷����� ¦���� ������ median ���� �� �Ҽ����� �� ��´�.
        int alarmCount = 0;
        int CntArray[201] = { 0, };   // 0 ~ 200�� �ε����� ������ int�� �迭 ����
                          // ���� CntArray�� �Ʒ����� �ԷµǴ� d��ŭ���� �ٷ����.
        cin >> N;
        cin >> D;

        for (int j = 0; j < N; j++) {
            cin >> temp;
            Expenditure.push_back(temp);
        }

        for (int j = 0; j < D; j++) {      // D ��ŭ���� �ٷ������
            CntArray[Expenditure[j]] += 1;
        }

        // median �� ����ϱ� ���� �ݺ���
        for (int j = D; j < N; j++) {
            median = CalcMedian(CntArray, D);
            if ((2 * median) <= Expenditure[j]) {
                alarmCount += 1;
            }
            CntArray[Expenditure[j]] += 1;   // Expenditure[j]�� ��� median ���� ���� ��. �� ������ CntArray�� ���� ���̹Ƿ� �̷��� �߰�����.
            CntArray[Expenditure[j - D]] -= 1; //CntArray �� �տ� �ִ� ���� ���� median ���� �� ������ ���̹Ƿ� �̷��� �ؼ� ����
        }

        cout << alarmCount << endl;
        vector<int>().swap(Expenditure);
    }

    return 0;
}