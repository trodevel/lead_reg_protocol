<?php

// $Revision: 12195 $ $Date:: 2019-10-18 #$ $Author: serge $

require_once 'user_reg_protocol.php';
require_once 'response_parser.php';

$session_id = "afafaf";

{
    $req = new \user_reg_protocol\RegisterUserRequest( $session_id, new \user_reg_protocol\User( \user_reg_protocol\gender_e_MALE, "Doe", "John", new \basic_objects\Email( "johndoe@example.com" ), "+49123456789", new \basic_objects\Date( 1978, 7, 6 ) ) );

    echo "req = " . $req->to_generic_request() . "\n";
}

{
    $req = new \user_reg_protocol\ConfirmRegistrationRequest( $session_id, "hjghjgj876jh765hjg765" );

    echo "req = " . $req->to_generic_request() . "\n";
}

?>
