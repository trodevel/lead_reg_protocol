<?php

namespace user_reg_protocol;


// base include
require_once __DIR__.'/../generic_protocol/str_helper.php';
// includes
require_once __DIR__.'/../basic_objects/str_helper.php';
require_once __DIR__.'/../basic_parser/str_helper.php';

// enums

// objects

function to_string__User( & $r )
{
    $res = "";

    $res .= "(";

    $res .= " gender=" . \basic_objects\to_string__gender_e( $r->gender );
    $res .= " login=" . \basic_parser\to_string__string( $r->login );
    $res .= " last_name=" . \basic_parser\to_string__string( $r->last_name );
    $res .= " first_name=" . \basic_parser\to_string__string( $r->first_name );
    $res .= " email=" . \basic_objects\to_string__Email( $r->email );
    $res .= " phone=" . \basic_parser\to_string__string( $r->phone );
    $res .= " birthday=" . \basic_objects\to_string__Date( $r->birthday );

    $res .= ")";

    return $res;
}

// base messages

function to_string__Request( & $r )
{
    $res = "";

    $res .= "(";

    // no base class

    $res .= ")";

    return $res;
}

function to_string__BackwardMessage( & $r )
{
    $res = "";

    $res .= "(";

    // base class
    $res .= \generic_protocol\to_string__BackwardMessage( $r );


    $res .= ")";

    return $res;
}

// messages

function to_string__RegisterUserRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " lead=" . to_string__User( $r->lead );
    $res .= " password=" . \basic_parser\to_string__string( $r->password );

    return $res;
}

function to_string__RegisterUserResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );


    return $res;
}

function to_string__ConfirmRegistrationRequest( & $r )
{
    $res = "";

    // base class
    $res .= to_string__Request( $r );

    $res .= " registration_key=" . \basic_parser\to_string__string( $r->registration_key );

    return $res;
}

function to_string__ConfirmRegistrationResponse( & $r )
{
    $res = "";

    // base class
    $res .= to_string__BackwardMessage( $r );


    return $res;
}

// generic

function to_string( $obj )
{
    $handler_map = array(
        // objects
        'user_reg_protocol\User'         => 'to_string__User',
        // messages
        'user_reg_protocol\RegisterUserRequest'         => 'to_string__RegisterUserRequest',
        'user_reg_protocol\RegisterUserResponse'         => 'to_string__RegisterUserResponse',
        'user_reg_protocol\ConfirmRegistrationRequest'         => 'to_string__ConfirmRegistrationRequest',
        'user_reg_protocol\ConfirmRegistrationResponse'         => 'to_string__ConfirmRegistrationResponse',
    );

    $type = get_class( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\user_reg_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return \generic_protocol\to_string( $obj );
}

// namespace_end user_reg_protocol


?>
