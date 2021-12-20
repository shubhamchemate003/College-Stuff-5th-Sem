#include <iostream>
#define pii pair<int, int>
#define number first
#define name second

const int buff_size = 3;

using namespace std;

void print_buffer(pii buffer[]) {
    // buffer
    for (int j = 0; j < buff_size; j++)
        cout << buffer[j].name << ' ';
    cout << '\n';
}

void FIFO(pii process[], int num_of_processes) {
    freopen("FIFO.txt", "w", stdout);

    pii buffer[buff_size];
    for (int i = 0; i < buff_size; i++)
        buffer[i] = { -1, -1};

    int hits = 0, miss = 0, cur_buff_size = 0;
    for (int i = 0; i < num_of_processes; i++) {
        cout << "Process Name: " << process[i].name << " -> ";

        bool is_cur_already_present = 0;
        for (int j = 0; j < buff_size; j++)
            is_cur_already_present |= (buffer[j].name == process[i].name);

        if (!is_cur_already_present) {
            miss++;
            cout << "Page fault: ";

            if (cur_buff_size < buff_size) {
                buffer[cur_buff_size] = process[i];
                cur_buff_size++;
            }
            else {
                int first_come = 0;
                for (int j = 0; j < buff_size; j++)
                    if (buffer[j].number < buffer[first_come].number)
                        first_come = j;

                buffer[first_come] = process[i];
            }
        }
        else {
            cout << "Page hit: ";
            hits++;
        }

        print_buffer(buffer);
    }

    cout << "Hits: " << hits << '\n';
    cout << "Miss: " << miss << '\n';
}

void place_at_front(pii buffer[], int process_num) {
    while (process_num > 0) {
        swap(buffer[process_num], buffer[process_num - 1]);
        process_num--;
    }
}

void LRU(pii process[], int num_of_processes) {
    freopen("LRU.txt", "w", stdout);

    pii buffer[buff_size];
    for (int i = 0; i < buff_size; i++)
        buffer[i] = { -1, -1};

    int hits = 0, miss = 0, cur_buff_size = 0;
    for (int i = 0; i < num_of_processes; i++) {
        cout << "Process Name: " << process[i].name << " -> ";

        int cur_proc_in_buffer = -1;
        for (int j = 0; j < buff_size; j++)
            if (buffer[j].name == process[i].name)
                cur_proc_in_buffer = j;

        if (cur_proc_in_buffer == -1) {
            miss++;
            cout << "Page fault: ";

            if (cur_buff_size < buff_size)
                buffer[cur_buff_size++] = process[i];
            else buffer[cur_buff_size - 1] = process[i];

            cur_proc_in_buffer = cur_buff_size - 1;
        }
        else {
            cout << "Page hit: ";
            hits++;
        }

        place_at_front(buffer, cur_proc_in_buffer);

        print_buffer(buffer);
    }


    cout << "Hits: " << hits << '\n';
    cout << "Miss: " << miss << '\n';
}

int get_next_apperance(pii process[], int num_of_processes, int cur_proc, int from) {
    for (int i = from; i < num_of_processes; i++)
        if (process[i].name == cur_proc)
            return i;
    return num_of_processes;
}

void FIF(pii process[], int num_of_processes) {
    freopen("FIF.txt", "w", stdout);

    pii buffer[buff_size];
    for (int i = 0; i < buff_size; i++)
        buffer[i] = { -1, -1};

    int hits = 0, miss = 0, cur_buff_size = 0;
    for (int i = 0; i < num_of_processes; i++) {
        cout << "Process Name: " << process[i].name << " -> ";

        int cur_proc_in_buffer = -1;
        for (int j = 0; j < buff_size; j++)
            if (buffer[j].name == process[i].name)
                cur_proc_in_buffer = j;

        if (cur_proc_in_buffer == -1) {
            miss++;
            cout << "Page fault: ";

            if (cur_buff_size < buff_size)
                buffer[cur_buff_size++] = process[i];
            else {
                int fif = 0;
                for (int j = 0; j < buff_size; j++) {
                    int cand = get_next_apperance(process, num_of_processes, process[i].name, i + 1);
                    int cur = get_next_apperance(process, num_of_processes, process[i].name, i + 1);

                    if (cand > cur)
                        fif = j;
                }

                buffer[fif] = process[i];
            }
        }
        else {
            cout << "Page hit: ";
            hits++;
        }

        print_buffer(buffer);
    }


    cout << "Hits: " << hits << '\n';
    cout << "Miss: " << miss << '\n';
}

int main() {

    // freopen("../input1.txt", "r", stdin);
    // freopen("../output1.txt", "w", stdout);

    int num_of_processes = 20;
    int a[num_of_processes] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};

    pii process[num_of_processes];
    for (int i = 0; i < num_of_processes; i++)
        process[i] = {i, a[i]};

    FIFO(process, num_of_processes);

    LRU(process, num_of_processes);

    FIF(process, num_of_processes);

    return 0;
}