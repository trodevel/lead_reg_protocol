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

// $Revision: 12188 $ $Date:: 2019-10-18 #$ $Author: serge $

#include <string>
#include <sstream>              // std::ostringstream

#include "enums.h"              // request_type_e
#include "user_reg_protocol.h"  // User

namespace user_reg_protocol {

class StrHelper
{
public:
    static const std::string & to_string( const request_type_e l );
    static const std::string & to_string( const gender_e l );

    static std::ostream & write( std::ostream & os, const User & r );

    template<class T>
    static std::string to_string( const T & l )
    {
        std::ostringstream os;

        write( os, l );

        return os.str();
    }
};

} // namespace user_reg_protocol
