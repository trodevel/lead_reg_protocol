<?php

// $Revision: 12186 $ $Date:: 2019-10-15 #$ $Author: serge $

require_once '../user_reg_protocol.php';
require_once '../response_parser.php';
require_once '../str_helper.php';

{
    $resp  =
    'user_reg/RegisterLeadResponse;';

    $parsed = user_reg_protocol\ResponseParser::parse( $resp );

    echo "parsed RegisterLeadResponse: " . \user_reg_protocol\to_html( $parsed ) . "\n";
}

?>
