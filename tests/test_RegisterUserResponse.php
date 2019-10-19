<?php

// $Revision: 12190 $ $Date:: 2019-10-18 #$ $Author: serge $

require_once '../user_reg_protocol.php';
require_once '../response_parser.php';
require_once '../str_helper.php';

{
    $resp  =
    'user_reg/RegisterUserResponse;';

    $parsed = user_reg_protocol\ResponseParser::parse( $resp );

    echo "parsed RegisterUserResponse: " . \user_reg_protocol\to_html( $parsed ) . "\n";
}

?>
