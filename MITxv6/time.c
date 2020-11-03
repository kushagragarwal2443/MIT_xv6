#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main (int argc, char *argv[])
{

    int pid;

    int var1=0;
    int var2=0;

    pid = fork();

    if(pid == 0)
    {
        // ps();
        exec(argv[1],&argv[1]);
        printf(1, "exec %s has failed\n", argv[1]);
    }
    else
    {   
        // ps();     
        waitx(&var1, &var2);
    }

    printf(1, "Wait Time = %d Run Time = %d\n", var1, var2);

    exit();

}