#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

/*
	���� Ǯ��

	���� �ð����� �������� ����
	�ϳ��� ������ ���� ��, ���� �ִ��� üũ, ������ ���ο� queue�� �ֱ�
	�������� queue�� ������ ���� �ȴ�. (== vec.size())

	�������� �𸣰�����, compare �Լ�����
	return t2.IsLaterThan(t1); ��ſ� return t1.IsLaterThan(t2) == false;
	�� ����ϸ� ������ �׽�Ʈ���̽����� segmentFault ������ �߻��Ѵ�;;; <- �̰Ŷ����� �����ɷȴ�.
	�ظ��ϸ� sort compare �Լ����� �׳� ���� �����ϴ� ������� ����.
*/

using namespace std;

struct Time
{
	int Hour;
	int Minutes;
	Time(string str)
	{
		int colonPos = str.find(':');
		Hour = stoi(str.substr(0, colonPos));
		Minutes = stoi(str.substr(colonPos + 1));
	}
	bool IsLaterThan(Time t2)
	{
		if (Hour != t2.Hour)
			return Hour > t2.Hour;

		return Minutes > t2.Minutes;
	}
};

bool compare(const vector<string>& s1, const vector<string>& s2)
{
	Time t1(s1[0]);
	Time t2(s2[0]);
	return t2.IsLaterThan(t1);
}

int solution(vector<vector<string>> book_time) {
	int answer = 0;

	sort(book_time.begin(), book_time.end(), compare);

	vector<queue<Time>> vec;
	for (int i = 0; i < book_time.size(); i++)
	{
		if (vec.empty())
		{
			queue<Time> q;
			q.push(Time(book_time[i][1]));
			vec.push_back(q);
		}
		else
		{
			// �ϳ��� ������ ���� ��, ���� �ִ��� üũ, ������ ���ο� queue�� �ֱ�
			bool isCan = false;
			for (int j = 0; j < vec.size(); j++)
			{
				queue<Time>* q = &vec[j];
				Time lastEnd = q->front();
				lastEnd.Minutes += 10;
				if (lastEnd.Minutes >= 60)
				{
					lastEnd.Hour += 1;
					lastEnd.Minutes -= 60;
				}

				if (lastEnd.IsLaterThan(book_time[i][0]))
					continue;
				else
				{
					q->pop();
					q->push(book_time[i][1]);
					isCan = true;
					break;
				}
			}
			if (isCan == false)
			{
				queue<Time> tempQ;
				tempQ.push(Time(book_time[i][1]));
				vec.push_back(tempQ);
			}
		}
	}

	answer = vec.empty() ? 0 : vec.size();
	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution({ {"15:00", "17:00"}, {"16:40", "18:20"}, {"14:20", "15:20"}, {"14:10", "19:20"}, {"18:20", "21:20"} });
	//solution({  });

	return 0;
}