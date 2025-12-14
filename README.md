# OS Lab — Program Index

This repository contains C programs for Operating Systems lab exercises. Each entry maps the question number to the source file implementing the program.

Q1  -> fork() demonstration: https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/fork_demo.c
Q2  -> Parent computes sum of even, Child sum of odd: https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/sum_even_odd.c
Q3  -> wait() demonstration: https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/wait_demo.c
Q4  -> Orphan process: https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/orphan.c
Q4  -> Zombie process: https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/zombie.c
Q5  -> PIPE implementation (parent->child messages): https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/pipe_communication.c
Q6  -> FIFO (named pipe) reader/writer: https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/fifo_reader.c and https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/fifo_writer.c
Q7  -> MESSAGE QUEUE sender/receiver: https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/msg_sender.c and https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/msg_receiver.c
Q8  -> SHARED MEMORY (without/with semaphore): https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/shm_writer.c, https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/shm_reader.c, https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/shm_writer_sem.c, https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/shm_reader_sem.c
Q9  -> FIRST COME FIRST SERVED Scheduling: https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/fcfs_scheduling.c
Q10 -> SHORTEST JOB FIRST Scheduling: https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/sjf_scheduling.c
Q11 -> PRIORITY Scheduling: https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/priority_scheduling.c
Q12 -> FCFS page replacement policy: https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/fcfs_page_replacement.c
Q13 -> LRU page replacement policy: https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/lru_page_replacement.c
Q14 -> execl() demo (child: ls, parent: date): https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/execl_demo.c
Q15 -> Command `ls | wc` using pipes: https://github.com/AdityaPandey-DEV/OS-LAB/blob/main/ls_wc_pipe.c

---
To compile all programs locally:

```bash
cd "path/to/OS Lab"
mkdir -p bin
for f in *.c; do gcc -Wall -Wextra "$f" -o "bin/${f%.c}" || echo "compile failed: $f"; done
```

Run the quick test script included (`test_all.sh`) to exercise a subset of programs:

```bash
./test_all.sh
```
