#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	priority_queue<int> pq; // �켱���� ť
	queue<pair<int, int>> q; // �ε����� �������� ���� ť�� ����
	for (int i = 0; i < priorities.size(); i++) {
		pq.push(priorities[i]);
		q.push({ i,priorities[i] });
	}
	// �켱���� ť�� ���� ������ ������ �������� ���ĵǾ� ����
	// 1. ť���� ���� ������.
	// 2. �켱���� ť�� �������� ���Ѵ�
	// 3. ������ �켱���� ť���� �� ������ answer ����
	// 4. �ε����� ��ǥ��ġ�̸� break
	// 5. 2�� false�̸� �ٽ� ť�� �������
	while (!q.empty())
	{
		// 1
		int index = q.front().first;
		int pri = q.front().second;
		q.pop();
		// 2
		if (pri == pq.top())
		{
			// 3
			pq.pop(); 
			answer++;
			// 4
			if (index == location)
				break;
		}
		// 5
		else
			q.push({ index,pri });
	}
	return answer;
}

int main(void)
{	
	solution({ 2,1,3,2 }, 2);
}