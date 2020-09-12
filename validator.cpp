// includes
#include "validator.h"
#include "generic_protocol/validator.h"
#include "basic_objects/validator.h"
#include "basic_parser/validator.h"

namespace user_reg_protocol
{

namespace validator
{

using ::basic_parser::validator::validate;
using ::basic_parser::validator::validate_t;

// enums

// objects

bool validate( const std::string & prefix, const User & r )
{
    ::basic_objects::validator::validate( prefix + ".GENDER", r.gender );
    validate( prefix + ".LOGIN", r.login ); // String
    validate( prefix + ".LAST_NAME", r.last_name ); // String
    validate( prefix + ".FIRST_NAME", r.first_name ); // String
    ::basic_objects::validator::validate( prefix + ".EMAIL", r.email );
    validate( prefix + ".PHONE", r.phone ); // String
    ::basic_objects::validator::validate( prefix + ".BIRTHDAY", r.birthday );

    return true;
}

// base messages

bool validate( const Request & r )
{
    // no base class

    return true;
}

bool validate( const BackwardMessage & r )
{
    // base class
    ::generic_protocol::validator::validate( static_cast<const generic_protocol::BackwardMessage&>( r ) );


    return true;
}

// messages

bool validate( const RegisterUserRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "LEAD", r.lead );

    return true;
}

bool validate( const RegisterUserResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );


    return true;
}

bool validate( const ConfirmRegistrationRequest & r )
{
    // base class
    validator::validate( static_cast<const Request&>( r ) );

    validate( "REGISTRATION_KEY", r.registration_key, true, true, static_cast<std::size_t>( 1 ), true, true, static_cast<std::size_t>( 256 ) ); // String

    return true;
}

bool validate( const ConfirmRegistrationResponse & r )
{
    // base class
    validator::validate( static_cast<const BackwardMessage&>( r ) );


    return true;
}

} // namespace validator

} // namespace user_reg_protocol

