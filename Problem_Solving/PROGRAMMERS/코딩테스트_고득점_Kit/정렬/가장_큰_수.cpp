#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 4 : ���Լ�
// ����, �������� ��ģ ����� ������������ ��
bool compare(const string a, const string b)
{
	string ab = a + b; // ����
	string ba = b + a; // ����
	return ab > ba ? true : false; // �������� ��
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> str;
	// 1. 0 ���� �˻�
	// 2. ���ڸ� ���ڷ� ġȯ�Ͽ� �迭�� ����
	// 3. �־��� ���� ��� 0�̸� 0 �ϳ��� ��ȯ
	// 4. �� ���ڿ��� ����, �������� ���ļ� ������ �� �������� ����
	// 5. ���� ����� �ϳ��� ���ڿ��� �����
	int zero = 0;
	for (int i : numbers)
	{
		// 1
		if (!i)
			zero++;
		str.push_back(to_string(i)); // 2
	}
	// 3
	if (numbers.size() == zero)
		return "0";
	// 4
	sort(str.begin(), str.end(), compare);
	// 5
	for (auto i : str)
		answer += i;
	return answer;
}