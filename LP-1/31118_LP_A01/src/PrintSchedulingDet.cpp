/*
 * PrintJobs.cpp
 *
 *  Created on: 23-Jul-2021
 *      Author: Shubham
 */

#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Job.h"
using namespace std;

void PrintSchedulingDet(Job jobs[], int n, int turnaround_time[], int waiting_time[]) {

	// sorting by job id
	sort(jobs, jobs + n, [](const Job &j1, const Job &j2) {
		return j1.id < j2.id;
	});

	cout << "\nJob Scheduling Details\n"
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
}

