#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

// 2018 KAKAO BLIND RECRUITMENT
/*
	����Ǯ��
	// 1. ���� ����� n������ ��ȯ�� ������ ���ؾ���
	// 2. ��ȯ�ϴ� ��� �����
	// 3. ��ȸ�ϸ鼭 ���° �ڸ����� �����;��ϴ��� ���ؾ��Ѵ�.

	Ǯ�� ���
	// 1. �ο� m, ���� ���� ����: t
	// �� ��ȯ�Ͽ� ������ ������ ������ t * m ���� Ŀ���� �׸� �����Ѵ�.
	// �� ��ȯ�ϸ鼭 üũ�ؾ���
	// 2. ��ȯ�ϴ� �Լ� (TranferToNFormation)
	// 3. �ڸ��� ��������
*/
string num = "0123456789ABCDEF";
string TranferToNFormation(int curNum, int nFormation)
{
	//curNum �� n������ȯ�Ͽ� ����ִ´�.
	// 1. ���� ����
	// // ���� �������� -> �������� ����
	// // ���� �ȳ������� -> ������ ���� , �� ����
	// ����� �ָ� �������� ��ȯ �Ϸ�.
	// �̶� m�̳� n �� 10 �̻� ������ ��� A �� ġȯ

	string transfered;
	if (curNum == 0)
		return "0";
	while (curNum > 0)
	{
		transfered += num[curNum % nFormation];
		curNum /= nFormation; // ��
	}
	reverse(transfered.begin(), transfered.end());
	return transfered;
}

string solution(int n, int t, int m, int p) {
	string answer = "";
	int maxSize = t * m;
	int idx = 0;
	string transfer;
	while (true)
	{
		transfer += TranferToNFormation(idx, n);
  		if (transfer.length() > maxSize)
			break;
		idx++;
	}

	int cnt = 0;
	for (int i = 0; i < transfer.length(); i++)
	{
		if (answer.length() == t)
			break;
		cnt++;
		if (cnt == p)
			answer += transfer[i];
		if (cnt == m)
			cnt = 0;
	}
	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	//solution(2, 4, 2, 1);
	solution(16, 16, 2, 2);

	return 0;
}