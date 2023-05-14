#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "args.h"
#include "events.h"
#include "osc.h"
#include "spindle.h"
#include "input.h"
#include "device/device_monitor.h"

void print_version(void);

void cleanup(void) {
  dev_monitor_deinit();
  osc_deinit();
  s_deinit();
  fprintf(stderr, "seamstress shutdown complete\n");
  printf("Bye!\n");
  exit(0);
}

int main(int argc, char **argv) {
  args_parse(argc, argv);
  print_version();

  fprintf(stderr, "starting event handler\n");
  events_init();

  fprintf(stderr, "starting spindle\n");
  s_init();

  fprintf(stderr, "starting device monitor\n");
  dev_monitor_init();

  atexit(cleanup);

  fprintf(stderr, "starting osc\n");
  osc_init();

  fprintf(stderr, "starting input\n");
  input_init();

  fprintf(stderr, "spinning spindle\n");
  s_startup();

  fprintf(stderr, "scanning for devices\n");
  dev_monitor_scan();

  fprintf(stderr, "handling events\n");
  event_handle_pending();

  fprintf(stderr, "starting main loop\n");
  event_loop();
}

void print_version(void) {
  printf("SEAMSTRESS\n");
  printf("seamstress version: %d.%d.%d\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
}
