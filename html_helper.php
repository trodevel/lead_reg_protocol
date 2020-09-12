<?php

namespace user_reg_protocol;


// includes
require_once __DIR__.'/../generic_protocol/html_helper.php';
require_once __DIR__.'/../basic_objects/html_helper.php';
require_once __DIR__.'/../basic_parser/html_helper.php';
require_once 'str_helper.php';

// enums

// objects

function to_html__User( & $r )
{
    $header = array( 'GENDER', 'LOGIN', 'LAST_NAME', 'FIRST_NAME', 'EMAIL', 'PHONE', 'BIRTHDAY' );

    $data = array(
        \basic_objects\to_html__gender_e( $r->gender ),
        \basic_parser\to_html__string( $r->login ),
        \basic_parser\to_html__string( $r->last_name ),
        \basic_parser\to_html__string( $r->first_name ),
        \basic_objects\to_html__Email( $r->email ),
        \basic_parser\to_html__string( $r->phone ),
        \basic_objects\to_html__Date( $r->birthday )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

// base messages

function to_html__Request( & $r )
{
    $header = array(  );

    $data = array(        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__BackwardMessage( & $r )
{
    $header = array( 'generic_protocol::BackwardMessage' );

    $data = array(
        \generic_protocol\to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

// messages

function to_html__RegisterUserRequest( & $r )
{
    $header = array( 'Request', 'LEAD' );

    $data = array(
        to_html__Request( $r ),
        to_html__User( $r->lead )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__RegisterUserResponse( & $r )
{
    $header = array( 'BackwardMessage' );

    $data = array(
        to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ConfirmRegistrationRequest( & $r )
{
    $header = array( 'Request', 'REGISTRATION_KEY' );

    $data = array(
        to_html__Request( $r ),
        \basic_parser\to_html__string( $r->registration_key )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

function to_html__ConfirmRegistrationResponse( & $r )
{
    $header = array( 'BackwardMessage' );

    $data = array(
        to_html__BackwardMessage( $r )
        );

    $res = \basic_parser\to_html_table( $header, $data );

    return $res;
}

// generic

function to_html( $obj )
{
    $handler_map = array(
        // objects
        'user_reg_protocol\User'         => 'to_html__User',
        // messages
        'user_reg_protocol\RegisterUserRequest'         => 'to_html__RegisterUserRequest',
        'user_reg_protocol\RegisterUserResponse'         => 'to_html__RegisterUserResponse',
        'user_reg_protocol\ConfirmRegistrationRequest'         => 'to_html__ConfirmRegistrationRequest',
        'user_reg_protocol\ConfirmRegistrationResponse'         => 'to_html__ConfirmRegistrationResponse',
    );

    $type = get_class( $obj );

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\user_reg_protocol\\' . $handler_map[ $type ];
        return $func( $obj );
    }

    return \generic_protocol\to_html( $obj );
}

# namespace_end user_reg_protocol


?>
