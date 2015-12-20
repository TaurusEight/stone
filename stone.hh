// Time-stamp: <2015-12-20 18:25:08 daniel>
#ifndef __STONE_HH__
#define __STONE_HH__

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
// stone.hh: Defines a simple file based thread-safe logging class
//
// Define __LOG_TO_FILE__ before including this header then
// use either INFO( message ), WARN( message ) or ERROR( message )
//

// Required header files
//-----------------------------------------------------------------------------
#include <fstream>  // std::ofstream
#include <mutex>  // std::mutex
#include <memory>  // std::uniquie_ptr
#include <iostream>  // std::cerr


// Namespace used with this class
//-----------------------------------------------------------------------------
namespace stone {

  // Logging class
  //---------------------------------------------------------------------------
  class log : public std::ofstream {

  public:

    typedef std::unique_ptr< log > log_ptr;

    virtual ~log();

    static void file( const char* );

    static log_ptr info();
    static log_ptr warn();
    static log_ptr error();

  protected:

    std::ios_base::openmode mode();

  private:

    static const char* the_file_name;
    static std::mutex the_mutex;
    static bool has_been_opened;

    log();  // private constructor
    static log_ptr output( const char* );

  };  // end class log


};  // end NS stone


// Macros
//-----------------------------------------------------------------------------
#define LOGFILE( F )
#ifdef __LOG_TO_FILE__
#undef LOGFILE
#define LOGFILE( F ) stone::log::file( F )
#define INFO( M ) *stone::log::info() << M
#define WARN( M ) *stone::log::warn() << M
#define ERROR( M )  *stone::log::error() << M
#elif defined __LOG_TO_CERR__
#define INFO( M ) std::cerr << "INFO: " << M
#define WARN( M ) std::cerr << "WARN: " << M
#define ERROR( M ) std::cerr << "ERROR: " << M
#else  // neither defined
#define INFO( M )
#define WARN( M )
#define ERROR( M )
#endif  // __LOG__


#endif  // __STONE_HH__
