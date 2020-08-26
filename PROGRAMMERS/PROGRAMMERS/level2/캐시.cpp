#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	// linked list �� ĳ�� ����
	list<string> l;
	map<string, list<string>::iterator> m;
	// 1. ĳ�� ����� 0 �̸� ĳ�� ���� �Ұ��� �̹Ƿ� ������*5 ����
	if (!cacheSize) { return cities.size() * 5; }
	// 2. cities Ž��
	for (int i = 0; i < cities.size(); i++) {
		// 3. ���� cities uppercase
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), (int(*)(int))toupper);
		// 4. ĳ�� miss ��
		if (m.find(cities[i]) == m.end()) {
			// 4-1. ĳ�ð� �� ����
			if (cacheSize == l.size()) {
				// 4-2. ����Ʈ ������ ���Ҹ� ����
				string last = l.back();
				l.pop_back();
				m.erase(last);
			}
			// �ð� �߰�
			answer += 5;
		}
		// 5. ĳ�� ���� ��
		else {
			// 5-1. ����Ʈ���� �ش� ĳ�ð� ���� (LRU ������ ����)
			l.erase(m[cities[i]]);
			// �ð� �߰�
			answer += 1;
		}
		// 6. ����Ʈ ���ʿ� ���� �� �߰� (ĳ�� �̽�, ���� ���������� ����)
		l.push_front(cities[i]);
		// iterator ����
		m[cities[i]] = l.begin();
	}
	return answer;
}