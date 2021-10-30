/*
 * SJF.cpp
 *
 *  Created on: 23-Jul-2021
 *      Author: Shubham
 */

#include <set>

#include "SchedulingAlgos.h"

// preemptive
void SchedulingAlgos::SJFPreem() {

	// sorting Jobs by arrival time and then by burst time
	sort(jobs, jobs + n, [](const Job &j1, const Job &j2) {
		if (j1.arv_time == j2.arv_time)
			return j1.burst_time < j2.burst_time;
		return j1.arv_time < j2.arv_time;
	});

	multiset<pair<int, int>> pq;
	int end_time = 0, jobi = 0; // end_time->end time of current process
	int processed_time[n] = { 0 }, last[n];

	memset(last, -1, sizeof (last));
	memset (waiting_time, 0, sizeof (waiting_time));
	memset (turnaround_time, 0, sizeof(turnaround_time));

	while (jobi < n || !pq.empty()) {
		if (pq.empty()) {
			pq.insert({jobs[jobi].burst_time, jobi});
			jobi++;
		}

		auto it = pq.begin();
		int cur_job = jobs[it->second].id - 1, qidx = it->second;
		pq.erase(it);
		int start_time = max(end_time, jobs[qidx].arv_time);
		waiting_time[cur_job] += start_time - max(last[cur_job], jobs[qidx].arv_time);
		end_time = start_time + jobs[qidx].burst_time - processed_time[cur_job];

		bool job_found=0; // id there more priority job before ending of cur job?
		while (jobi < n and jobs[jobi].arv_time < end_time and !job_found) {
			if (jobs[jobi].burst_time < jobs[qidx].burst_time) { // pause the cur job
				pq.insert({jobs[qidx].burst_time, qidx});
				end_time = jobs[jobi].arv_time;
				last[cur_job] = end_time;
				processed_time[cur_job] = end_time - start_time;
				pq.insert({jobs[jobi].burst_time, jobi});
				job_found = 1;
			}
			else { // put jobi in queue
				pq.insert({jobs[jobi].burst_time, jobi});
			}

			jobi++;
		}

		if (!job_found) { // no job can interrupt my current job
			turnaround_time[cur_job] = end_time - jobs[qidx].arv_time;
			processed_time[cur_job] = jobs[qidx].burst_time;
		}

	}

	PrintSchedulingDet();

}

