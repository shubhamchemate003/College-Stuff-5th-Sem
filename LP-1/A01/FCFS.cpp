/*
 * FCFS.cpp
 *
 *  Created on: 23-Jul-2021
 *      Author: Shubham
 */

#include "SchedulingAlgos.h"

void SchedulingAlgos :: FCFS() {

	// sorting by arrival time
	sort(jobs, jobs + n, [](const Job &j1, const Job &j2) {
		return j1.arv_time < j2.arv_time;
	});

	memset (waiting_time, 0, sizeof (waiting_time));
	memset (turnaround_time, 0, sizeof(turnaround_time));

	int end_time = 0; // completion time of cur job
	for (int i = 0; i < n; i++) {
		int id = jobs[i].id-1, arv_time = jobs[i].arv_time, burst_time = jobs[i].burst_time;

		waiting_time[id] = max(0, end_time - arv_time);
		end_time = max(end_time, arv_time) + burst_time; // completion time of cur job
		turnaround_time[id] = end_time - arv_time;
	}

	PrintSchedulingDet();

}



