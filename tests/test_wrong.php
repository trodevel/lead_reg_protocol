<?php

// $Revision: 9878 $ $Date:: 2018-10-18 #$ $Author: serge $

require_once '../lead_reg_protocol.php';
require_once '../response_parser.php';
require_once '../str_helper.php';

{
    $resp  =
    'AddContactPhoneResponse;123;';

    $parsed = lead_reg_protocol\ResponseParser::parse( $resp );

    $str = "";

    if( is_null( $parsed ) )
    {
        $str = "cannot parse object";
    }
    else
    {
        $str = \lead_reg_protocol\to_html( $parsed );
    }

    echo "parsed wrong: " . $str . "\n";
}

?>
