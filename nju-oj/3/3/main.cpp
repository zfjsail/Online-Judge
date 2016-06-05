#include <vector>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

vector<double> BatchQueryExecutionTime(const vector<string>&sqls, const vector<double>&times, const vector<string>&keywords) {
	// your code
	vector<double> avg_time(keywords.size());
	for (int i = 0; i < keywords.size(); i++) {
		string key = keywords[i];
	    double t = 0;
		int cnt = 0;
		string sub;
		for (int j = 0; j < sqls.size(); j++) {
			string ssql = sqls[j];
			istringstream iss(ssql);
			bool flag = false;
			while (iss) {
				iss >> sub;
				if (key.compare(sub) == 0) {
					flag = true;
					break;
				}
			}
			if (flag) {
				string::size_type sz;
				cnt++;
				t += times[j];
			}
		}
		avg_time[i] = t / cnt;
	}
	return avg_time;
}

int main() {
	vector<string> sqls(1);
	sqls[0] = "insert into tableA values(1, \"columnA\", \"columnB\")";
	vector<double> times(1);
	times[0] = 2.5;
	vector<string> keywords(1);
	keywords[0] = "tableA";
	vector<double> r = BatchQueryExecutionTime(sqls, times, keywords);
	cout << r[0] << endl;
	return 0;
}

vector<double> BatchQueryExecutionTime(int kindSize, const vector<vector<int>>&kindsTree, \
	const vector<SQL>&sqls, const vector<Query>&queries) {
	vector<double> avg_time(queries.size());
	for (int i = 0; i < queries.size(); i++) {
		int k = queries[i].kind; 
		vector<int> subk = kindsTree[k]; //找到所有子类
		vector<int> flag(kindSize); //标志每类是否属于上面子类
		for (int j = 0; j < subk.size(); j++) {
			flag[subk[j]] = 1;
		}
		double t = 0;
		int cnt = 0;
		for (int j = 0; j < sqls.size(); j++) {
			SQL sq = sqls[j];
			int kd = sq.kind;
			if (flag[kd]) {
				t += sq.time;
				cnt++;
			}
		}
		avg_time[i] = t / cnt;
	}
	return avg_time;
}
