#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ���̸� �������� �������� ��
bool compare(vector<int>&a, vector<int>&b) {
	return a.size() < b.size() ? true : false;
}

// �� �迭 ���̿� ������� �ʴ� ���� �ϳ��� �����ϴ� �Լ�
int difference(vector<int>&a, vector<int>&b) {
	for (int i = 0; i < a.size(); i++) {
		int j;
		for (j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) break;
		}
		if (j == b.size())
			return a[i];
	}
	return 0;
}

vector<int> solution(string s) {
	vector<int> answer;
	vector<vector<int>> tuple;
	vector<int> sub;
	int k = 0;
	// 1. tuple �迭 �����
	for (int i = 1; i < s.size() - 1; i++) {
		// ���� �߰�ȣ�� ����
		if (s[i] == '{') continue;
		// �ݴ� �߰�ȣ�� ���
		else if (s[i] == '}') {
			sub.push_back(k); // ���տ� ���� ����
			tuple.push_back(sub); // Ʃ�� �迭�� ���� ����
			sub.clear(); // ���� �ʱ�ȭ
			k = 0; // ���� �ʱ�ȭ
		}
		// �޸��� ���
		else if (s[i] == ',') {
			// ���� ���ڿ��� �ݴ� �߰�ȣ�̸� �ƹ��͵� ����
			if (s[i - 1] == '}') continue;
			sub.push_back(k); // ���տ� ���� ����
			k = 0; // ���� �ʱ�ȭ
		}
		// ������ ���
		else {
			k *= 10; // �ڸ��� ����
			k += s[i] - '0';  // ���� ����
		}
	}
	// 2. ���� ���̸� �������� ����
	sort(tuple.begin(), tuple.end(), compare);
	// 3. �ʱⰪ push
	answer.push_back(tuple[0][0]);
	// 4. i, i-1 �迭�� �� �Ͽ� ������� �ʴ� ���� push 
	for (int i = 1; i < tuple.size(); i++) {
		answer.push_back(difference(tuple[i], tuple[i - 1]));
	}
	// ��� �迭 ���
	return answer;
}

int main(void) {
	solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
}