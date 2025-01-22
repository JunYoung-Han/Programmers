#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// 2018 KAKAO BLIND RECRUITMENT
/*
	����Ǯ��
	���� ���� �����̴�. �ܾ� ������ 2�� ���պ��� �˻��ϱ� �����Ѵ�.
	1. �ش� ������ ������ 2������ 3�� �������� �ٽ� üũ
	2. 1���� �ش� ������ ���� ������ �ݺ�
	3. �ش� ������ ������ ������ ������ �߰��ϰ� while ����
	4. �̶� �ٱ� for ��ȸ�� i ������ ���ռ� - 2 ��ŭ ������Ų��.
	�� ������ �ܾ��� �������� ������ ù��°�� �Ǿ� �ٽ� ����Ǿ�� �ϱ� ����
	�� ���ռ� - 2  �� ������ ����, ���� ������ 2���̸�  for ������ �ڵ����� 1 �߰��Ǿ� ������ ������ ���ں��� �ٽ� ���۵Ǳ� ����.

	������
	������ ������� ����� ��� �ڵ带 ¥�ߵǴµ�, ���� �̷��� �ǰڴ� ��� �����ϴ� �ǵ��ư����� �ð��� �� �ɷȴ�. ó������ ����� Ǯ������ �ð��� ���������� �پ��� �� ����.
	Ǯ�� ������ ����� ����� �ڵ带 ����.
*/

vector<int> solution(string msg) {
	vector<int> answer;

	// msg�� ��ȸ�ϸ鼭 ����.
	map<string, int> alpha;
	char cur = 'A';
	for (int i = 0; i < 26; i++)
	{
		string str;
		str += cur + i;
		alpha.insert({ str, i + 1 });
	}

	for (int i = 0; i < msg.size(); i++)
	{
		// 2�� ���պ��� ������, -> 3������ �׽�Ʈ.
		// �ɸ��� ���� �ϴ°Ŵ�.
		int sumWordCount = 2;
		while (true)
		{
			string str;
			for (int k = 0; k < sumWordCount; k++)
				str += msg[i + k];
			// str: sumWordCount ���� ����

			// ������ sumWordCount++ �ؼ� �ٽ� üũ 
			if (alpha.find(str) != alpha.end())
			{
				sumWordCount++;
				continue;
			}
			else
			{
				// ������ ������ ������ �߰�
				alpha.insert({ str,  alpha.size() + 1 });
				str.pop_back();
				answer.push_back(alpha[str]);
				i += sumWordCount - 2;
				break;
			}
		}
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	//solution("TOBEORNOTTOBEORTOBEORNOT");
	solution("TOBEORNOTTOBEORTOBEORNOT");

	return 0;
}