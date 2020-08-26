using namespace std;

// �ִ� �����
long long gcd(int a, int b) {
	if (a > b) return gcd(a%b, b);
	if (a == 0) return b;
	return gcd(b%a, a);
}

long long solution(int w, int h)
{
	// 1. ������ ������ �ݺ��Ǵµ� �� ������ ������ w, h�� �ִ� �������
	// 2. ���� w, ���� h(w, h�� ���μ�)�� �밢������ �������� ��
	//    �������� ���� �簢���� ������ w+h-1
	// 3. �� ������ w, h�� �ִ� ����� ��ŭ �����Ƿ�
	//    w, h�� �ִ������� gcd��� �ϸ� �������� ���� �簢 ���� ������
	//    w/gcd+h/gcd-1
	// 4. 3�� gcd�� ���ϸ� w+h-gcd (����ó�� �ܿ���)
	long long answer = (long long)w*(long long)h;
	// ������ �簢�� = (��ü �簢�� ����) - (�������� ���� �簢�� ����)
	//                      (w * h)                 (w + h - gcd)
	answer -= w + h - gcd(w, h);
	return answer;
}