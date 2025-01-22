#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <queue>
#include <map>

using namespace std;

/*
	문제풀이

	records를 순회하면서 입차를 저장한다.
	입차인 경우, 입차 시간을 carIn에 캐싱
	출차 인 경우, 캐싱한 입차시간과 시간 차이 계산
	시간차이로 요금 carTimes에 캐싱

*/


int basicTime = 0;
int basicFee = 0;
int unitMin = 0;
int unitFee = 0;

// 주차 요금 계산 함수
int CalculateFee(int minutes)
{
	int time = max(0, (minutes - basicTime));
	int unitTime = time / unitMin;
	unitTime += time % unitMin == 0 ? 0 : 1;
	int fee = basicFee + unitTime * unitFee;
	return fee;
}

// 문자열 "HH:MM"을 총 분 단위로 변환하는 함수
int TimeToMinutes(string time) {
	int hours = std::stoi(time.substr(0, 2)); // "HH" 부분
	int minutes = std::stoi(time.substr(3, 2)); // "MM" 부분
	return hours * 60 + minutes;
}

// 두 시간 문자열 간의 차이를 계산하는 함수
int TimeDifference(string time1, string time2) {
	int minutes1 = TimeToMinutes(time1);
	int minutes2 = TimeToMinutes(time2);
	return std::abs(minutes1 - minutes2); // 절대값 반환
}

vector<string> SplitInfo(string str) {
	vector<string> result;
	size_t start = 0, end = 0;

	while ((end = str.find(' ', start)) != std::string::npos) {
		result.push_back(str.substr(start, end - start)); // 현재 부분 문자열 저장
		start = end + 1; // 다음 시작 위치로 이동
	}

	result.push_back(str.substr(start)); // 마지막 부분 문자열 추가
	return result;
}

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;

	basicTime = fees[0]; // 기본 시간
	basicFee = fees[1]; // 기본 요금
	unitMin = fees[2]; // 단위 시간(분)
	unitFee = fees[3]; // 단위 요금

	map<int, int> carTimes; // 차량 요금 합계
	map<int, string> carIn; // 차량 입력 캐싱
	for (int i = 0; i < records.size(); i++)
	{
		vector<string> info = SplitInfo(records[i]);
		int carNum = stoi(info[1]);
		if (carIn[carNum] != "")
		{
			// 출차 타이밍
			carTimes[carNum] += TimeDifference(carIn[carNum], info[0]);
			// 출차 이후 false 로 변환
			carIn[carNum] = "";
		}
		else
		{
			// 입차 타이밍
			carIn[carNum] = info[0];
		}
	}

	// 출차 기록 없는 차량 시간 처리
	for (auto it = carIn.begin(); it != carIn.end(); ++it) 
	{
		if (it->second != "")
		{
			carTimes[it->first] += TimeDifference(it->second, "23:59");
		}
	}

	// 주차 시간으로 주차 요금 계산
	for (auto it = carTimes.begin(); it != carTimes.end(); ++it)
		answer.push_back(CalculateFee(it->second));

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	//solution({ 4, 3, 1, 2, 5 });
	solution({ 180, 5000, 10, 600 }, { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" });

	return 0;
}