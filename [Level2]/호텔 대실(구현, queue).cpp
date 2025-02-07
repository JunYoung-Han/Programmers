#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

/*
	문제 풀이

	시작 시간으로 오름차순 정렬
	하나씩 꺼내서 넣을 때, 방이 있는지 체크, 없으면 새로운 queue에 넣기
	마지막에 queue의 개수를 세면 된다. (== vec.size())

	왜인지는 모르겠으나, compare 함수에서
	return t2.IsLaterThan(t1); 대신에 return t1.IsLaterThan(t2) == false;
	를 사용하면 마지막 테스트케이스에서 segmentFault 오류가 발생한다;;; <- 이거때문에 오래걸렸다.
	왠만하면 sort compare 함수에는 그냥 직접 접근하는 방식으로 쓰자.
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
			// 하나씩 꺼내서 넣을 때, 방이 있는지 체크, 없으면 새로운 queue에 넣기
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