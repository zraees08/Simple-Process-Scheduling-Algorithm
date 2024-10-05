# Simple-Process-Scheduling-Algorithm
Round-Robin Scheduling Algorithm

Overview

This C++ code implements a simple Round-Robin Scheduling algorithm to manage processes.

Approach

1. Create processes with unique IDs and execution times.
2. Link processes in a circular linked list.
3. Schedule processes using a fixed time slice (cpu_time_per_cycle) in each cycle.
4. Remove completed processes from the list.

Assumptions

- Processes are independent and do not have dependencies.
- CPU time per cycle is fixed.

Challenges Faced

- Handling circular linked list.
- Removing completed processes efficiently.
