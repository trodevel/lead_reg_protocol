/*

Request Parser.

Copyright (C) 2018 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 12177 $ $Date:: 2019-10-15 #$ $Author: serge $

#include "request_parser.h"         // self

#include "basic_parser/get_value.h" // basic_parser::get_value_or_throw
#include "basic_objects/parser.h"   // basic_objects::Parser

#include "parser.h"                 // Parser
#include "generic_protocol/request_parser.h" // generic_protocol::RequestParser::to_request()
#include "request_validator.h"      // RequestValidator

namespace user_reg_protocol {

using basic_parser::get_value_or_throw;
using basic_parser::get_value_or_throw_uint32;

generic_protocol::ForwardMessage* RequestParser::to_forward_message( const generic_request::Request & r )
{
    auto type = RequestParser::detect_request_type( r );

    typedef RequestParser Type;

    typedef ForwardMessage* (*PPMF)( const generic_request::Request & r );

    static const std::map<request_type_e, PPMF> funcs =
    {
        { request_type_e::RegisterLeadRequest,              & Type::to_RegisterLeadRequest },
    };

    auto it = funcs.find( type );

    if( it != funcs.end() )
        return it->second( r );

    return nullptr;
}

request_type_e  RequestParser::detect_request_type( const generic_request::Request & r )
{
    std::string cmd;

    if( r.get_value( "CMD", cmd ) == false )
        throw MalformedRequest( "CMD is not defined" );

    return Parser::to_request_type( cmd );
}

void RequestParser::to_Lead( Lead & res, const generic_request::Request & r )
{
    basic_objects::Parser::to_Date( & res.birthday, "BIRTHDAY", r );
    basic_objects::Parser::to_Email( & res.email, "EMAIL", r );

    uint32_t    gender;

    get_value_or_throw_uint32( gender,       "GENDER", r );

    res.gender   = static_cast<gender_e>( gender );

    r.get_value( "NAME",        res.name );
    r.get_value( "FIRST_NAME",  res.first_name );
    r.get_value( "PHONE",       res.phone );
}

RequestParser::ForwardMessage * RequestParser::to_RegisterLeadRequest( const generic_request::Request & r )
{
    auto * res = new RegisterLeadRequest;

    to_Lead( res->lead, r );

    generic_protocol::RequestParser::to_request( res, r );

    RequestValidator::validate( * res );

    return res;
}

} // namespace user_reg_protocol
