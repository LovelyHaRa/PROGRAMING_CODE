#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	// ���� �ð������ Ž���ϴٰ�
	// �������� ������ �� �� ������ count�� ����
	// �������� �׻� 0�̹Ƿ� 0 �߰�
	for (int i = 0; i < prices.size() - 1; i++)
	{
		int count = 0;
		for (int j = i + 1; j < prices.size(); j++) {
			if (prices[i] > prices[j] || j == prices.size() - 1) {
				count = j - i;
				break;
			}
		}
		answer.push_back(count);
	}
	answer.push_back(0);
	return answer;
}