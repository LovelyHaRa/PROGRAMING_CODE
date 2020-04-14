#include <string>
#include <vector>
#include <set>

using namespace std;

bool isAlpa(char a) {
	return a >= 'a' && a <= 'z';
}

vector<string> getUnion(string s) {
	vector<string> res;
	for (int i = 0; i < s.size() - 1; i++) {
		char a = tolower(s[i]), b = tolower(s[i + 1]);
		if (isAlpa(a) && isAlpa(b)) {
			string t;
			t += a;
			t += b;
			res.push_back(t);
		}
	}
	return res;
}

int solution(string str1, string str2) {
	int answer = 0;
	vector<string> s1;
	vector<string> s2;

	// 1. �������� �����
	s1 = getUnion(str1);
	s2 = getUnion(str2);

	// 2. �������̸� 1*65536 ����
	if (s1.empty() && s2.empty()) {
		return 65536;
	}

	// 3. ������, ������ ���� ���ϱ�
	set<int> check; // �ߺ��Ǵ� �ε��� üũ
	int count = 0; // ������ ����
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			// ���Ұ� �Ȱ����� ������ ���� ����
			if (!s1[i].compare(s2[j]) && !check.count(j)) {
				count++;
				check.insert(j); // �ߺ� üũ
				break;
			}
		}
	}
	// ������ ���� ������ �̿�
	int ucount = s1.size() + s2.size() - count;
	// 4. ��ī�� ���絵 ���
	double j = count / (double)ucount * 65536;
	answer = (int)j;
	return answer;
}