// system includes
#include <map>
#include <memory>

// includes
#include "parser.h"
#include "generic_protocol/parser.h"
#include "basic_objects/parser.h"
#include "basic_parser/parser.h"
#include "basic_parser/malformed_request.h"
#include "validator.h"
#include "request_type_parser.h"

namespace user_reg_protocol
{

namespace parser
{

using ::basic_parser::parser::get_value_or_throw;
using ::basic_parser::parser::get_value_or_throw_t;

// enums

// objects

void get_value_or_throw( User * res, const std::string & prefix, const generic_request::Request & r )
{
    ::basic_objects::parser::get_value_or_throw( & res->gender, prefix + ".GENDER", r );
    get_value_or_throw( & res->login, prefix + ".LOGIN", r );
    get_value_or_throw( & res->last_name, prefix + ".LAST_NAME", r );
    get_value_or_throw( & res->first_name, prefix + ".FIRST_NAME", r );
    ::basic_objects::parser::get_value_or_throw( & res->email, prefix + ".EMAIL", r );
    get_value_or_throw( & res->phone, prefix + ".PHONE", r );
    ::basic_objects::parser::get_value_or_throw( & res->birthday, prefix + ".BIRTHDAY", r );
}

// base messages

void get_value_or_throw( Request * res, const generic_request::Request & r )
{
    // no base class
}

void get_value_or_throw( BackwardMessage * res, const generic_request::Request & r )
{
    // base class
    ::generic_protocol::parser::get_value_or_throw( static_cast<generic_protocol::BackwardMessage*>( res ), r );

}

// messages

void get_value_or_throw( RegisterUserRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->lead, "LEAD", r );
}

void get_value_or_throw( RegisterUserResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

}

void get_value_or_throw( ConfirmRegistrationRequest * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<Request*>( res ), r );

    get_value_or_throw( & res->registration_key, "REGISTRATION_KEY", r );
}

void get_value_or_throw( ConfirmRegistrationResponse * res, const generic_request::Request & r )
{
    // base class
    parser::get_value_or_throw( static_cast<BackwardMessage*>( res ), r );

}

// to object

Object * to_RegisterUserRequest( const generic_request::Request & r )
{
    std::unique_ptr<RegisterUserRequest> res( new RegisterUserRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_RegisterUserResponse( const generic_request::Request & r )
{
    std::unique_ptr<RegisterUserResponse> res( new RegisterUserResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_ConfirmRegistrationRequest( const generic_request::Request & r )
{
    std::unique_ptr<ConfirmRegistrationRequest> res( new ConfirmRegistrationRequest );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

Object * to_ConfirmRegistrationResponse( const generic_request::Request & r )
{
    std::unique_ptr<ConfirmRegistrationResponse> res( new ConfirmRegistrationResponse );

    get_value_or_throw( res.get(), r );

    validator::validate( * res );

    return res.release();
}

// to forward message

basic_parser::Object* to_forward_message( const generic_request::Request & r )
{
    auto type = detect_request_type( r );

    typedef request_type_e KeyType;

    typedef Object* (*PPMF)( const generic_request::Request & r );

#define HANDLER_MAP_ENTRY(_v)       { KeyType::_v,    & to_##_v }

    static const std::map<KeyType, PPMF> funcs =
    {
        HANDLER_MAP_ENTRY( RegisterUserRequest ),
        HANDLER_MAP_ENTRY( RegisterUserResponse ),
        HANDLER_MAP_ENTRY( ConfirmRegistrationRequest ),
        HANDLER_MAP_ENTRY( ConfirmRegistrationResponse ),
    };

#undef HANDLER_MAP_ENTRY

    auto it = funcs.find( type );

    if( it != funcs.end() )
        return it->second( r );

    return generic_protocol::parser::to_forward_message( r );
}

using basic_parser::MalformedRequest;

request_type_e  detect_request_type( const generic_request::Request & r )
{
    std::string cmd;

    if( r.get_value( "CMD", cmd ) == false )
        throw MalformedRequest( "CMD is not defined" );

    return RequestTypeParser::to_request_type( cmd );
}

} // namespace parser

} // namespace user_reg_protocol

