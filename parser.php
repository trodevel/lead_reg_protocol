<?php

namespace user_reg_protocol;


// base include
require_once __DIR__.'/../generic_protocol/parser.php';
// includes
require_once __DIR__.'/../basic_objects/parser.php';
require_once __DIR__.'/../basic_parser/parser.php';

// enums

// objects

function parse__User( & $csv_arr, & $offset )
{
    $res = new User;

    $res->gender = \basic_objects\parse__gender_e( $csv_arr, $offset );
    $res->login = \basic_parser\parse__string( $csv_arr, $offset );
    $res->last_name = \basic_parser\parse__string( $csv_arr, $offset );
    $res->first_name = \basic_parser\parse__string( $csv_arr, $offset );
    $res->email = \basic_objects\parse__Email( $csv_arr, $offset );
    $res->phone = \basic_parser\parse__string( $csv_arr, $offset );
    $res->birthday = \basic_objects\parse__Date( $csv_arr, $offset );

    return $res;
}

// base messages

function parse__Request( & $res, & $csv_arr, & $offset )
{
    // no base class

}

function parse__BackwardMessage( & $res, & $csv_arr, & $offset )
{
    // base class
    \generic_protocol\parse__BackwardMessage( $res, $csv_arr, $offset );


}

// messages

function parse__RegisterUserRequest( & $csv_arr )
{
    $res = new RegisterUserRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->lead = parse__User( $csv_arr, $offset );
    $res->password = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

function parse__RegisterUserResponse( & $csv_arr )
{
    $res = new RegisterUserResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );


    return $res;
}

function parse__ConfirmRegistrationRequest( & $csv_arr )
{
    $res = new ConfirmRegistrationRequest;

    $offset = 1;

    // base class
    parse__Request( $res, $csv_arr, $offset );

    $res->registration_key = \basic_parser\parse__string( $csv_arr, $offset );

    return $res;
}

function parse__ConfirmRegistrationResponse( & $csv_arr )
{
    $res = new ConfirmRegistrationResponse;

    $offset = 1;

    // base class
    parse__BackwardMessage( $res, $csv_arr, $offset );


    return $res;
}

// generic

class Parser extends \generic_protocol\Parser
{

protected static function parse_csv_array( $csv_arr )
{
    if( sizeof( $csv_arr ) < 1 )
        return NULL;

    $handler_map = array(
        // messages
        'user_reg_protocol/RegisterUserRequest'         => 'parse__RegisterUserRequest',
        'user_reg_protocol/RegisterUserResponse'         => 'parse__RegisterUserResponse',
        'user_reg_protocol/ConfirmRegistrationRequest'         => 'parse__ConfirmRegistrationRequest',
        'user_reg_protocol/ConfirmRegistrationResponse'         => 'parse__ConfirmRegistrationResponse',
    );

    $type = $csv_arr[0][0];

    if( array_key_exists( $type, $handler_map ) )
    {
        $func = '\\user_reg_protocol\\' . $handler_map[ $type ];
        return $func( $csv_arr[0] );
    }

    return \generic_protocol\Parser::parse_csv_array( $csv_arr );
}

}

// namespace_end user_reg_protocol


?>
