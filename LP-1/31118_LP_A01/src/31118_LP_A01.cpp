//============================================================================
// Name        : 31118_LP_A01.cpp
// Author      : Shubham
//============================================================================

#include "SchedulingAlgos.h"

int main() {

	SchedulingAlgos sch;

	sch.takeInput();

	cout << "\nFirst Come First Serve algorithm:\n";
	sch.FCFS();

	cout << "\nShortest Job First (Non-preemptive) algorithm:\n";
	sch.SJFNonPreem();

	cout << "\nShortest Job First (Preemptive) algorithm:\n";
	sch.SJFPreem();

	cout << "\nPriority Scheduling algorithm:\n";
	sch.PriorityScheduling();

	cout << "\nRound Robin Scheduling algorithm:\n";
	sch.RoundRobin();

	return 0;
}
