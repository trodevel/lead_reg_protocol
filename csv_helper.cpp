// system includes
#include <map>
#include <typeindex>

// includes
#include "csv_helper.h"
#include "generic_protocol/csv_helper.h"
#include "basic_objects/csv_helper.h"
#include "basic_parser/csv_helper.h"

namespace user_reg_protocol
{

namespace csv_helper
{

using ::basic_parser::csv_helper::write;
using ::basic_parser::csv_helper::write_t;

// enums

// objects

std::ostream & write( std::ostream & os, const User & r )
{
    ::basic_objects::csv_helper::write( os, r.gender );
    write( os, r.login );
    write( os, r.last_name );
    write( os, r.first_name );
    ::basic_objects::csv_helper::write( os, r.email );
    write( os, r.phone );
    ::basic_objects::csv_helper::write( os, r.birthday );

    return os;
}

// base messages

std::ostream & write( std::ostream & os, const Request & r )
{
    // no base class

    return os;
}

std::ostream & write( std::ostream & os, const BackwardMessage & r )
{
    // base class
    ::generic_protocol::csv_helper::write( os, static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return os;
}

// messages

std::ostream & write( std::ostream & os, const RegisterUserRequest & r )
{
    write( os, std::string( "user_reg_protocol/RegisterUserRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.lead );
    write( os, r.password );

    return os;
}

std::ostream & write( std::ostream & os, const RegisterUserResponse & r )
{
    write( os, std::string( "user_reg_protocol/RegisterUserResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write( std::ostream & os, const ConfirmRegistrationRequest & r )
{
    write( os, std::string( "user_reg_protocol/ConfirmRegistrationRequest" ) );

    // base class
    csv_helper::write( os, static_cast<const Request&>( r ) );

    write( os, r.registration_key );

    return os;
}

std::ostream & write( std::ostream & os, const ConfirmRegistrationResponse & r )
{
    write( os, std::string( "user_reg_protocol/ConfirmRegistrationResponse" ) );

    // base class
    csv_helper::write( os, static_cast<const BackwardMessage&>( r ) );


    return os;
}

std::ostream & write_RegisterUserRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const RegisterUserRequest &>( rr );

    return write( os, r );
}

std::ostream & write_RegisterUserResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const RegisterUserResponse &>( rr );

    return write( os, r );
}

std::ostream & write_ConfirmRegistrationRequest( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const ConfirmRegistrationRequest &>( rr );

    return write( os, r );
}

std::ostream & write_ConfirmRegistrationResponse( std::ostream & os, const basic_parser::Object & rr )
{
    auto & r = dynamic_cast< const ConfirmRegistrationResponse &>( rr );

    return write( os, r );
}


std::ostream & write( std::ostream & os, const basic_parser::Object & r )
{
    typedef std::ostream & (*PPMF)( std::ostream & os, const basic_parser::Object & );

#define HANDLER_MAP_ENTRY(_v)       { typeid( _v ),        & write_##_v }

    static const std::map<std::type_index, PPMF> funcs =
    {
        HANDLER_MAP_ENTRY( RegisterUserRequest ),
        HANDLER_MAP_ENTRY( RegisterUserResponse ),
        HANDLER_MAP_ENTRY( ConfirmRegistrationRequest ),
        HANDLER_MAP_ENTRY( ConfirmRegistrationResponse ),
    };

#undef HANDLER_MAP_ENTRY

    auto it = funcs.find( typeid( r ) );

    if( it != funcs.end() )
        return it->second( os, r );

    return ::generic_protocol::csv_helper::write( os, r );
}

} // namespace csv_helper

} // namespace user_reg_protocol

