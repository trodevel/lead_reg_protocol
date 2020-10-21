#ifndef APG_USER_REG_PROTOCOL__PARSER_H
#define APG_USER_REG_PROTOCOL__PARSER_H

// includes
#include "generic_request/request.h"
#include "enums.h"
#include "protocol.h"

namespace user_reg_protocol
{

namespace parser
{

typedef basic_parser::Object    Object;

basic_parser::Object * to_forward_message( const generic_request::Request & r );

request_type_e detect_request_type( const generic_request::Request & r );

// enums


// objects

void get_value_or_throw( User * res, const std::string & key, const generic_request::Request & r );

// base messages

void get_value_or_throw( Request * res, const generic_request::Request & r );
void get_value_or_throw( BackwardMessage * res, const generic_request::Request & r );

// messages

void get_value_or_throw( RegisterUserRequest * res, const generic_request::Request & r );
void get_value_or_throw( RegisterUserResponse * res, const generic_request::Request & r );
void get_value_or_throw( ConfirmRegistrationRequest * res, const generic_request::Request & r );
void get_value_or_throw( ConfirmRegistrationResponse * res, const generic_request::Request & r );

// to_... functions

Object * to_RegisterUserRequest( const generic_request::Request & r );
Object * to_RegisterUserResponse( const generic_request::Request & r );
Object * to_ConfirmRegistrationRequest( const generic_request::Request & r );
Object * to_ConfirmRegistrationResponse( const generic_request::Request & r );

} // namespace parser

} // namespace user_reg_protocol

#endif // APG_USER_REG_PROTOCOL__PARSER_H
