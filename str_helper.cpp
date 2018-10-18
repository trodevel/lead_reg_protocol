/*

String Helper. Provides to_string() function.

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

// $Revision: 9867 $ $Date:: 2018-10-17 #$ $Author: serge $

#include "str_helper.h"             // self

#include <sstream>                  // std::ostringstream
#include <iomanip>                  // std::setfill
#include <map>

#include "../lang_tools/str_helper.h"   // to_string for lang_e
#include "../utils/to_string_t.h"       // to_string()


#include "lead_reg_protocol.h"        // SayRequest

NAMESPACE_LEAD_REG_PROTOCOL_START

#define TUPLE_VAL_STR(_x_)  _x_,#_x_
#define TUPLE_STR_VAL(_x_)  #_x_,_x_

const std::string & StrHelper::to_string( const request_type_e s )
{
    typedef request_type_e Type;
    static const std::map< Type, std::string > m =
    {
        { Type:: TUPLE_VAL_STR( UNDEF ) },
        { Type:: TUPLE_VAL_STR( RegisterLeadRequest ) },
    };

    auto it = m.find( s );

    static const std::string undef( "undef" );

    if( it == m.end() )
        return undef;

    return it->second;
}

NAMESPACE_LEAD_REG_PROTOCOL_END

