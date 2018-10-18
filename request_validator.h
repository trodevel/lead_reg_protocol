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

// $Revision: 9867 $ $Date:: 2018-10-17 #$ $Author: serge $

#include "lead_reg_protocol.h"    // Request...

NAMESPACE_LEAD_REG_PROTOCOL_START

class RequestValidator
{
public:
    static bool validate( const Lead & r );
    static bool validate( const RegisterLeadRequest & r );
};

NAMESPACE_LEAD_REG_PROTOCOL_END

