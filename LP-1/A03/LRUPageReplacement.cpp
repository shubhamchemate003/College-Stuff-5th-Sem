#include <iostream>
#include <cstring>

using namespace std;

void placeAtFront(int buffer[], int k, int p) {
	while (p > 0) {
		swap (buffer[p], buffer[p - 1]);
		p--;
	}
}

int main() {
	int number_of_processes = 20;
	int process[number_of_processes] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};

	int k = 3, cur_buffer_size = 0;
	int buffer[k];
	memset(buffer, -1, sizeof(buffer));

	int faults = 0, hits = 0;
	for (int i = 0; i < number_of_processes; i++) {
		int cur_proc = -1;
		for (int j = 0; j < k; j++)
			if (buffer[j] == process[i])
				cur_proc = j;

		// cur process was not in buffer
		if (cur_proc == -1) {
			cout << "Page fault case: ";
			if (cur_buffer_size < k) {
				buffer[cur_buffer_size] = process[i];
				cur_buffer_size++;
			}
			else { // remove lru
				buffer[k - 1] = process[i];
			}
			cur_proc = cur_buffer_size - 1;
			faults++;
		}
		else hits++;

		placeAtFront(buffer, k, cur_proc);

		// printing buffer
		for (int j = 0; j < k; j++)
			cout << buffer[j] << ' ';
		cout << '\n';
	}

	cout << "Number of page faults: " << faults << '\n';
	cout << "Number of page hits: " << hits << '\n';

	return 0;
}