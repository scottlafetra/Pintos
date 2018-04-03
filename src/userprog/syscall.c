#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

static void syscall_handler (struct intr_frame *);

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
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

void syscall_handler (struct intr_frame * frame)
{
  char* stack_pointer = frame->esp;
  switch( *stack_pointer )
  {
  case SYS_HALT:
    halt();
    break;
    
  case SYS_EXIT:
    int status = (int) *(stack_pointer - sizeof(int));
    exit( status );
    break;
    
  case SYS_EXEC:
    char* cmd_line = *(stack_pointer - sizeof(char*));
    pid_t return_pid = exec( cmd_line );
    
    // Return the value
    *(frame->eax) = (uint_32) return_pid;
    break;
    
  case SYS_WAIT:
    pid_t pid = (pid_t) *(stack_pointer - sizeof(pid_t));
    pid_t return_pid = wait( pid );
    break;
    
  case SYS_CREATE:
    char* stack_temp = stack_pointer;
    
    stack_temp -= sizeof(char*);
    char* file = *stack_temp;
    
    stack_temp -= sizeof(unsigned);
    unsigned initial_size = (unsigned) *stack_temp;
    
    bool return_sucsess = create( file, initial_size );
    // Return the value
    *(frame->eax) = (uint_32) return_sucsess;
    break;
    
  case SYS_REMOVE:
    char* file = *(stack_pointer - sizeof(char*));
    bool return_sucsess = remove( file );
    
    // Return the value
    *(frame->eax) = (uint_32) return_sucsess;
    break;
    
  case SYS_OPEN:
    char* file = *(stack_pointer - sizeof(char*));
    int return_fd = open( file );
    
    // Return the value
    *(frame->eax) = (uint_32) return_fd;
    break;
    
  case SYS_FILESIZE:
    int fd = *(stack_pointer - sizeof(int));
    int return_size = filesize( fd );
    
    // Return the value
    *(frame->eax) = (uint_32) return_size;
    break;
  
  case SYS_READ:
    char* stack_temp = stack_pointer;
    
    stack_temp -= sizeof(char*);
    int fd = *stack_temp;
    
    stack_temp -= sizeof(void*);
    void* buffer = (void*) *stack_temp;
    
    stack_temp -= sizeof(unsigned);
    unsigned size = (unsigned) *stack_temp;
    
    int return_value = read( fd, buffer, size );
    
    // Return the value
    *(frame->eax) = (uint_32) return_value;
    
    break;
  
  case SYS_WRITE:
    char* stack_temp = stack_pointer;
    
    stack_temp -= sizeof(int);
    int fd = (int) *stack_temp;
    
    stack_temp -= sizeof(void*);
    void* buffer = (void*) *stack_temp;
    
    stack_temp -= sizeof(unsigned);
    unsigned size = (unsigned) *stack_temp;
    
    int return_value = write( fd, buffer, size );
    
    // Return the value
    *(frame->eax) = (uint_32) return_value;
    break;
  
  case SYS_SEEK:
    char* stack_temp = stack_pointer;
    
    stack_temp -= sizeof(int);
    int fd = (int) *stack_temp;
    
    stack_temp -= sizeof(unsigned);
    unsigned position = (unsigned) *stack_temp;
    
    seek( fd, position );
    break;
  
  case SYS_TELL:
    int fd = (int) *(stack_pointer - sizeof(int));
    tell( file );
    break;
  
  case SYS_CLOSE:
    int fd = (int) *(stack_pointer - sizeof(int));
    close( file );
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
  //TODO
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
  //TODO
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
