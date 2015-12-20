// Time-stamp: <2015-12-20 18:10:42 daniel>
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
