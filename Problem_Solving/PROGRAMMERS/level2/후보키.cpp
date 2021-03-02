#include <string>
#include <vector>
#include <set>
#include<iostream>

using namespace std;

int solution(vector<vector<string>> relation) {
	set<int> bitset; // �ĺ�Ű ����
	int colSize = relation[0].size(); // �� ������
	int rowSize = relation.size(); // �� ������
	// ��� �κ����� ����(1 ~ 2^colSize-1)
	for (int i = 1; i < (1 << colSize); i++) {
		set<string> rowset; // �� ������ ����
		// �� Ž��
		for (int j = 0; j < rowSize; j++) {
			string rowData; // �� ������
			// �� �����ŭ Ž��
			for (int k = 0; k < colSize; k++) {
				// ���� �κ������߿� 1�� ���� ��������� ������ ����
				if (i&(1 << k)) {
					rowData += relation[j][k] + ',';// ������ ����(,�� ����)
				}
			}
			// ������� �� �����͸� ���տ� �߰�
			rowset.insert(rowData);
		}
		// �� ������������ ���� �� ������ ���� ��ġ�ϸ� ���ϼ� ����
		if (rowSize == rowset.size()) {
			// �ĺ�Ű ���� Ž��
			set<int>::iterator iter;
			for (iter = bitset.begin(); iter != bitset.end(); iter++) {
				int t = *iter; // �ĺ�Ű ������ ����
				if ((t&i) == t) break; // �ĺ�Ű ���Ұ� i�� �κ������̸� �ּҼ��� �������� ����
			}
			// �̹� ���Ե� �ĺ�Ű�� ã�� ���ϸ� �ĺ�Ű ���տ� �߰�
			if (iter == bitset.end()) bitset.insert(i);
		}
	}
	// �ĺ�Ű ������ ������ ����
	return bitset.size();
}