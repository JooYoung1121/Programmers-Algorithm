#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

long long min_ll(long long a, long long b) { return a < b ? a : b; }

inline long long cal_cost(vector<vector<int> >& land, int P, int Q, long long check, int n) {		// &�����ڸ� ���� ������ ������ �ð��ʰ�..

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += (land[i][j] - check) * (land[i][j] - check > 0 ? Q : -P);
		}
	}
	return ans;
}

// �Ķ��Ʈ�� ��ġ �̿�! 
long long solution(vector<vector<int> > land, int P, int Q)
{
	long long answer = LONG_MAX;
	int n = land.size();
	int low = 0;
	int high = 1000000000;
	int mid = 0;

	// ��� �׷����� �Ʒ��� ����
	// �Ʒ��� ������ �׷����� ���Ⱑ 0�϶� �ּҰ�. ���� ���� 0�� ���� Ž��
	while (low <= high) {
		mid = (low + high) / 2;
		unsigned long long pos1 = cal_cost(land, P, Q, mid, n);
		unsigned long long pos2 = cal_cost(land, P, Q, mid + 1, n);
		if (pos1 == pos2)
			break;
		if (pos1 < pos2)
			high = mid - 1;
		else
			low = mid + 1;
	}
	// �ٻ簪�̱� ������ �յڰ��� �ѹ��� �˻�
	for (int i = mid - 1; i <= mid + 1; i++)
		answer = min(answer, cal_cost(land, P, Q, i, n));

	return answer;
}

/*

//���Ž�� �̿�! 
long long solution(vector<vector<int> > land, int P, int Q)
{
	long long answer = LONG_MAX;
	int n = land.size();
	double low = 0;
	double high = 0;

	for (int i = 0; i < land.size(); i++) {
		for (int j = 0; j < land[i].size(); j++) {
			high = max(high, (double)land[i][j]);
		}
	}

	// ��� �׷����� �Ʒ��� ����
	// �Ʒ��� ������ �׷����� ���Ⱑ 0�϶� �ּҰ�. ���� ���� 0�� ���� Ž��
	double aab, abb;
	long long pos1, pos2;
	for (int i = 0; i < 50; i++) {
		aab = (2 * low + high) / 3.0;
		abb = (low + 2 * high) / 3.0;
		pos1 = cal_cost(land, P, Q, aab, n);
		pos2 = cal_cost(land, P, Q, abb, n);
		if (pos1 > pos2)
			low = aab;
		else
			high = abb;
	}
	double mid = (low + high) / 2;
	// �ٻ簪�̱� ������ �յڰ��� �ѹ��� �˻�
	for (int i = mid - 3; i <= mid + 3; i++)
		answer = min_ll(answer, cal_cost(land, P, Q, i,n));

	return answer;
}

// �ٸ� ��� Ǯ�� -> �ð����⵵�� ����!
long long solution(vector<vector<int> > land, int P, int Q)
{
	long long answer = -1;
	int N = land.size();
	vector<long long > v;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			v.push_back(land[i][j]);
	sort(v.begin(), v.end());

	long long temp = 0;
	for (int i = 0; i < v.size(); i++)
		temp += (v[i]-v[0]) * Q;

	answer = temp;

	for (int i = 1; i < v.size();i++) {

		int down = i;
		int up = v.size() - i;

		temp += down * (v[i] - v[i - 1])*P;
		temp -= up * (v[i] - v[i - 1])*Q;
		if (answer > temp)
			answer = temp;
	}
	return answer;
}
*/


