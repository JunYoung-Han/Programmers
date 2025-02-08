#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

/*
	����Ǯ��

	1. ���� Head�� number�� �����ش� �Լ�
	2. head �κ����� ���� �� ����
	// �� �̶� �ҹ��ڷ� üũ, ������ ���, �Է¼�����
	3. ���� Number�� ����
	// �� 0023 ���� ���ڿ� 12�� ���ϴ� �Լ� �����

	�Ǽ� ����!!!
	sort �ҰŸ� sort ����� vector�� ������ �̷���� compare �Լ��� ������ �Ѵ�.
	���� sort�� �ε����� ����� ���͸� �ϰ� compare �Լ��� �ش� �ε����� �����ϴ� map���� ���� ������ ���ϴ� ������ �ߴ�.
	�̷��� �ȵȴ�!!!

*/

using namespace std;

unordered_map<int, string> dp;

string solve(int n) {
	if (dp.count(n)) return dp[n];

	if (n < 4) return vector<string>{"4", "1", "2", "4"} [n] ;

	return dp[n] = solve((n - 1) / 3) + solve(n % 3);
}

string solution(int n) {
	return solve(n);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution(1);

	return 0;
}