#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	// 1. ����
	// 2. �Է� ��ȭ��ȣ ���� -1 ��ŭ Ž��
	// 3. ���� ��ȭ��ȣ ���̰� ���� ��ȭ��ȣ ���� ���� ���� ��
	// 4. find�� �̿��� ���ڿ��� �˻�, ���� �ε����� 0�̸� break
	// 5. ������ Ž���ϸ� YES �ƴϸ� NO

	// 1
	sort(phone_book.begin(), phone_book.end());
	// 2
	for (int i = 0; i < phone_book.size() - 1; i++)
	{
		// 3
		if (phone_book[i].length() < phone_book[i + 1].length())
		{
			// 4
			if (!phone_book[i + 1].find(phone_book[i]))
			{
				answer = false;
				break;
			}
		}
	}
	// 5
	return answer;
}