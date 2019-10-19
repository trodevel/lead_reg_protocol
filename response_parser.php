<?php

/*

Response Parser.

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

// $Revision: 12194 $ $Date:: 2019-10-18 #$ $Author: serge $

namespace user_reg_protocol;

require_once __DIR__.'/../php_snippets/nonascii_hex_codec.php';     // \utils\nonascii_hex_codec\decode()
require_once __DIR__.'/../generic_protocol/response_parser.php';    // generic_protocol\create_parse_error()
require_once __DIR__.'/../basic_objects/parser.php';                // \basic_objects\parse_Email
require_once 'user_reg_protocol.php';

function parse_RegisterUserResponse( & $resp )
{
    // RegisterUserResponse;

    $res = new RegisterUserResponse;

    return $res;
}

function parse_ConfirmRegistrationResponse( & $resp )
{
    // ConfirmRegistrationResponse;

    $res = new ConfirmRegistrationResponse;

    return $res;
}

class ResponseParser extends \generic_protocol\ResponseParser
{

protected static function parse_csv_array( $csv_arr )
{
    if( sizeof( $csv_arr ) < 1 )
        return self::create_parse_error();

    $type = $csv_arr[0][0];

    $func_map = array(
        'user_reg/RegisterUserResponse'         => 'parse_RegisterUserResponse',
        'user_reg/ConfirmRegistrationResponse'  => 'parse_ConfirmRegistrationResponse',
        );

    if( array_key_exists( $type, $func_map ) )
    {
        $func = '\\user_reg_protocol\\' . $func_map[ $type ];
        return $func( $csv_arr[0] );
    }

    return \generic_protocol\ResponseParser::parse_csv_array( $csv_arr );
}

}

?>
