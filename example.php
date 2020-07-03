<?php

namespace user_reg_protocol;


// includes
require_once 'protocol.php';
require_once 'dummy_creator.php';
require_once 'str_helper.php';
require_once 'request_encoder.php';

# objects

function example_User()
{
    $obj = \user_reg_protocol\create_dummy__User();

    echo "User : STR : " . \user_reg_protocol\to_string( $obj ) . "\n";
}


# messages

function example_RegisterUserRequest()
{
    $obj = \user_reg_protocol\create_dummy__RegisterUserRequest();

    echo "RegisterUserRequest : STR : " . \user_reg_protocol\to_string( $obj ) . "\n";

    echo "RegisterUserRequest : REQ : " . \user_reg_protocol\to_generic_request( $obj ) . "\n";

}

function example_RegisterUserResponse()
{
    $obj = \user_reg_protocol\create_dummy__RegisterUserResponse();

    echo "RegisterUserResponse : STR : " . \user_reg_protocol\to_string( $obj ) . "\n";

    echo "RegisterUserResponse : REQ : " . \user_reg_protocol\to_generic_request( $obj ) . "\n";

}

function example_ConfirmRegistrationRequest()
{
    $obj = \user_reg_protocol\create_dummy__ConfirmRegistrationRequest();

    echo "ConfirmRegistrationRequest : STR : " . \user_reg_protocol\to_string( $obj ) . "\n";

    echo "ConfirmRegistrationRequest : REQ : " . \user_reg_protocol\to_generic_request( $obj ) . "\n";

}

function example_ConfirmRegistrationResponse()
{
    $obj = \user_reg_protocol\create_dummy__ConfirmRegistrationResponse();

    echo "ConfirmRegistrationResponse : STR : " . \user_reg_protocol\to_string( $obj ) . "\n";

    echo "ConfirmRegistrationResponse : REQ : " . \user_reg_protocol\to_generic_request( $obj ) . "\n";

}


{
    // objects

    example_User();

    // messages

    example_RegisterUserRequest();
    example_RegisterUserResponse();
    example_ConfirmRegistrationRequest();
    example_ConfirmRegistrationResponse();

}

# namespace_end user_reg_protocol


?>
