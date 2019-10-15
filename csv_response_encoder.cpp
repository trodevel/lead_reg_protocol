/*

CSV response encoder.

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

// $Revision: 10620 $ $Date:: 2019-03-10 #$ $Author: serge $

#include "csv_response_encoder.h"       // self

#include <typeinfo>                     // typeid

#include "utils/nonascii_hex_codec.h"   // nonascii_hex_codec
#include "utils/csv_helper.h"           // CsvHelper
#include "utils/utils_assert.h"               // ASSERT

#include "generic_protocol/csv_helper.h"    // generic_protocol::CsvHelper::to_csv()
#include "basic_objects/csv_helper.h"       // basic_objects::CsvHelper::write()

#include "str_helper.h"

#define MODULENAME      "lead_reg_protocol::CsvResponseEncoder"

NAMESPACE_LEAD_REG_PROTOCOL_START

std::string CsvResponseEncoder::to_csv( const generic_protocol::BackwardMessage & r )
{
    if( typeid( r ) == typeid( RegisterLeadResponse ) )
    {
        return to_csv( static_cast<const RegisterLeadResponse&>( r ) );
    }
    else
    {
        return generic_protocol::CsvHelper::to_csv( r );
    }
}

std::ostream & CsvResponseEncoder::write( std::ostream & os, const Lead & r )
{
    utils::CsvHelper::write(
            os,
            static_cast<unsigned>( r.gender ),
            utils::nonascii_hex_codec::encode( r.name ),
            utils::nonascii_hex_codec::encode( r.first_name ) );

    basic_objects::CsvHelper::write( os, r.email );

    utils::CsvHelper::write(
            os,
            utils::nonascii_hex_codec::encode( r.phone ) );

    basic_objects::CsvHelper::write( os, r.birthday );

    return os;
}

std::string CsvResponseEncoder::to_csv( const RegisterLeadResponse & r )
{
    return utils::CsvHelper::to_csv( "lead_reg/RegisterLeadResponse" );
}


NAMESPACE_LEAD_REG_PROTOCOL_END
