#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

static void syscall_handler (struct intr_frame *);

struct file_descriptor_node{//index is fd
  uint32_t* fd;
  uint32_t* pid_t;
  uint32_t* pd;
};

static struct list fd_list;

/* System Call Functions */
void halt();
void exit(int status);
pid_t exec(const char* cmd_line);
pid_t wait(pid_t pid);
bool create(const char* file, unsigned initial_size);
bool remove(const char *file);
int open(const char *file);
int filesize(int fd);
int read(int fd, void *buffer, unsigned size);
int write(int fd, const void *buffer, unsigned size);
void seek(int fd, unsigned position);
void tell(int fd);
void close(int fd);

void
syscall_init (void) 
{
  list_init (&fd_list);
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

void syscall_handler (struct intr_frame * frame)
{
  switch( *(frame->esp) )
  {
  case SYS_HALT:
    break;
    
  case SYS_EXIT:
    break;
    
  case SYS_EXEC:
    break;
    
  case SYS_WAIT:
    break;
    
  case SYS_CREATE:
    break;
    
  case SYS_REMOVE:
    break;
    
  case SYS_OPEN:
    break;
  
  case SYS_READ:
    break;
  
  case SYS_WRITE:
    break;
  
  case SYS_SEEK:
    break;
  
  case SYS_TELL:
    break;
  
  case SYS_CLOSE:
    break;
  
  case SYS_HALT:
    break;
  
  case SYS_HALT:
    break;
  }
}

// Call functions implementation
void halt()
{
  //TODO
}

void exit(int status)
{
  //TODO
}

pid_t exec(const char* cmd_line)
{
  const char delim[2] = " ";
  char* token = strtok(cmd_line, delim);
  char* commandToRun = token;
  char** args;
  
  int i = 0;
  while( token != NULL ) {
      args[i] = token;
      token = strtok(NULL, s);
      i++;
   }
   
   //run command args
}

pid_t wait(pid_t pid)
{
  //TODO
}

bool create(const char* file, unsigned initial_size)
{
  //TODO
}

bool remove(const char *file)
{
  //TODO
}

int open(const char *file)
{
  int i = 2;
  
  struct list_elem *e;

  ASSERT (intr_get_level () == INTR_OFF);

  for (e = list_begin (&all_list); e != list_end (&all_list); e = list_next (e))
    {
      struct file_descriptor_node *fdn = list_entry (e, struct thread, allelem);
      if(fdn != i){
      }
      
    }
  
  //Create list entry with 
}

int filesize(int fd)
{
  //TODO
}

int read(int fd, void *buffer, unsigned size)
{
  //TODO
}

int write(int fd, const void *buffer, unsigned size)
{
  //TODO
}

void seek(int fd, unsigned position)
{
  //TODO
}

void tell(int fd)
{
  //TODO
}

void close(int fd)
{
  //TODO
}
