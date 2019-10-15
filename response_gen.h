/*

Protocol response generator.

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

// $Revision: 12181 $ $Date:: 2019-10-15 #$ $Author: serge $

#ifndef LIB_USER_REG_PROTOCOL__RESPONSE_GEN_H
#define LIB_USER_REG_PROTOCOL__RESPONSE_GEN_H

#include "user_reg_protocol.h"        // SayResponse

namespace user_reg_protocol {

inline RegisterLeadResponse * create_RegisterLeadResponse()
{
    auto * res = new RegisterLeadResponse;

    return res;
}

} // namespace user_reg_protocol

#endif // LIB_USER_REG_PROTOCOL__RESPONSE_GEN_H
