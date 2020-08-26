#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	// 1. �������� ����
	sort(people.begin(), people.end());
	int min = 0, max = people.size() - 1;
	// 2. �� ������ ����, ������������ �ݺ�
	while (min < max) {
		// 3. �� ��ġ�� �����Ը� ���ؼ� �¿� �� ������ ���� �� ����
		if (people[min] + people[max] <= limit) {
			min++;
		}
		// 4. �׷��� ������ ������ ������ ���� ȥ�� Ÿ�� ��� �ܿ� �����Ƿ� ��Ʈ�� �߰�
		answer++;
		// 5. ��� ��쿡 ���� ������ �� ����
		max--;
	}
	// 6. ¦�� ���̸� ����(���̰� -1), Ȧ�� ���̸� �ε����� ������
	// Ȧ�� ���� �� �� ���� �Ѹ��� ��Ʈ�� �߰�
	if (min == max)
		answer++;
	return answer;
}