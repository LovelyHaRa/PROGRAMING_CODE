#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
	// �ְ��� ������ ����
	// 1. ���� S�� �Ǵ� ���� ���յ� �� ���� �ִ밪�� ������ ��� ���Ұ����� ���밪�� �ּҰ� �Ǿ����
	// 2. 1�� ������ �����ϴ� ������ �ߺ��� ���� �ִ��� ���� ������(���밪 0)
	// 3. S�� n���� ���� ǥ���ҷ��� (S/n) n-1��, (s/n+s%n) 1���� ǥ�� ����
	// 4. ������ 1,2�� ������ �����Ϸ��� (s/n+1) s%n��, s/n�� n-s%n �� �־���Ѵ�
	vector<int> answer;
	// �ְ��� ������ �������� �ʴ� ���
	if (n > s) {
		answer.resize(1, -1);
		return answer;
	}
	answer.resize(n);
	int div = s / n; // ��
	int mod = s % n; // ������
	// �ڿ��� ���� ����(�������� �迭 ����)
	for (int i = n - 1; i >= 0; i--)
	{
		int p;
		p = (mod-- > 0) ? 1 : 0; // 1�� ������ ���� ����
		answer[i] = div + p;
	}
	return answer;
}