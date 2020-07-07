#include <iostream>
#include <vector>
using namespace std;

float CalcMedian(int CntArray[], int D) {   //CntArray[] 쪽에 배열주소가 넘어옴. 따라서 배열을 여기서 수정하면 main쪽 배열도 변경됨
    if (D % 2 != 0) {   // 홀수일 경우
        int median = D / 2;      // D가 int 이므로 이렇게 나눠주면 소수점은 제거된다.
        int count = 0;
        int index;
        for (int i = 0; i < 201; i++) {      // for문 통해서 CntArray 전체를 돌건데 이 CalcMedian 함수를 호출하기전에 CntArray에는 D개 만큼만 1로 채워져 있으므로 이 for문에서 break 걸어주면 된다.
            count += CntArray[i];
            if (count > median) {      // 나 맨처음엔 여기를 count == median으로 했는데 이렇게하면 동일한 숫자가 여러개 있을 경우 ex) 2 3 3 4 5 이렇게 있을 경우 count가 바로 3으로 뛰어버려서 이 if문에 걸리지 않게 됨
                                 // 또한 count >= median 으로 했을경우 예를들어 d=5일때 2번째 칸까지만 +1 해줘도 벌써 count = 2가 되버려서 결국 두번째 칸의 인덱스를 저장해버림.
                                 // 이때 3번째 칸의 인덱스를 저장해야 하므로 count > median으로 구성해야함
                index = i;
                break;
            }
        }
        return index;      // index가 곧 expenditure에 들어가 있는 수를 의미함
    }

    else {      // 짝수일 경우
        int median = D / 2;
        int count = 0;
        float firstIndex = 0;
        float secondIndex = 0;
        for (int i = 0; i < 201; i++) {
            count += CntArray[i];
            if ((count >= median) && firstIndex == 0) {
                firstIndex = i;
            }

            if ((count >= median + 1) && secondIndex == 0) {      // 두번째로 기준삼을 수 까지 찾았다면 
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
        float median;            // 이거 꼭 !!!! float로 해줘!!!! 그래야지 짝수일 때에도 median 구할 때 소숫점을 잘 찍는다.
        int alarmCount = 0;
        int CntArray[201] = { 0, };   // 0 ~ 200의 인덱스를 가지는 int형 배열 선언
                          // 여기 CntArray를 아래에서 입력되는 d만큼씩만 다룰것임.
        cin >> N;
        cin >> D;

        for (int j = 0; j < N; j++) {
            cin >> temp;
            Expenditure.push_back(temp);
        }

        for (int j = 0; j < D; j++) {      // D 만큼씩만 다뤄줘야함
            CntArray[Expenditure[j]] += 1;
        }

        // median 값 계산하기 위한 반복문
        for (int j = D; j < N; j++) {
            median = CalcMedian(CntArray, D);
            if ((2 * median) <= Expenditure[j]) {
                alarmCount += 1;
            }
            CntArray[Expenditure[j]] += 1;   // Expenditure[j]는 방금 median 값과 비교한 값. 즉 다음에 CntArray에 넣을 값이므로 이렇게 추가해줌.
            CntArray[Expenditure[j - D]] -= 1; //CntArray 맨 앞에 있던 값은 다음 median 구할 때 빠지는 값이므로 이렇게 해서 제거
        }

        cout << alarmCount << endl;
        vector<int>().swap(Expenditure);
    }

    return 0;
}