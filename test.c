#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>

#define sys_sh_task_info 333

int main()
{  

	const int size = 10;
	long **buf = malloc(sizeof(long *) * size);
	for(int i=0; i<size; i++) buf[i] = malloc(sizeof(long));


	int sys = syscall(sys_sh_task_info,"232145","lol.txt",buf);
	printf("%d\n", sys);
	if (sys==3)
	{
		printf("Error Code: %ld\n", sys);
		printf("Error Name: ESRCH 3 No such process.PID Wrong!");

	}

	else if(sys==-1)
	{
		printf("Error Code: %ld\n", sys);
		printf("Error Name: EIO 5 Input/output error");
	}

	else
	{
		printf("PID: %ld\n",  *buf[0]);
		printf("Process State: %ld\n",  *buf[1]);
		printf("Priority: %ld\n",  *buf[2]);
		printf("Process Exit State: %ld\n",  *buf[3]);
		printf("Process Exit Code: %ld\n",  *buf[4]);
		printf("Process Exit Signal: %ld\n",  *buf[5]);
		printf("Process RT Priority: %ld\n",  *buf[6]);
		printf("Process Static Priority: %ld\n",  *buf[7]);
		printf("Process Normal Priority: %ld\n",  *buf[8]);

		printf("Creating File....\n");
		FILE *fp = fopen("lol.txt", "ab+");

		fprintf(fp, "-------------\n");
		fprintf(fp, "PID: %ld\n",  *buf[0]);
		fprintf(fp,"Process State: %ld\n",  *buf[1]);
		fprintf(fp,"Priority: %ld\n",  *buf[2]);
		fprintf(fp,"Process Exit State: %ld\n",  *buf[3]);
		fprintf(fp,"Process Exit Code: %ld\n",  *buf[4]);
		fprintf(fp,"Process Exit Signal: %ld\n",  *buf[5]);
		fprintf(fp,"Process RT Priority: %ld\n",  *buf[6]);
		fprintf(fp,"Process Static Priority: %ld\n",  *buf[7]);
		fprintf(fp,"Process Normal Priority: %ld\n",  *buf[8]);
		fclose(fp);

	}
	



	// printf("%ld", *buf[0]); 
	return 0;
}