#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
const int MAX = 1e7;
int prime[MAX];

// �����佺�׳׽��� ü�� �̿��Ͽ� �Ҽ� ���̺� ����
void setPrime()
{
	prime[0] = prime[1] = -1;
	for (int i = 2; i <= MAX; i++)
		prime[i] = i;
	for (int i = 2; i*i <= MAX; i++) {
		if (prime[i] == i)
		{
			for (int j = i * i; j <= MAX; j += i) {
				if (prime[j] == j)
					prime[j] = i;
			}
		}
	}
}

int solution(string numbers) {
	int answer = 0;
	vector<int> num; // ���� ������ ����
	map<int, bool> visited; // �ߺ� �� ���� üũ�ϱ� ����
	// 1. �Ҽ����̺� ����
	// 2. ���� ������ ����
	// 3. 1���� ���� �ڸ� �������� ���� Ž��
	// 4. ���� ����
	// 5. ���� �ڸ� ����ŭ ���� ��ġ��
	// 6. �ߺ� ���� �˻�
	// 7. �Ҽ� �˻�
	// 1
	setPrime();
	// 2
	for (int i = 0; i < numbers.length(); i++)
		num.push_back(numbers[i] - '0');
	// 3
	for (int i = 1; i <= num.size(); i++)
	{
		// 4
		sort(num.begin(), num.end());
		do
		{
			// 5
			string s;
			for (int j = 0; j < i; j++) {
				// ù°�ڸ��� 0�� ���� ����
				if (s.empty() && num[j] == 0)
					continue;
				s += num[j] + '0';
			}
			// ���ڰ� ������� �ʾҴٸ�(0�̶��);
			if (s.empty())
				continue;
			// ���� ��ȯ
			int k = stoi(s);
			// 6
			if (visited.count(k))
				continue;

			visited[k] = true; // ���� Ž���� ��, �ߺ� üũ
			// 7
			if (prime[k] == k)
				answer++;
		} while (next_permutation(num.begin(), num.end())); // 4
	}
	return answer;
}