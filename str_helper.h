#ifndef APG_USER_REG_PROTOCOL__STR_HELPER_H
#define APG_USER_REG_PROTOCOL__STR_HELPER_H

// system includes
#include <sstream>

// includes
#include "protocol.h"

namespace user_reg_protocol
{

namespace str_helper
{

// enums

// objects
std::ostream & write( std::ostream & os, const User & r );

// base messages
std::ostream & write( std::ostream & os, const Request & r );
std::ostream & write( std::ostream & os, const BackwardMessage & r );

// messages
std::ostream & write( std::ostream & os, const RegisterUserRequest & r );
std::ostream & write( std::ostream & os, const RegisterUserResponse & r );
std::ostream & write( std::ostream & os, const ConfirmRegistrationRequest & r );
std::ostream & write( std::ostream & os, const ConfirmRegistrationResponse & r );

template<class T>
std::string to_string( const T & l )
{
    std::ostringstream os;

    write( os, l );

    return os.str();
}

} // namespace str_helper

} // namespace user_reg_protocol

#endif // APG_USER_REG_PROTOCOL__STR_HELPER_H
