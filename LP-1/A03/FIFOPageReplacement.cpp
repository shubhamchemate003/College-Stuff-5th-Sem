#include <iostream>
#define process_number first
#define process_name second

using namespace std;

int main()
{
    int number_of_processes = 20;
    int a[number_of_processes] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    pair<int, int> process[number_of_processes];

    for (int i = 0; i < number_of_processes; i++)
        process[i] = {i, a[i]};

    int k = 3, cur_buffer_size = 0, cur_process_ptr = -1;
    pair<int, int> buffer[k];
    for (int i = 0; i < k; i++)
        buffer[i] = { -1, -1};

    int faults = 0, hits = 0;
    for (int i = 0; i < number_of_processes; i++) {

        cout << "Process Name: " << process[i].process_name << " -----> ";

        bool is_cur_proccess_already_present = 0;
        for (int j = 0; j < k; j++)
            is_cur_proccess_already_present |= (buffer[j].process_name == process[i].process_name);

        if (!is_cur_proccess_already_present) {
            cout << "Page fault case: ";
            if (cur_buffer_size < k) {
                cur_process_ptr = (cur_process_ptr + 1) % k;
                buffer[cur_process_ptr] = process[i];
                cur_buffer_size++;
            }
            else {
                int first_come = 0;
                for (int j = 1; j < k; j++)
                    if (buffer[j].process_number < buffer[first_come].process_number)
                        first_come = j;
                buffer[first_come] = process[i];
            }
            faults++;
        }
        else hits++;

        // printing buffer
        for (int j = 0; j < k; j++)
            cout << buffer[j].process_name << ' ';
        cout << '\n';
    }

    cout << "Number of page faults: " << faults << '\n';
    cout << "Number of page hits: " << hits << '\n';

    return 0;
}
