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
	����Ǯ��

	records�� ��ȸ�ϸ鼭 ������ �����Ѵ�.
	������ ���, ���� �ð��� carIn�� ĳ��
	���� �� ���, ĳ���� �����ð��� �ð� ���� ���
	�ð����̷� ��� carTimes�� ĳ��

*/


int basicTime = 0;
int basicFee = 0;
int unitMin = 0;
int unitFee = 0;

// ���� ��� ��� �Լ�
int CalculateFee(int minutes)
{
	int time = max(0, (minutes - basicTime));
	int unitTime = time / unitMin;
	unitTime += time % unitMin == 0 ? 0 : 1;
	int fee = basicFee + unitTime * unitFee;
	return fee;
}

// ���ڿ� "HH:MM"�� �� �� ������ ��ȯ�ϴ� �Լ�
int TimeToMinutes(string time) {
	int hours = std::stoi(time.substr(0, 2)); // "HH" �κ�
	int minutes = std::stoi(time.substr(3, 2)); // "MM" �κ�
	return hours * 60 + minutes;
}

// �� �ð� ���ڿ� ���� ���̸� ����ϴ� �Լ�
int TimeDifference(string time1, string time2) {
	int minutes1 = TimeToMinutes(time1);
	int minutes2 = TimeToMinutes(time2);
	return std::abs(minutes1 - minutes2); // ���밪 ��ȯ
}

vector<string> SplitInfo(string str) {
	vector<string> result;
	size_t start = 0, end = 0;

	while ((end = str.find(' ', start)) != std::string::npos) {
		result.push_back(str.substr(start, end - start)); // ���� �κ� ���ڿ� ����
		start = end + 1; // ���� ���� ��ġ�� �̵�
	}

	result.push_back(str.substr(start)); // ������ �κ� ���ڿ� �߰�
	return result;
}

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;

	basicTime = fees[0]; // �⺻ �ð�
	basicFee = fees[1]; // �⺻ ���
	unitMin = fees[2]; // ���� �ð�(��)
	unitFee = fees[3]; // ���� ���

	map<int, int> carTimes; // ���� ��� �հ�
	map<int, string> carIn; // ���� �Է� ĳ��
	for (int i = 0; i < records.size(); i++)
	{
		vector<string> info = SplitInfo(records[i]);
		int carNum = stoi(info[1]);
		if (carIn[carNum] != "")
		{
			// ���� Ÿ�̹�
			carTimes[carNum] += TimeDifference(carIn[carNum], info[0]);
			// ���� ���� false �� ��ȯ
			carIn[carNum] = "";
		}
		else
		{
			// ���� Ÿ�̹�
			carIn[carNum] = info[0];
		}
	}

	// ���� ��� ���� ���� �ð� ó��
	for (auto it = carIn.begin(); it != carIn.end(); ++it) 
	{
		if (it->second != "")
		{
			carTimes[it->first] += TimeDifference(it->second, "23:59");
		}
	}

	// ���� �ð����� ���� ��� ���
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