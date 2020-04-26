#include <string>
#include <vector>
#include<algorithm>

using namespace std;

string to_lower(string s) {
	string res;
	for (int i = 0; i < s.size(); i++) {
		res += tolower(s[i]);
	}
	return res;
}

bool compare(vector<string> a, vector<string> b) {
	// head ����
	string h1 = to_lower(a[0]), h2 = to_lower(b[0]); // ���ڿ� lowercase
	// ������ ���� ��
	if (h1 == h2) {
		return stoi(a[1]) < stoi(b[1]);
	}
	// �ٸ��� head ��
	else return h1 < h2;
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	// 0, 1, 2 => head, number, tail
	vector<vector<string>> k(files.size(), vector<string>(3));
	// 1. ���ϸ� �и�
	for (int i = 0; i < files.size(); i++) {
		int j = 0;
		string t;
		// head �и�
		while (j < files[i].size()) {
			// ���ڰ� ó�� �߰ߵǸ� ����
			if (files[i][j] >= '0' && files[i][j] <= '9') {
				break;
			}
			t += files[i][j++]; // ���� ����
		}
		k[i][0] = t; // head ����
		t = ""; // �ʱ�ȭ
		// number �и�
		while (j < files[i].size()) {
			// ���ڰ� ������ ����
			if (files[i][j]<'0' || files[i][j]>'9') {
				break;
			}
			t += files[i][j++];
		}
		k[i][1] = t; // number ����
		k[i][2] = files[i].substr(j); // ������(tail) ����
	}
	// 2. ���� ����: ���� ���� ���� ������ ����Ǵ� ����
	stable_sort(k.begin(), k.end(), compare);
	// 3. ���� ��� ���
	for (int i = 0; i < k.size(); i++) {
		string t = k[i][0] + k[i][1] + k[i][2];
		answer.push_back(t);
	}
	return answer;
}

int main(void) {
	solution({ "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" });
}