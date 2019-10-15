<?php

// $Revision: 12181 $ $Date:: 2019-10-15 #$ $Author: serge $

require_once '../user_reg_protocol.php';
require_once '../response_parser.php';
require_once '../str_helper.php';

{
    $resp  =
    'AddContactPhoneResponse;123;';

    $parsed = user_reg_protocol\ResponseParser::parse( $resp );

    $str = "";

    if( is_null( $parsed ) )
    {
        $str = "cannot parse object";
    }
    else
    {
        $str = \user_reg_protocol\to_html( $parsed );
    }

    echo "parsed wrong: " . $str . "\n";
}

?>
