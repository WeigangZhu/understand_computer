#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>

int system(const char *cmdstring)  // version without signal handling
{
	pid_t pid;
	int status;
	
	if(cmdstring == NULL)
		return (1); /// always a command processor with UNIX
	
	if((pid = fork()) < 0)
	{
		status = -1;
	}
	else if (pid == 0) // child
	{
		execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
		_exit(127);
	}
	else
	{
		while( waitpid(pid, &status, 0) < 0)
		{
			if( errno != EINTR)
			{
				status = -1; // error other than EINTR from waitpid()
				break;
			}
		}
	}
		
	
	return (status);
}

