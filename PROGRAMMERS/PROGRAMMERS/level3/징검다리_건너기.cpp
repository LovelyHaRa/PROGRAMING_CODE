#include <string>
#include <vector>

using namespace std;

// ����: n����� ¡�˴ٸ��� �ǳ� �� ���� ����� �ǳμ� �ִ��� ���θ� ��ȯ
bool decision(const vector<int>& stones, int k, int n) {
	int cnt = 0, max = 0; // �ǳ� �� ���� ���� ����, �ִ� ����
	for (int i = 0; i < stones.size(); i++) {
		int k = stones[i] - n; // n���� �ǳʹ�
		// �ǳ� �� ���� ���� ���� ����
		if (k <= 0)
			cnt++;
		else {
			max = max < cnt ? cnt : max;
			cnt = 0;
		}
	}
	// max���� �ѹ��� ���� �ȉ��� ���� �����Ƿ� ����
	max = max < cnt ? cnt : max;
	// ���̰� k���� ª�ƾ� ��������� �ǳ� �� �ִ�
	return max < k;
}
// ����ȭ: �̺�Ž������ ¡�˴ٸ��� �ǳ� �� �ִ� ���°� �Ǵ� �ּ��� n�� ���Ѵ�
int optimize(const vector<int>& stones, int k) {
	int lo = 0, hi = 2e8; // �ּ�: �ƹ��� �Ȱǳʴ� ���, �ִ�: ���� ����
	// �̺� Ž��
	for (int i = 0; i < 100; i++) {
		int mid = (lo + hi) / 2;
		// ¡�˴ٸ��� �ǳ� �� �ִ� �����̸�
		if (decision(stones, k, mid))
			lo = mid; // �� ū���� ã�ƺ���
		// �׷��� �ʴٸ�
		else
			hi = mid; // �� ���� ���� ã�ƺ���
	}
	return lo; //�ּڰ��� ���� �ؾ� �ϹǷ� lo ����
}

int solution(vector<int> stones, int k) {
	int answer = 0;
	return optimize(stones, k) + 1; // 1�� �� �ǳ� �� �����Ƿ� +1
}