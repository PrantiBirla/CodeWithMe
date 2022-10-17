#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();
	if(pid < 0)
	return errno;
    else if(pid == 0)
    {
	int n = atoi(argv[1]);
	printf("%d: %d ", n, n);
	while(n!=1)
	{
		if(n%2)
			n = 3*n+1;
		else
			n = n/2;
		printf("%d ", n);
	}
    }
    else
    {
	wait(NULL);
	printf("\nChild %d finished\n", pid);
    }
    return 0;
}
