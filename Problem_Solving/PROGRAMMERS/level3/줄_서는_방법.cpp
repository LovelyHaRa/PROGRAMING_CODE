#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
	vector<int> answer, people;
	long long fac = 1; // n! ����
	for (int i = 1; i <= n; i++) {
		fac *= i;
		people.push_back(i);
	}
	k--; // �ε���ȭ
	while (n) {
		fac /= n--; 
		answer.push_back(people[k / fac]); // k/fac�� ���� ���� �ڸ��� ����� ������ ��ġ
		people.erase(people.begin() + k / fac); // ���� ����
		k %= fac; // ������ ����
	}
	return answer;
}