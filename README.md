# Implementing Lottery Scheduling in Xv6

## Code and Report
Click [here](https://github.com/aashaykorani/Xv6-scheduling/blob/main/kernel/proc.c) to see the `proc.c` kernel code for my scheduler.

Click [here](https://github.com/aashaykorani/Xv6-scheduling/blob/main/scheduling-report.pdf) to see my final report for this project.

## Part 1 - Nice
Having policies is the first step in implementing a non-trivial scheduler. For the sake of simplicity, you can implement the nice UNIX API as an extra system call. A higher nice value means lower priority. For more information type – man 2 nice on Linux system.
You should be able to store the nice value in the process structure. Xv6 stores the PCB in struct proc in the file proc.h
Note: You are not expected to enforce specific permissions on nice. On Linux systems, typically only root can increase priorities. But you can skip this part in the assignment.

## Part 2 - Random Number Generator
Lottery scheduling is a randomized heuristic. Hence, we need to design a pseudo-random number generator (PRNG). Since xv6 does not include a PNRG, you need to design one. This does not require strong randomness such as in cryptographic algorithms but a decent PRNG will do. 
We recommend using the Xorshift family, although you can use anything else. If you do choose to use the Xorshift values, care should be taken to pick non-zero seed values. 

## Part 3 - Scheduler				
Mentioned in the link, lottery scheduling works by assigning tickets to each of the processes in the system. Then, in each time slice, it randomly picks a ‘winning’ ticket. It is up to you to decide how many more tickets to assign less nice processes and vice versa. 	
The design problem is more open-ended. After reading the text mentioned in the link above, some of the design factors you might want to consider: 
Which data structure makes sense?
In what way would you handle a process leaving or entering a system all while maintaining a policy?
How would you map the winning number back to the runnable process?
Note: You should keep both the schedulers as an option. It is fine to select the scheduler (Round Robin vs. Lottery) to be a compile time option.
Implement lottery scheduling in xv6. As mentioned, the particulars of the data structure and the policies to map the number of tickets to nice values is a design choice which is open-ended. You have to convince us that your implementation handles edge cases. Provide a detailed explanation of your approach. (Questions like ‘what if?’ should be mentioned and handled as well)
Come up with at least 3 test cases for your lottery scheduler and provide screenshot(s) of your test cases along with an explanation. Also, mention how to run your test cases - in what file is it located and what to run.

## Compiling
If you are using the class vm, to compile, just run `make xv6.img` in the project directory. That will build xv6.img. Assuimging that was successful, you can then run xv6 by running `make qemu`. If you make changes to any xv6, you will likely need to first clean out the "stale" binaries before rebuilding xv6.img. You can clean your build environment with `make clean`.

## Debugging 
You will then want to navigate to
run `make clean && make qemu-vscode` once the gdb server has started, it will wait for connections. You can then 
navigate to your debug console in VSCode and select gdb from the gear icon. You should see an "Attach to QEMU" profile 
available. When you run this, you should connect to the gdb server. Go ahead and try to set up breakpoints and whatnot. 

## Compiling with Docker (if you want to)
If you are already a linux power user, you can compile natively with docker. You can compile xv6 with docker my running `make docker`. That will run an ubuntu 18.04 container that will compile xv6.img for you. I would not recommend relying on this unless you are already profcient with docker.

## Dependencies (if you are not on the VM)
If you are compiling natively, will need to add a plugin to your vscode. To install the necessary dependencies for debugging in vscode, press `ctrl p` then enter `ext install webfreak.debug`. 
That will install [this](https://github.com/WebFreak001/code-debug) vscode module. You will also need to install
gdb and lldb if you haven't already. On debian that is `sudo apt update && sudo apt install -y gdb lldb`, on arch 
(btw) `sudo pacman -S gdb lldb`, and alpine `sudo apk add --update gdb lldb`.

BUILDING AND RUNNING XV6

To build xv6 on an x86 ELF machine (like Linux or FreeBSD), run "make".
On non-x86 or non-ELF machines (like OS X, even on x86), you will
need to install a cross-compiler gcc suite capable of producing x86 ELF
binaries.  See http://pdos.csail.mit.edu/6.828/2014/tools.html.
Then run "make TOOLPREFIX=i386-jos-elf-".

To run xv6, install the QEMU PC simulators.  To run in QEMU, run "make qemu".

To create a typeset version of the code, run "make xv6.pdf".  This
requires the "mpage" utility.  See http://www.mesa.nl/pub/mpage/.
