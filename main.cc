

#define __LOG_TO_FILE__

#include <iostream>
#include "stone.hh"  // stone::log



//-----------------------------------------------------------------------------
int main( int, char*[] ) {

  LOGFILE( "sample.log" );

  INFO( "first sample message" << std::endl );
  WARN( "message one!  " << std::hex << 15 << std::endl );
  ERROR( "another message" << std::endl );

  return 0x0;

};  // end main
