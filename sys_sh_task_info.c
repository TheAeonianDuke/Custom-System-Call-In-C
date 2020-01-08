#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/sched.h>
#include<linux/syscalls.h>
#include<linux/sched.h> 
#include <linux/slab.h>
// #incldde <linux/ioctl.h>

asmlinkage long sys_sh_task_info(int pid,char *filename,long **buf)
{
  struct task_struct *task;
  // struct task_struct *temp;
  struct pid *pid_str;
  pid_str=find_vpid(pid);

  task=pid_task(pid_str, PIDTYPE_PID);

  if (task == NULL)
  {
    printk(KERN_ERR "No Process with given PID\n");
       
    return "3";
  }

  else
  {
    long buf_kernel[50];
    long *user_ptrs[50];
    unsigned long res;
    int i;
    printk(KERN_ERR "Process: %s\n",  task->comm);
    printk(KERN_ERR "PID: %ld\n",  (long)task_pid_nr(task));
    printk(KERN_ERR "Process State: %ld\n",  (long)task->state);
    printk(KERN_ERR "Priority: %ld\n",  (long)task->prio);
    printk(KERN_ERR "Process Exit State: %ld\n",  (long)task->exit_state);
    printk(KERN_ERR "Process Exit Code: %ld\n",  (long)task->exit_code);
    printk(KERN_ERR "Process Exit Signal: %ld\n",  (long)task->exit_signal);
    printk(KERN_ERR "Process RT Priority: %ld\n",  (long)task->rt_priority);
    printk(KERN_ERR "Process Static Priority: %ld\n",  (long)task->static_prio);
    printk(KERN_ERR "Process Normal Priority: %ld\n",  (long)task->normal_prio);
    
    
    // char pidval[100];
    // char state[100];
    // char prio[100];
    // char exit_state[100];
    // char exit_signal[100];
    // char exit_code[100];
    // char rt_priority[100];
    // char static_prio[100];
    // char normal_prio[100];
    // snprintf(pidval,40,"%ld",(long)task_pid_nr(task));
    // snprintf(state,40,"%ld",(long)task->state);
    // snprintf(prio,40,"%ld",(long)task->prio);
    // snprintf(exit_signal,40,"%ld",(long)task->exit_state);
    // snprintf(exit_code,40,"%ld",(long)task->exit_code);
    // snprintf(exit_signal,40,"%ld",(long)task->exit_signal);
    // snprintf(rt_priority,40,"%ld",(long)task->rt_priority);
    // snprintf(static_prio,40,"%ld",(long)task->static_prio);
    // snprintf(normal_prio,40,"%ld",(long)task->normal_prio);
    printk(KERN_ERR "Creating File....");

    // buf_kernel[0]="0";
    buf_kernel[0]=(long)task_pid_nr(task);
    buf_kernel[1]=(long)task->state;
    buf_kernel[2]=(long)task->prio;
    buf_kernel[3]=(long)task->exit_state;
    buf_kernel[4]=(long)task->exit_code;
    buf_kernel[5]=(long)task->exit_signal;
    buf_kernel[6]=(long)task->rt_priority;
    buf_kernel[7]=(long)task->static_prio;
    buf_kernel[8]=(long)task->normal_prio;

    // buf_kernel[0]=(char)filename;
    // buf_kernel[1]=(char)comm;
    // buf_kernel[2]=(char)pidval;
    // buf_kernel[3]=(char)state;
    // buf_kernel[4]=(char)prio;
    // buf_kernel[5]=(char)exit_state;
    // buf_kernel[6]=(char)exit_signal;
    // buf_kernel[7]=(char)exit_code;
    // buf_kernel[8]=(char)rt_priority;
    // buf_kernel[9]=(char)static_prio;
    // buf_kernel[10]=(char)normal_prio;


    res = copy_from_user(user_ptrs,buf,sizeof(long *)* 50);

    for (i=0; i<50; i++)
    {
      res=copy_to_user(user_ptrs[i],&buf_kernel[i],sizeof(long));
    }
    
    return 0;
  }


}

// char **create_file(char* file_name)
// {
  

 
// }

// asmlinkage void sh_task_info(int pid, )
// {
//   print_proc(pid);
//   // create_file(file_name);
  
// }


