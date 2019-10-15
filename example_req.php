<?php

// $Revision: 9882 $ $Date:: 2018-10-18 #$ $Author: serge $

require_once 'lead_reg_protocol.php';
require_once 'response_parser.php';

$session_id = "afafaf";

{
    $req = new \lead_reg_protocol\RegisterLeadRequest( $session_id, new \lead_reg_protocol\Lead( \lead_reg_protocol\gender_e_MALE, "Doe", "John", new \basic_objects\Email( "johndoe@example.com" ), "+49123456789", new \basic_objects\Date( 1978, 7, 6 ) ) );

    echo "req = " . $req->to_generic_request() . "\n";
}

?>
