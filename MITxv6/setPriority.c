#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main(int argc, char *argv[])
{
    int input_value = atoi(argv[1]);
    int input_pid = atoi(argv[2]);

    if(input_value < 0)
    {
        input_value = 0;
    }
    if(input_value > 100)
    {
        input_value = 100;
    }

    int old_pid;

    old_pid = set_priority(input_value, input_pid);
    
    printf(1, "PID= %d   OLD_PRIORITY = %d  NEW_PRIORITY= %d\n",input_pid, old_pid, input_value);
    exit();
    
}