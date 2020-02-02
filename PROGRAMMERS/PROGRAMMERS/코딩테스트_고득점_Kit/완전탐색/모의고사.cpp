#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> count(3, 0); // ���� ���� ī����
	vector<int> answer;
	// ������ ��� ����
	int a[5] = { 1,2,3,4,5 };
	int b[8] = { 2,1,2,3,2,4,2,5 };
	int c[10] = { 3,3,1,1,2,2,4,4,5,5 };
	int idx = 0;

	while (idx != answers.size())
	{
		// ���� ���� ī����
		count[0] = answers[idx] == a[idx % 5] ? count[0] + 1 : count[0];
		count[1] = answers[idx] == b[idx % 8] ? count[1] + 1 : count[1];
		count[2] = answers[idx] == c[(idx++) % 10] ? count[2] + 1 : count[2];
	}
	// �ִ밪 ���ϱ�
	int max = (count[0] > count[1])
		? ((count[0] > count[2]) ? 0 : 2)
		: ((count[1] > count[2]) ? 1 : 2);
	// �����ڵ� ������������ ����ؾ���
	for (int i = 0; i < 3; i++)
	{
		if (count[max] == count[i])
			answer.push_back(i + 1);
	}
	return answer;
}