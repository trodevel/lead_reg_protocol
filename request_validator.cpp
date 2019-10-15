/*

Request Validator.

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


#include "request_validator.h"      // self

#include "request_parser.h"         // MalformedRequest

#include "generic_protocol/request_validator.h" // generic_protocol::RequestValidator::validate
#include "basic_objects/validator.h"            // basic_objects::Validator::validate

namespace user_reg_protocol {

bool RequestValidator::validate( const Lead & r )
{
    if( r.gender < gender_e::UNDEF || r.gender > gender_e::FEMALE )
        throw RequestParser::MalformedRequest( "unsupported gender " + std::to_string( static_cast<int>( r.gender ) ) );

    if( r.email.email.empty() && r.phone.empty() )
        throw RequestParser::MalformedRequest( "email and phone are empty" );

    if( r.email.email.empty() == false )
        basic_objects::Validator::validate( r.email );

    return true;
}

bool RequestValidator::validate( const RegisterLeadRequest & r )
{
    validate( r.lead );

    return true;
}

} // namespace user_reg_protocol
