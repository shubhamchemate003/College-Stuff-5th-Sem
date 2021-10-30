/*
 * PriorityScheduling.cpp
 *
 *  Created on: 28-Jul-2021
 *      Author: Shubham
 */

#include "SchedulingAlgos.h"
#include <set>

// non-preemptive
void SchedulingAlgos :: PriorityScheduling () {
	cout << "Enter the priorities of the jobs:\n";
	for (int i=0; i<n; i++) {
		cout << "Job #" << i+1 << ": ";
		cin>>priority[i];
	}

	// sorting jobs by arrival time, conflicts resolved by priority
	sort (jobs, jobs+n, [=] (const Job& j1, const Job& j2) {
		if (j1.arv_time != j2.arv_time)
				return j1.arv_time < j2.arv_time;
		return priority[j1.id-1] < priority[j2.id-1];
	});

	memset (waiting_time, 0, sizeof (waiting_time));
	memset (turnaround_time, 0, sizeof(turnaround_time));

	multiset<pair<int,int>> pq;
	int end_time=0, jobi=0;
	while (jobi < n || !pq.empty()) {
		if (pq.empty()) {
			pq.insert({priority[jobs[jobi].id-1], jobi});
			jobi++;
		}

		auto it = pq.begin();
		int cur_job=jobs[it->second].id-1, qidx=it->second;
		waiting_time[cur_job] = max(0, end_time-jobs[cur_job].arv_time);
		end_time = max(end_time, jobs[qidx].arv_time)+jobs[qidx].burst_time;
		turnaround_time[cur_job] = end_time - jobs[qidx].arv_time;
		pq.erase(it);

		while (jobi < n && jobs[jobi].arv_time < end_time) {
			pq.insert({priority[jobs[jobi].id-1], jobi});
			jobi++;
		}
	}

	PrintSchedulingDet();
}


