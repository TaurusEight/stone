// Time-stamp: <2015-12-20 18:27:32 daniel>


// Copyright (c) 2015 by Daniel Mendyke
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.


//
// stone.cc: Source definitions for this logging class
//


// Required header files
//-----------------------------------------------------------------------------
#include <cstring>  // strcmp
#include "stone.hh"  // stone::log


// NS short hand
//-----------------------------------------------------------------------------
using namespace stone;


// static constants
//-----------------------------------------------------------------------------
const char* log::the_file_name = "log.out";
std::mutex log::the_mutex;
bool log::has_been_opened = false;


// constructor
//-----------------------------------------------------------------------------
log::log( ) : std::ofstream() {

  log::the_mutex.lock();  // lock access to this log file
  open( log::the_file_name, mode() );
  log::has_been_opened = true;

};  // end constructor


// Return the open mode - trunc file if this is the first time it is opened
//-----------------------------------------------------------------------------
std::ios_base::openmode log::mode() {

  using namespace std;

  ios_base::openmode result = ios_base::out;
  result |= log::has_been_opened ? ios_base::app : ios_base::trunc;
  return result;

};  // end mode


// destructor
//-----------------------------------------------------------------------------
log::~log() {

  log::the_mutex.unlock();  // unlock access to the log file

};  // end destructor


// Main logging function - returns auto pointer to a log instance
//-----------------------------------------------------------------------------
log::log_ptr log::output( const char* level ) {

  log_ptr result( new log );
  *result << level << ": ";

  return result;

};  // end output


// Change name of the log file
//-----------------------------------------------------------------------------
void log::file( const char* file_name ) {

  if ( strcmp( log::the_file_name, file_name ) != 0x0 )
    log::has_been_opened = false;

  log::the_file_name = file_name;

};  // end file


// Logging functions
//-----------------------------------------------------------------------------
log::log_ptr log::warn() { return log::output( "WARN" ); };
log::log_ptr log::info() { return log::output( "INFO" ); };
log::log_ptr log::error() { return log::output( "ERROR" ); };
