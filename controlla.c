#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 4578


int main(int argc, char* argv[]){

  int sem;

  if (!strcmp(argv[1], "-c") && argc >2 ){
    printf("testing -c:\n");
    sem = semget(KEY, 4, IPC_CREAT |IPC_EXCL| 0600);
    if (sem == -1){
      printf("Semaphore already exists.\n");
    }
    else{
      printf("Semaphore created: %d\n", sem);
      printf("Semaphore value: %d\n", semctl(sem, 0, GETVAL));
    }
    semctl(sem, 0 , SETVAL, atoi(argv[2]));
  }
  else if (!strcmp(argv[1], "-v")){
    printf("testing -v :\n");
    sem = semget(KEY, 4, 0600);
    printf("Semaphore value: %d\n", semctl(sem, 0, GETVAL));
  }
  else if (!strcmp(argv[1], "-r")){
    printf("testing -r:\n");
    sem = semget(KEY, 4, 0600);
    printf("Semaphore removed: %d\n", semctl(sem, 0, IPC_RMID));

  }

  return 0;
}
