#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sig_handler(int sig) {
  switch(sig) {
    case SIGABRT:
      printf("Received SIGABRT\n");
      break;
    case SIGFPE:
      printf("Received SIGFPE\n");
      break;
    case SIGILL:
      printf("Received SIGILL\n");
      break;
    case SIGINT:
      printf("Received SIGINT\n");
      break;
    case SIGSEGV:
      printf("Received SIGSEGV\n");
      break;
    case SIGTERM:
      printf("Received SIGTERM\n");
      break;
  }
}

int main() {
  signal(SIGABRT, sig_handler);
  signal(SIGFPE, sig_handler);
  signal(SIGILL, sig_handler);
  signal(SIGINT, sig_handler);
  signal(SIGSEGV, sig_handler);
  signal(SIGTERM, sig_handler);

  int choice;
  while(1) {
    printf("Enter signal to raise (1-6), or 0 to exit: ");
    scanf("%d", &choice);
    if (choice == 0) {
      printf("Exiting...\n");
      break;
    }
    switch(choice) {
      case 1:
        raise(SIGABRT);
        break;
      case 2:
        raise(SIGFPE);
        break;
      case 3:
        raise(SIGILL);
        break;
      case 4:
        raise(SIGINT);
        break;
      case 5:
        raise(SIGSEGV);
        break;
      case 6:
        raise(SIGTERM);
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
  }

  return 0;
}
