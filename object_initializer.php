<?php

namespace user_reg_protocol;


// includes
require_once 'protocol.php';
require_once __DIR__.'/../generic_protocol/object_initializer.php';

// objects

function initialize__User( & $res
    , $gender // basic_objects\gender_e
    , $login // string
    , $last_name // string
    , $first_name // string
    , $email // basic_objects\Email
    , $phone // string
    , $birthday // basic_objects\Date
 )
{
    $res->gender = $gender;
    $res->login = $login;
    $res->last_name = $last_name;
    $res->first_name = $first_name;
    $res->email = $email;
    $res->phone = $phone;
    $res->birthday = $birthday;
}

// base messages

function initialize__Request( & $res
 )
{
    // no base class
}

function initialize__BackwardMessage( & $res
 )
{
    // base class
    \generic_protocol\initialize__BackwardMessage( $res );

}

// messages

function initialize__RegisterUserRequest( & $res
    , $lead // User
    , $password // string
 )
{
    // base class
    initialize__Request( $res );

    $res->lead = $lead;
    $res->password = $password;
}

function initialize__RegisterUserResponse( & $res
 )
{
    // base class
    initialize__BackwardMessage( $res );

}

function initialize__ConfirmRegistrationRequest( & $res
    , $registration_key // string
 )
{
    // base class
    initialize__Request( $res );

    $res->registration_key = $registration_key;
}

function initialize__ConfirmRegistrationResponse( & $res
 )
{
    // base class
    initialize__BackwardMessage( $res );

}

// objects (constructors)

function create__User(
    $gender // basic_objects\gender_e
    , $login // string
    , $last_name // string
    , $first_name // string
    , $email // basic_objects\Email
    , $phone // string
    , $birthday // basic_objects\Date
 )
{
    $res = new User;

    initialize__User( $res, $gender, $login, $last_name, $first_name, $email, $phone, $birthday );

    return $res;
}

// messages (constructors)

function create__RegisterUserRequest(
    $lead // User
    , $password // string
 )
{
    $res = new RegisterUserRequest;

    initialize__RegisterUserRequest( $res, $lead, $password );

    return $res;
}

function create__RegisterUserResponse(
 )
{
    $res = new RegisterUserResponse;

    initialize__RegisterUserResponse( $res );

    return $res;
}

function create__ConfirmRegistrationRequest(
    $registration_key // string
 )
{
    $res = new ConfirmRegistrationRequest;

    initialize__ConfirmRegistrationRequest( $res, $registration_key );

    return $res;
}

function create__ConfirmRegistrationResponse(
 )
{
    $res = new ConfirmRegistrationResponse;

    initialize__ConfirmRegistrationResponse( $res );

    return $res;
}

# namespace_end user_reg_protocol


?>
