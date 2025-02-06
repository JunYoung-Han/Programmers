#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

/*
	���� Ǯ��

	������ ���� �������� �˾Ҵµ�, ���� ������ ��������.
	������ ���� �ĵ� �ʿ��ϰ�,
	���������� �ٿ����ϴ� ����� �����ؾ� �Ѵ�.

	1. ���� �ߺ��Ǵ� ������ ������ ���Ժ��� map�� ����

	2. �� map�� ������ ���� ¦������ �� �ִ� ������ ���� ���Ѵ�.
	�� (������ n ���� 2���� �̴� ����� ��) �� �����ϸ� �ȴ�.

	3. �ش� map�� ��ȸ�ϸ鼭 �� ���԰� ���� ¦������ �Ǻ��Ѵ�.
	�� �̶� ¦���� �ȴٸ�, ����A �� ���� x ����B�� ���� �� ���־�� �ش� ���԰� ¦�������� ������ ������ ���� �� �ִ�.

	* ������ ���� �� long long ������ ��ȯ�ؼ� answer�� �־�� �Ѵ�.
	�� �ִ� ������ int ���� ���� �� �ֱ� �����̴�.

*/

using namespace std;

bool IsPair(int weightA, int weightB)
{
	if (weightA * 2 == weightB * 3
		|| weightA * 2 == weightB * 4
		|| weightA * 3 == weightB * 4
		|| weightB * 2 == weightA * 3
		|| weightB * 2 == weightA * 4
		|| weightB * 3 == weightA * 4)
		return true;

	return false;
}

long long solution(vector<int> weights) {
	long long answer = 0;

	map<long, long long> m;
	for (int i = 0; i < weights.size(); i++)
		m[weights[i]] += 1;

	vector<int> vec;
	for (auto& pair : m)
	{
		long long count = pair.second;
		if (count > 1)
			answer += ((count * (count - 1)) / 2); // ���� ��� �߰�
		vec.push_back(pair.first);
	}

	for (int i = 0; i < vec.size() - 1; i++)
	{
		int weight = vec[i];
		for (int j = i + 1; j < vec.size(); j++)
		{
			if (IsPair(weight, vec[j]))
				answer += (long)(long)(m[weight] * m[vec[j]]);
		}
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution({ 100, 150, 200 });

	return 0;
}