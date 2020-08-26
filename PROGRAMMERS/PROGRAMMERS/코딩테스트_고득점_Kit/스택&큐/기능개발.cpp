#include <string>
#include <vector>
#include <stack>

using namespace std;

// ���� �̿�
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	stack<int> s;
	// 1. �۾� �迭 �ε��� ���ÿ� �ױ�
	// 2. ������ �������� �Ʒ� ���� �ݺ�
	// 3. �۾�����
	// 4. ���ð��� �ε����� �ؼ� 100�̸��� ���� ���ö� ���� ī��Ʈ �� pop
	// 5. �ѹ��̶� pop ������ answer�� �߰�
	
	// 1
	int n = progresses.size() - 1;
	while (n >= 0)
		s.push(n--);
	// 2
	while (!s.empty()) {
		// 3
		for (int i = 0; i < progresses.size(); i++)
			progresses[i] += speeds[i];
		// 4
		int count = 0;
		while (progresses[s.top()] >= 100)
		{
			s.pop();
			count++;
			if (s.empty())
				break;
		}
		// 5
		if (count > 0)
			answer.push_back(count);
	}
	return answer;
}