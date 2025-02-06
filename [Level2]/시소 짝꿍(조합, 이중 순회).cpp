#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

/*
	문제 풀이

	간단한 조합 문제인줄 알았는데, 함정 투성인 문제였다.
	순열의 조합 식도 필요하고,
	이중포문을 줄여야하는 방법도 생각해야 한다.

	1. 먼저 중복되는 무게의 개수를 무게별로 map에 저장

	2. 각 map의 개수가 서로 짝지어질 수 있는 조합의 수를 구한다.
	ㄴ (동일한 n 개중 2개를 뽑는 경우의 수) 를 생각하면 된다.

	3. 해당 map을 순회하면서 각 무게가 서로 짝꿍인지 판별한다.
	ㄴ 이때 짝꿍이 된다면, 무게A 의 개수 x 무게B의 개수 를 해주어야 해당 무게가 짝지어지는 조합의 개수를 구할 수 있다.

	* 개수를 구할 떄 long long 형으로 변환해서 answer에 넣어야 한다.
	ㄴ 최대 개수가 int 형을 넘을 수 있기 때문이다.

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
			answer += ((count * (count - 1)) / 2); // 조합 계산 추가
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