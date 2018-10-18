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

#include <string>
#include <sstream>

#include "enums.h"              // request_type_e
#include "lead_reg_protocol.h"  // JobInfo::type_e, OpenJobStatus::state_e

#include "namespace_lib.h"      // NAMESPACE_LEAD_REG_PROTOCOL_START

NAMESPACE_LEAD_REG_PROTOCOL_START

class StrHelper
{
public:
    static const std::string & to_string( const request_type_e l );


    template<class T>
    static std::string to_string( const T & l )
    {
        std::ostringstream os;

        write( os, l );

        return os.str();
    }
};

NAMESPACE_LEAD_REG_PROTOCOL_END
