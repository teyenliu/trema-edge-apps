#include <inttypes.h>
#include "trema.h"

static void
handle_switch_ready( uint64_t datapath_id, void *user_data ) {
  info( "Hello %#" PRIx64 " from %s!", datapath_id, user_data );
  stop_trema();
}

int
main( int argc, char *argv[] ) {
  init_trema( &argc, &argv );

  set_switch_ready_handler( handle_switch_ready, argv[ 0 ] );

  start_trema();

  return 0;
}
