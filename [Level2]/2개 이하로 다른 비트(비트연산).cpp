#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <map>

using namespace std;

/*
	����Ǯ��

	input data�� 2���� ��ȯ������ ���� ���� ������ 0�� �ڸ��� 1�� �������� 0����
	�� ���ڸ� input data�� ���ϰ� �� ���ڸ� /2 �� ���� ���ֽø� �˴ϴ�.
	ex) 5 -> 101 -> ���� ���� ������ 0�� Ž��(2�� 1���ڸ�) -> 101 + 10 - 1 -> 110 ->output data : 6
	ex) 3 -> 11 -> ���� ���� ������ 0�� Ž��(2�� 2���ڸ�) -> 11 + 100 - 10 -> 101 ->output data : 5

*/


vector<long long> answer;
int countBitDifferences(long long num1, long long num2) {
	std::bitset<64> bits1(num1);
	std::bitset<64> bits2(num2);
	return (bits1 ^ bits2).count();  // XOR ���� �� 1�� ��Ʈ�� ���� ��ȯ
}

void GetAnswer(long long num)
{
	// ¦���� ���� +1 ���ָ� �ȴ�
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