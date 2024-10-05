#include <iostream>
#include <string>
using namespace std;

// Structure to represent a process
struct Process {
    string process_id;
    int execution_time;
    int remaining_time;
    Process* next;
};

// Function to create a new process
Process* create_process(string process_id, int execution_time) {
    Process* new_process = new Process();
    new_process->process_id = process_id;
    new_process->execution_time = execution_time;
    new_process->remaining_time = execution_time;
    new_process->next = nullptr;
    return new_process;
}

// Function to schedule processes
void schedule_processes(int cpu_time_per_cycle, Process* head) {
    int cycle = 1;
    cout << "Initial Processes: ";
    Process* current = head;
    do {
        cout << "(" << current->process_id << ", " << current->remaining_time << ") ";
        current = current->next;
    } while (current != head);
    cout << endl;

    while (head) {
        cout << "Cycle " << cycle << ":" << endl;
        Process* current = head;
        Process* previous = nullptr;
        do {
            cout << current->process_id << " (Remaining: " << current->remaining_time - cpu_time_per_cycle << ")" << endl;
            current->remaining_time -= cpu_time_per_cycle;
            previous = current;
            current = current->next;
        } while (current != head);

        // Remove completed processes
        Process* temp = head;
        Process* prev = nullptr;
        while (temp->remaining_time <= 0) {
            head = temp->next;
            if (prev) prev->next = head;
            delete temp;
            temp = head;
            prev = nullptr;
        }
        current = head;
        while (current->next != head) {
            if (current->next->remaining_time <= 0) {
                Process* temp2 = current->next;
                current->next = temp2->next;
                delete temp2;
            } else {
                current = current->next;
            }
        }

        if (head) {
            cout << "Processes remaining: ";
            current = head;
            do {
                cout << "(" << current->process_id << ", " << current->remaining_time << ") ";
                current = current->next;
            } while (current != head);
            cout << endl;
        }
        cycle++;
        if (head == head->next) break; // exit loop if only one process left
    }
}

int main() {
    // Create processes
    Process* p1 = create_process("P1", 10);
    Process* p2 = create_process("P2", 5);
    Process* p3 = create_process("P3", 8);

    // Link processes
    p1->next = p2;
    p2->next = p3;
    p3->next = p1;

    int cpu_time_per_cycle = 3;
    schedule_processes(cpu_time_per_cycle, p1);
    return 0;
}