#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include <stddef.h>

int number_of_processes = 10;
int total_waittime, total_runtime;

int main(int argc, char *argv[])
{
  total_waittime=0;
  total_runtime=0;
  int j;
  for (j = 0; j < number_of_processes; j++)
  {
    int pid = fork();
    if (pid < 0)
    {
      printf(1, "Fork failed\n");
      continue;
    }
    if (pid == 0)
    {
      volatile int i;
      for (volatile int k = 0; k < number_of_processes; k++)
      {
        if (k <= j)
        {
          sleep(50); //io time
        }
        else
        {
          for (i = 0; i < 100000000; i++)
          {
            ; //cpu time
          }
        }
      }
      exit();
    }
    else
    {      
      // set_priority(100-(20+j),pid); 
      // ;
    }
  }
  for (j = 0; j < number_of_processes+5; j++)
  {
    int waittime, runtime;
    waitx(&waittime, &runtime);
    total_waittime+=waittime;
    total_runtime+=runtime;
  }
  printf(1, "TOTAL WAIT TIME: %d  TOTAL RUN TIME: %d\n", total_waittime, total_runtime);
  exit();
}
