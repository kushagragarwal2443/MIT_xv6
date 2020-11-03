# MIT xv6 Improvements

To run the code:

						make clean qemu-nox SCHEDULER=<flag>

#### Allowed flags: 

+ DEFAULT (Round Robin)
+ FCFS (First come first serve)
+ PBS (Priority Based Scheduler)

### Sample commands

				time ls

				setPriority 20 2

				benchmark & (run ps continously to monitor output)


## New Syscalls Added


### waitx :
+ The two arguments are pointers to integers to which waitx will assign the total number of clock ticks during which process was waiting and total number of clock ticks when the process was running.
+ Using Terminal we can access this syscall via user defined 'time' command
+ time takes a command as an argument and prints the runtime and waitime of that command using waitx on the terminal.

						time <command>

### ps :

+ No arguements are taken. Loops over proc_table and returns info.
+ Returns some basic information about each process:  runtime, wait time, num_run, current_queue, ticks in different queues.
+ Values are passed into a struct of type proc_stat
+ To access this syscall enter the 'ps' command

						ps


### set_Priority

+ It is used to change the priority of a process.
+ Using Terminal we can access this syscall via 'setPriority' command
+ It takes pid of the process and the new priority as an argument and returns the old priority

						setPriority <val> <pid>


## New Scheduling Algorithms added


### FCFS Scheduler :

+ First in, first out (FIFO), also known as first come, first served (FCFS), is the simplest scheduling algorithm. 
+ FIFO simply queues processes in the order that they arrive in the ready queue.
+ No preemption is allowed.
+ In this, the process that comes first will be executed first and next process starts only after the previous gets fully executed.

				make clean qemu-nox SCHEDULER=FCFS


### Priority Based Scheduling :

+ Priority based scheduling is a preemptive algorithm.
+ Each process is assigned a priority. Process with highest priority (numerically least) is to be executed first and so on
+ Processes with same priority are executed according to Round Robin algorithm
+ If a process of higher priority(numerically less) arrives while a lower priority process is being executed the lower priority process is preempted.

				make clean qemu-nox SCHEDULER=PRIORITY
