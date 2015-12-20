// Time-stamp: <2015-12-20 17:46:00 daniel>
#ifndef __STONE_HH__
#define __STONE_HH__

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
#ifdef __LOG__
#define LOGFILE( F ) stone::log::file( F )
#define INFO( M ) *stone::log::info() << M
#define WARN( M ) *stone::log::warn() << M
#define ERROR( M )  *stone::log::error() << M
#else
#define LOGFILE( F )
#define INFO( M )
#define WARN( M )
#define ERROR( M )
#endif  // __LOG__


#endif  // __STONE_HH__
