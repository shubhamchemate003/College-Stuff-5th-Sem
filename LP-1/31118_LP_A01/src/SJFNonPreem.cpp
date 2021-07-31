/*
 * SJF2.cpp
 *
 *  Created on: 31-Jul-2021
 *      Author: Shubham
 */

#include <set>

#include "SchedulingAlgos.h"

// non-preemptive
void SchedulingAlgos :: SJFNonPreem() {

	// sorting by arrival time
	sort(jobs, jobs + n, [](const Job &j1, const Job &j2) {
		if (j1.arv_time == j2.arv_time)
			return j1.burst_time < j2.burst_time;
		return j1.arv_time < j2.arv_time;
	});

	multiset<pair<int,int>> pq;
	int end_time=0, jobi=0;
	memset (waiting_time, 0, sizeof (waiting_time));
	memset (turnaround_time, 0, sizeof(turnaround_time));

	while (jobi < n || !pq.empty()) {
		if (pq.empty()) {
			pq.insert({jobs[jobi].burst_time, jobi});
			jobi++;
		}

		auto it = pq.begin();
		int cur_job = jobs[it->second].id-1, qidx=it->second;
		pq.erase(it);

		waiting_time[cur_job] = max(0, end_time-jobs[qidx].arv_time);
		end_time = max(end_time, jobs[qidx].arv_time)+jobs[qidx].burst_time; // completion time of cur job
		turnaround_time[cur_job] = end_time-jobs[qidx].arv_time;

		while (jobi < n && jobs[jobi].arv_time < end_time) {
			pq.insert({jobs[jobi].burst_time, jobi});
			jobi++;
		}
	}

	PrintSchedulingDet();
}






