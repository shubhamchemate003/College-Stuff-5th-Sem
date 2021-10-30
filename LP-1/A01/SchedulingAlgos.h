/*
 * scheduling_algos.h
 *
 *  Created on: 23-Jul-2021
 *      Author: Shubham
 */

#ifndef SCHEDULINGALGOS_H_
#define SCHEDULINGALGOS_H_

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring> // memset function

using namespace std;

struct Job {
	int id, arv_time, burst_time;
};

const int D=100;

class SchedulingAlgos {
private:
	Job jobs[D];
	int n;
	int turnaround_time[D], waiting_time[D], priority[D];

public:

	void takeInput();

	void FCFS();

	void SJFPreem();

	void SJFNonPreem();

	void PriorityScheduling ();

	void RoundRobin();

	void PrintSchedulingDet();
};





#endif /* SCHEDULINGALGOS_H_ */
