#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int answer = -1;
void go(int N, int number, int sum, int cnt) {
	if (cnt > 8) {			// ��������
		return;
	}
	if (number == sum) {	// �Ϸ�����
		if (cnt < answer || answer == -1) {		// ���� answer������ ������ �־���
			answer = cnt;
		}
		return;
	}

	int nn = 0;
	for (int i = 0; i < 8; i++) {
		nn = nn * 10 + N;		// N, NN, NNN, NNNN .....
		go(N, number, sum + nn, cnt + 1 + i);		// i�� N�� � �پ��ִ� ��
		go(N, number, sum - nn, cnt + 1 + i);
		go(N, number, sum * nn, cnt + 1 + i);
		go(N, number, sum / nn, cnt + 1 + i);

	}
}
int solution(int N, int number) {
	go(N, number, 0, 0);
	return answer;
}
