/*

Core enums.

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

#ifndef LEAD_REG_PROTOCOL_ENUMS_H
#define LEAD_REG_PROTOCOL_ENUMS_H

namespace user_reg_protocol {

enum class request_type_e
{
    UNDEF,
    RegisterUserRequest,
    ConfirmRegistrationRequest,
};

} // namespace user_reg_protocol

#endif // LEAD_REG_PROTOCOL_ENUMS_H
