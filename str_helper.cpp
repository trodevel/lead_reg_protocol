// system includes
#include <map>

// includes
#include "str_helper.h"
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

std::ostream & write( std::ostream & os, const gender_e r )
{
    typedef gender_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( UNDEF ) },
        { Type:: TUPLE_VAL_STR( MALE ) },
        { Type:: TUPLE_VAL_STR( FEMALE ) },
    };

    auto it = m.find( r );

    static const std::string undef( "undef" );

    if( it != m.end() )
        return write( os, it->second );

    return write( os, undef );
}

// objects

std::ostream & write( std::ostream & os, const User & r )
{
    os << "(";

    os << " gender="; write( os, r.gender );
    os << " name="; write( os, r.name );
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


    os << ")";

    return os;
}

std::ostream & write( std::ostream & os, const BackwardMessage & r )
{
    os << "(";


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

