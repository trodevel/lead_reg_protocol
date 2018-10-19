/*

Lead/Registration Protocol messages.

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

// $Revision: 9869 $ $Date:: 2018-10-18 #$ $Author: serge $

#ifndef LIB_LEAD_REG_PROTOCOL_LEAD_REG_PROTOCOL_H
#define LIB_LEAD_REG_PROTOCOL_LEAD_REG_PROTOCOL_H

#include "generic_protocol/generic_protocol.h"  // generic_protocol::Request
#include "basic_objects/basic_objects.h"        // basic_objects::Email

#include "namespace_lib.h"      // NAMESPACE_LEAD_REG_PROTOCOL_START

NAMESPACE_LEAD_REG_PROTOCOL_START

struct Request: public generic_protocol::Request
{
    virtual ~Request() {};
};

struct BackwardMessage: public generic_protocol::BackwardMessage
{
};

enum class gender_e
{
    UNDEF   = 0,
    MALE    = 1,
    FEMALE  = 2,
};

struct Lead
{
    gender_e                gender;
    std::string             name;
    std::string             first_name;
    basic_objects::Email    email;
    std::string             phone;
    basic_objects::Date     birthday;
};

struct RegisterLeadRequest: public Request
{
    Lead            lead;
};

struct RegisterLeadResponse: public BackwardMessage
{
};

NAMESPACE_LEAD_REG_PROTOCOL_END

#endif // LIB_LEAD_REG_PROTOCOL_LEAD_REG_PROTOCOL_H
