#include "read_only_state.h"

returncode_t libtocksync_read_only_state_quick_yield(void* base, int* pending_tasks) {
  if (yield_check_tasks()) {
    *pending_tasks = 1;
    return RETURNCODE_SUCCESS;
  } else {
    uint32_t tasks = libtock_read_only_state_get_pending_tasks(base);

    if (tasks > 0) {
      // Waiting tasks, call yield
      yield();
    }

    *pending_tasks = tasks;
    return RETURNCODE_SUCCESS;
  }
}
