<?php

namespace user_reg_protocol;


// includes
require_once __DIR__.'/../generic_protocol/request_encoder.php';
require_once __DIR__.'/../basic_objects/request_encoder.php';
require_once __DIR__.'/../basic_parser/request_encoder.php';

// enums

// objects

function to_generic_request__User( $prefix, & $r )
{
    $res = "";
    $res .= "&" . \basic_objects\to_generic_request__gender_e( $prefix . ".GENDER", $r->gender );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".LOGIN", $r->login );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".LAST_NAME", $r->last_name );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".FIRST_NAME", $r->first_name );
    $res .= "&" . \basic_objects\to_generic_request__Email( $prefix . ".EMAIL", $r->email );
    $res .= "&" . \basic_parser\to_generic_request__string( $prefix . ".PHONE", $r->phone );
    $res .= "&" . \basic_objects\to_generic_request__Date( $prefix . ".BIRTHDAY", $r->birthday );

    return $res;
}

// base messages

function to_generic_request__Request( & $r )
{
    $res = "";
    // no base class

    return $res;
}

function to_generic_request__BackwardMessage( & $r )
{
    $res = "";
    // base class
    $res .= \generic_protocol\to_generic_request__BackwardMessage( $r );


    return $res;
}

// messages

function to_generic_request__RegisterUserRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "user_reg/RegisterUserRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . to_generic_request__User( "LEAD", $r->lead );
    $res .= "&" . \basic_parser\to_generic_request__string( "PASSWORD", $r->password );

    return $res;
}

function to_generic_request__RegisterUserResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "user_reg/RegisterUserResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );


    return $res;
}

function to_generic_request__ConfirmRegistrationRequest( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "user_reg/ConfirmRegistrationRequest" );

    // base class
    $res .= to_generic_request__Request( $r );

    $res .= "&" . \basic_parser\to_generic_request__string( "REGISTRATION_KEY", $r->registration_key );

    return $res;
}

function to_generic_request__ConfirmRegistrationResponse( & $r )
{
    // name
    $res = \basic_parser\to_generic_request__string( "CMD", "user_reg/ConfirmRegistrationResponse" );

    // base class
    $res .= to_generic_request__BackwardMessage( $r );


    return $res;
}

// generic

function to_generic_request( $obj )
{
    $handler_map = array(
        // messages
        'user_reg_protocol\RegisterUserRequest'         => 'to_generic_request__RegisterUserRequest',
        'user_reg_protocol\RegisterUserResponse'         => 'to_generic_request__RegisterUserResponse',
        'user_reg_protocol\ConfirmRegistrationRequest'         => 'to_generic_request__ConfirmRegistrationRequest',
        'user_reg_protocol\ConfirmRegistrationResponse'         => 'to_generic_request__ConfirmRegistrationResponse',
    );

    $type = get_class( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\user_reg_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return \generic_protocol\to_generic_request( $obj );
}

# namespace_end user_reg_protocol


?>
