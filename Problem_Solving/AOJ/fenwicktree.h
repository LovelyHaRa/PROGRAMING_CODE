#pragma once
#include<vector>

// ���� Ʈ���� ����. ������ �迭 A[]�� �κ�����
// ������ ������ �� �ֵ��� �Ѵ�.
// �ʱ�ȭ�ÿ��� A[]�� ���Ұ� ���� 0�̶�� �����Ѵ�
template<typename T>
struct fenwick_tree
{
	std::vector<T> tree;
	fenwick_tree(int n) : tree(n + 1) {}
	// pos ������ �κ����� ���Ѵ�
	T sum(int pos)
	{
		// �ε����� 1���� ����
		pos++;
		int ret = 0;
		while (pos > 0)
		{
			ret += tree[pos];
			// ���� ��Ʈ�� ����� ����
			pos &= (pos - 1);
		}
		return ret;
	}
	// A[pos]�� val�� ���Ѵ�
	void add(int pos, T val)
	{
		pos++;
		while (pos < tree.size())
		{
			tree[pos] += val;
			// ������ ��Ʈ�� ������ ���ϴ� ����
			pos += (pos&-pos);
		}
	}
};
