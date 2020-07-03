<?php

namespace user_reg_protocol;


// includes
require_once __DIR__.'/../basic_parser/dummy_creator.php';
require_once __DIR__.'/../basic_objects/dummy_creator.php';
require_once 'object_initializer.php';

// enums

function create_dummy__gender_e()
{
    $res = gender_e__UNDEF;

    return $res;
}

// objects

function create_dummy__User()
{
    $res = new User;

    initialize__User( $res
        , create_dummy__gender_e()
        , \basic_parser\create_dummy__string()
        , \basic_parser\create_dummy__string()
        , \basic_objects\create_dummy__Email()
        , \basic_parser\create_dummy__string()
        , \basic_objects\create_dummy__Date()
        );
    return $res;
}

// messages

function create_dummy__RegisterUserRequest()
{
    $res = new RegisterUserRequest;

    initialize__RegisterUserRequest( $res
        , create_dummy__User()
        );
    return $res;
}

function create_dummy__RegisterUserResponse()
{
    $res = new RegisterUserResponse;

    initialize__RegisterUserResponse( $res
        );
    return $res;
}

function create_dummy__ConfirmRegistrationRequest()
{
    $res = new ConfirmRegistrationRequest;

    initialize__ConfirmRegistrationRequest( $res
        , \basic_parser\create_dummy__string()
        );
    return $res;
}

function create_dummy__ConfirmRegistrationResponse()
{
    $res = new ConfirmRegistrationResponse;

    initialize__ConfirmRegistrationResponse( $res
        );
    return $res;
}

# namespace_end user_reg_protocol


?>
