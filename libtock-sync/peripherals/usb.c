#include "usb.h"

struct usb_data {
  bool fired;
  returncode_t ret;
};

static struct usb_data result = { .fired = false };

static void usb_callback(returncode_t ret) {
  result.fired = true;
  result.ret   = ret;
}

returncode_t libtocksync_usb_enable_and_attach(void) {
  int err;

  result.fired = false;

  err = libtock_usb_enable_and_attach(usb_callback);
  if (err != RETURNCODE_SUCCESS) return err;

  yield_for(&result.fired);
  return result.ret;
}
