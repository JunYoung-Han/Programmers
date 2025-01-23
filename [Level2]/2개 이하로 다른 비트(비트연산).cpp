#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <map>

using namespace std;

/*
	문제풀이

	input data를 2진수 변환했을때 가장 먼저 나오는 0의 자리를 1로 나머지는 0으로
	이 숫자를 input data에 더하고 이 숫자를 /2 한 값을 빼주시면 됩니다.
	ex) 5 -> 101 -> 가장 먼저 나오는 0을 탐색(2의 1승자리) -> 101 + 10 - 1 -> 110 ->output data : 6
	ex) 3 -> 11 -> 가장 먼저 나오는 0을 탐색(2의 2승자리) -> 11 + 100 - 10 -> 101 ->output data : 5

*/


vector<long long> answer;
int countBitDifferences(long long num1, long long num2) {
	std::bitset<64> bits1(num1);
	std::bitset<64> bits2(num2);
	return (bits1 ^ bits2).count();  // XOR 연산 후 1인 비트의 개수 반환
}

void GetAnswer(long long num)
{
	// 짝수인 경우는 +1 해주면 된다
	if (num % 2 == 0)
	{
		answer.push_back(num + 1);
		return;
	}

	bitset<64> bit(num);
	long long newNum = num;
	for (int i = 0; i < bit.size(); i++)
	{
		if (bit[i] == 0)
		{
			newNum |= (1LL << i);
			newNum &= ~(1LL << i - 1);
			answer.push_back(newNum);
			break;
		}
	}
}

vector<long long> solution(vector<long long> numbers) {

	for (int i = 0; i < numbers.size(); i++)
		GetAnswer(numbers[i]);

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	//solution({ 23,191,181,3787,835583,9395240959,38588383231,13194139533311,26388279066623 });
	solution({ 7 });

	return 0;
}