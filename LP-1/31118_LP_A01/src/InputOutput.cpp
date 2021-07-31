/*
 * PrintJobs.cpp
 *
 *  Created on: 23-Jul-2021
 *      Author: Shubham
 */


#include "SchedulingAlgos.h"

void SchedulingAlgos :: takeInput() {
	cout << "Enter Number of Jobs: "; cin >> n;
	cout << "Enter Arrival time and Burst time:\n";
	for (int i = 0; i < n; i++) {
		cout << "Job #" << i + 1 << ": ";
		cin >> jobs[i].arv_time >> jobs[i].burst_time;
		jobs[i].id = i + 1;
	}
}

void SchedulingAlgos :: PrintSchedulingDet() {

	// sorting by job id
	sort(jobs, jobs + n, [](const Job &j1, const Job &j2) {
		return j1.id < j2.id;
	});

	cout << "Job Scheduling Details\n"
					"(job_id, arrival_time, burst_time, turnaround_time, waiting_time)\n";
	double tot_turn=0.0, tot_wait=0.0;
	for (int i = 0; i < n; i++) {
		cout << setw(3) << jobs[i].id << " " << setw(3) << jobs[i].arv_time << " "
				<<setw(3) << jobs[i].burst_time << " " << setw(3) << turnaround_time[i] << " "
				<<setw(3) << waiting_time[i] << endl;
		tot_turn += turnaround_time[i];
		tot_wait += waiting_time[i];
	}

	cout << "Average Turnaround Time: " << tot_turn / n << endl;
	cout << "Average Waiting Time: " << tot_wait / n << endl;
	cout << "\n---------------------------------------------\n";
}

