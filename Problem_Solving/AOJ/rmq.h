#pragma once
#include<vector>

template<typename T>
T min(T a, T b) { return a < b ? a : b; }

const int hugeNum = 1987654321;

template<typename T>
struct range_min_query
{
	int n; // �迭�� ����
	std::vector<T> rangeMin; // ������ �ּڰ� ����
	range_min_query(const std::vector<T>& array)
	{
		n = array.size();
		rangeMin.resize(n * 4);
		init(array, 0, n - 1, 1);
	}
	// node ��尡 array[left..right]�迭�� ǥ���� ��,
	// node�� ��Ʈ�� �ϴ� ����Ʈ���� �ʱ�ȭ�ϰ�, �� ������ �ּ�ġ�� ��ȯ�Ѵ�
	T init(const std::vector<T>& array, int left, int right, int node)
	{
		// �������: ���� ���̰� 1�� ���
		if (left == right)
			return rangeMin[node] = array[left];
		// �������� ������
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}
	// // node�� ǥ���ϴ� ���� array[left..right]�� �־��� ��,
	// �� ������ array[left..right]�� �������� �ּ�ġ�� ���Ѵ�
	T query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		// �� ������ ��ġ�� ������ ���� ū �� ��ȯ: ���õ�
		if (right < nodeLeft || nodeRight < left) return (T)hugeNum;
		// node�� ǥ���ϴ� ������ array[left..right]�� ������ ���ԵǴ� ���
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];
		// ���� ������ ������ Ǭ �� ����� ��ģ��
		int mid = (nodeLeft + nodeRight) / 2;
		return min<T>(query(left, right, node * 2, nodeLeft, mid),
			query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}
	// �������̽�
	T query(int left, int right) { return query(left, right, 1, 0, n - 1); }
};