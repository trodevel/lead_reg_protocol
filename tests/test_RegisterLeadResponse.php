<?php

// $Revision: 9880 $ $Date:: 2018-10-18 #$ $Author: serge $

require_once '../lead_reg_protocol.php';
require_once '../response_parser.php';
require_once '../str_helper.php';

{
    $resp  =
    'lead_reg/RegisterLeadResponse;';

    $parsed = lead_reg_protocol\ResponseParser::parse( $resp );

    echo "parsed RegisterLeadResponse: " . \lead_reg_protocol\to_html( $parsed ) . "\n";
}

?>
