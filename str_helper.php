<?php

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

// $Revision: 9874 $ $Date:: 2018-10-18 #$ $Author: serge $

namespace lead_reg_protocol;

require_once 'lead_reg_protocol.php';
require_once __DIR__.'/../generic_protocol/str_helper.php';
require_once __DIR__.'/../basic_objects/str_helper.php';        // to_string_Email

function to_html_not_impl( & $obj )
{
    return get_html_table_header_elems( array( 'not implemented yet' ) );
}

function to_html_RegisterLeadResponse( & $obj )
{
    return get_html_table( NULL, NULL, NULL, 'border="1" cellspacing="1" cellpadding="3"',
        get_html_table_row_header( array( 'RESULT' ) ) .
        get_html_table_row_data( array( 'OK' ) ) );
}

// *********************************************************

function to_html( $obj )
{
    $handler_map = array(
        'lead_reg_protocol\RegisterLeadRequest'             => 'to_html_not_impl',
        'lead_reg_protocol\RegisterLeadResponse'            => 'to_html_RegisterLeadResponse',
    );

    $type = get_class ( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\lead_reg_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return NULL;
}

?>