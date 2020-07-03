<?php

namespace user_reg_protocol;


// includes
require_once 'protocol.php';
require_once 'dummy_creator.php';
require_once 'html_helper.php';

# objects

function example_User()
{
    $obj = \user_reg_protocol\create_dummy__User();

    echo "User : HTML : " . \user_reg_protocol\to_html( $obj ) . "<br>\n";
}


# messages

function example_RegisterUserRequest()
{
    $obj = \user_reg_protocol\create_dummy__RegisterUserRequest();

    echo "RegisterUserRequest : HTML : " . \user_reg_protocol\to_html( $obj ) . "<br>\n";
}

function example_RegisterUserResponse()
{
    $obj = \user_reg_protocol\create_dummy__RegisterUserResponse();

    echo "RegisterUserResponse : HTML : " . \user_reg_protocol\to_html( $obj ) . "<br>\n";
}

function example_ConfirmRegistrationRequest()
{
    $obj = \user_reg_protocol\create_dummy__ConfirmRegistrationRequest();

    echo "ConfirmRegistrationRequest : HTML : " . \user_reg_protocol\to_html( $obj ) . "<br>\n";
}

function example_ConfirmRegistrationResponse()
{
    $obj = \user_reg_protocol\create_dummy__ConfirmRegistrationResponse();

    echo "ConfirmRegistrationResponse : HTML : " . \user_reg_protocol\to_html( $obj ) . "<br>\n";
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
