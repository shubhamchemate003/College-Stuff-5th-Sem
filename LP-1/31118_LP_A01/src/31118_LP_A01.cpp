//============================================================================
// Name        : 31118_LP_A01.cpp
// Author      : Shubham
//============================================================================

#include <iostream>
#include "scheduling_algos.h"
#include "Job.h"
using namespace std;

int main() {
	int n;
	cout << "Enter Number of Jobs: ";
	cin >> n;
	Job jobs[n];
	cout << "Enter Arrival time and Burst time:\n";
	for (int i = 0; i < n; i++) {
		cout << "Job #" << i + 1 << ": ";
		cin >> jobs[i].arv_time >> jobs[i].burst_time;
		jobs[i].id = i + 1;
	}

	FCFS(jobs, n);

	SJF(jobs, n);

	return 0;
}
