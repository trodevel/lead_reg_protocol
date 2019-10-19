/*

Parser.

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

// $Revision: 12191 $ $Date:: 2019-10-18 #$ $Author: serge $

#include "parser.h"                 // self

#include <map>
#include <stdexcept>                // std::invalid_argument

namespace user_reg_protocol {

#define TUPLE_VAL_STR(_x_)  _x_,#_x_
#define TUPLE_STR_VAL(_x_)  #_x_,_x_
#define TUPLE_VAL_STR_PREF(_x_,_p_)  _x_,_p_+std::string(#_x_)

template< typename _U, typename _V >
std::pair<_V,_U> make_inverse_pair( _U first, _V second )
{
    return std::make_pair( second, first );
}

request_type_e Parser::to_request_type( const std::string & s )
{
    typedef std::map< std::string, request_type_e > Map;
    static const Map m =
    {
        make_inverse_pair( request_type_e:: TUPLE_VAL_STR_PREF( RegisterUserRequest, "user_reg/" ) ),
        make_inverse_pair( request_type_e:: TUPLE_VAL_STR_PREF( ConfirmRegistrationRequest, "user_reg/" ) ),
    };

    auto it = m.find( s );

    if( it == m.end() )
        return request_type_e::UNDEF;

    return it->second;
}

} // namespace user_reg_protocol
