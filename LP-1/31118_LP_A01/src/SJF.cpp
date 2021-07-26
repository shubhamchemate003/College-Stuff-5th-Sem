/*
 * SJF.cpp
 *
 *  Created on: 23-Jul-2021
 *      Author: Shubham
 */

#include <iostream>
#include <algorithm>
#include "Job.h"
#include "scheduling_algos.h" // for printing jobs

using namespace std;

void SJF(Job jobs[], int n) {

	// sorting Jobs by arrival time and then by burst time
	sort(jobs, jobs + n, [](const Job &j1, const Job &j2) {
		if (j1.arv_time == j2.arv_time)
			return j1.burst_time < j2.burst_time;
		return j1.arv_time < j2.arv_time;
	});

	int prev_time = 0; // completion time of previous job
	int waiting_time[n] = { 0 }, turnaround_time[n] = { 0 };
	for (int i = 0; i < n; i++) {
		waiting_time[jobs[i].id - 1] = max(0, prev_time - jobs[i].arv_time);
		int cur_time = max(prev_time + jobs[i].burst_time,
				jobs[i].arv_time + jobs[i].burst_time); // completion time of cur job
		turnaround_time[jobs[i].id - 1] = cur_time - jobs[i].arv_time;
		prev_time = cur_time;
	}

	PrintSchedulingDet(jobs, n, turnaround_time, waiting_time);

}





