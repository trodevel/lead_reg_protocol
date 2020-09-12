// system includes
#include <map>

// includes
#include "str_helper.h"
#include "generic_protocol/str_helper.h"
#include "basic_objects/str_helper.h"
#include "basic_parser/str_helper.h"

namespace user_reg_protocol
{

namespace str_helper
{

using ::basic_parser::str_helper::write;
using ::basic_parser::str_helper::write_t;

// enums

#define TUPLE_VAL_STR(_x_)  _x_,#_x_

// objects

std::ostream & write( std::ostream & os, const User & r )
{
    os << "(";

    os << " gender="; ::basic_objects::str_helper::write( os, r.gender );
    os << " login="; write( os, r.login );
    os << " last_name="; write( os, r.last_name );
    os << " first_name="; write( os, r.first_name );
    os << " email="; ::basic_objects::str_helper::write( os, r.email );
    os << " phone="; write( os, r.phone );
    os << " birthday="; ::basic_objects::str_helper::write( os, r.birthday );

    os << ")";

    return os;
}

// base messages

std::ostream & write( std::ostream & os, const Request & r )
{
    os << "(";

    // no base class

    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const BackwardMessage & r )
{
    os << "(";

    // base class
    ::generic_protocol::str_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );


    os << ")";

    return os;
}

// messages

std::ostream & write( std::ostream & os, const RegisterUserRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " lead="; write( os, r.lead );

    return os;
}

std::ostream & write( std::ostream & os, const RegisterUserResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const ConfirmRegistrationRequest & r )
{
    // base class
    str_helper::write( os, static_cast<const Request&>( r ) );

    os << " registration_key="; write( os, r.registration_key );

    return os;
}

std::ostream & write( std::ostream & os, const ConfirmRegistrationResponse & r )
{
    // base class
    str_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

} // namespace str_helper

} // namespace user_reg_protocol

