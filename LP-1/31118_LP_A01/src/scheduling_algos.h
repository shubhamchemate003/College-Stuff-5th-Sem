/*
 * scheduling_algos.h
 *
 *  Created on: 23-Jul-2021
 *      Author: Shubham
 */

#ifndef SCHEDULING_ALGOS_H_
#define SCHEDULING_ALGOS_H_

#include "Job.h"

void FCFS(Job jobs[], int n);

void SJF(Job jobs[], int n);

void PrintSchedulingDet(Job jobs[], int n, int turnaround_time[], int waiting_time[]);


#endif /* SCHEDULING_ALGOS_H_ */
