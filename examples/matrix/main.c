#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <console.h>
#include <internal/alarm.h>

uint32_t matrixSize = 5;

static void nop(
  int   a __attribute__((unused)),
  int   b __attribute__((unused)),
  int   c __attribute__((unused)),
  void* d __attribute__((unused))) {}

int main(void) {
    char hello[50];
    sprintf(hello, "Initializing Matrix example with size %d!\r\n", matrixSize);
    putnstr(hello, strlen(hello));

    uint32_t ticks;
    alarm_internal_read(&ticks);

    char bye[30];
    sprintf(bye, "It tooks %d ticks!\r\n", ticks);
    return 0;
}

