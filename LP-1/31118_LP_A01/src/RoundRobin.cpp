/*
 * RoundRobin.cpp
 *
 *  Created on: 28-Jul-2021
 *      Author: Shubham
 */


#include <queue>
#include "SchedulingAlgos.h"

void SchedulingAlgos :: RoundRobin() {
	int k; // k is time quantum
	cout << "Enter time quantum: "; cin>>k;

	// sorting jobs by arrival time
	sort(jobs, jobs + n, [](const Job &j1, const Job &j2) {
		if (j1.arv_time != j2.arv_time)
			return j1.arv_time < j2.arv_time;
		return j1.id < j2.id;
	});

	queue<int> q;
	int time_proccessed[n] = { 0 }, end_time = 0, jobidx = 0;
	int last[n]={0}; // when job was given cpu in past?

	memset(last, -1, sizeof (last));
	memset (waiting_time, 0, sizeof (waiting_time));
	memset (turnaround_time, 0, sizeof(turnaround_time));

	while (jobidx < n || !q.empty()) {
		if (q.empty()) {
			q.push(jobidx);
			jobidx++;
		}

		int qidx = q.front(); q.pop();
		int cur_job = jobs[qidx].id-1, start_time = max(end_time, jobs[qidx].arv_time);

		waiting_time[cur_job] += start_time - max(last[cur_job], jobs[qidx].arv_time);

		int time_given = min(k, jobs[qidx].burst_time - time_proccessed[cur_job]);
		time_proccessed[cur_job] += time_given;
		end_time = start_time + time_given;
		last[cur_job] = end_time;
		if (time_proccessed[cur_job] == jobs[qidx].burst_time)
			turnaround_time[cur_job] = end_time - jobs[qidx].arv_time;

		while (jobidx < n && jobs[jobidx].arv_time < end_time)
			q.push(jobidx++);
		if (time_proccessed[cur_job] < jobs[qidx].burst_time)
			q.push(qidx);
	}

	PrintSchedulingDet();
}
