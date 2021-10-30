#include <iostream>
#include <cstring>
#define BUFFER_CAP 3

using namespace std;

int nearestApp(int process[], int numOfProc, int from, int p) {
	for (int i = from; i < numOfProc; i++)
		if (process[i] == p)
			return i;
	return numOfProc;
}

int main() {
	int numOfProc = 20;
	int process[numOfProc] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};

	int curBuffSize = 0;
	int buffer[BUFFER_CAP];
	memset(buffer, -1, sizeof(buffer));

	int faults = 0, hits = 0;
	for (int i = 0; i < numOfProc; i++) {

		// check if cur process was already there
		int curProc = -1;
		for (int j = 0; j < curBuffSize; j++)
			if (buffer[j] == process[i])
				curProc = j;

		// cur process was not in buffer
		if (curProc == -1) {
			cout << "Page fault case: ";
			if (curBuffSize < BUFFER_CAP) {
				buffer[curBuffSize] = process[i];
				curBuffSize++;
			}
			else { // remove farthest in future
				int fif = 0;
				for (int j = 1; j < BUFFER_CAP; j++)
					if (nearestApp(process, numOfProc, i, buffer[j]) >
					        nearestApp(process, numOfProc, i, buffer[fif]))
						fif = j;
				buffer[fif] = process[i];
			}
			faults++;
		}
		else hits++;

		// printing buffer
		for (int j = 0; j < BUFFER_CAP; j++)
			cout << buffer[j] << ' ';
		cout << '\n';
	}

	cout << "Number of page faults: " << faults << '\n';
	cout << "Number of page hits: " << hits << '\n';

	return 0;
}