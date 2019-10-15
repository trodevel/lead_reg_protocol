<?php

/*

Lead/Registration Protocol messages.

Copyright (C) 2018 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 12186 $ $Date:: 2019-10-15 #$ $Author: serge $

namespace user_reg_protocol;

require_once __DIR__.'/../basic_objects/basic_objects.php';         // \basic_objects\TimeWindow, \basic_objects\Weekdays
require_once __DIR__.'/../generic_protocol/generic_protocol.php';

class Request extends \generic_protocol\Request
{
    function __construct( $session_id )
    {
        parent::__construct( $session_id );
    }
}

class Response extends \generic_protocol\BackwardMessage
{
}

const gender_e_UNDEF   = 0;
const gender_e_MALE    = 1;
const gender_e_FEMALE  = 2;

class Lead
{
    public          $gender;            // gender, see gender_e_... constants
    public          $name;              // name
    public          $first_name;        // first name
    public          $email;             // email, see \basic_objects\Email
    public          $phone;             // phone
    public          $birthday;          // birthday, see \basic_objects\Date

    function __construct( $gender, $name, $first_name, $email, $phone, $birthday )
    {
        $this->gender           = $gender;
        $this->name             = $name;
        $this->first_name       = $first_name;
        $this->email            = $email;
        $this->phone            = $phone;
        $this->birthday         = $birthday;
    }

    public function to_generic_request()
    {
        $res = array(
            "GENDER"        => $this->gender,
            "NAME:X"        => str2hex( $this->name ),
            "FIRST_NAME:X"  => str2hex( $this->first_name ),
            "PHONE:X"       => str2hex( $this->phone ) );

        return \generic_protocol\assemble_request( $res ) .
            $this->email->to_generic_request( "EMAIL" ).
            $this->birthday->to_generic_request( "BIRTHDAY" );
    }

};

class RegisterLeadRequest extends Request
{
    public          $lead;           // contact, see Lead

    function __construct( $session_id, $lead )
    {
        parent::__construct( $session_id );

        $this->lead             = $lead;
    }

    public function to_generic_request()
    {
        $res = array(
                "CMD"           => "user_reg/RegisterLeadRequest" );

        return \generic_protocol\assemble_request( $res ) .
            $this->lead->to_generic_request() .
            parent::to_generic_request();
    }
};

class RegisterLeadResponse extends Response
{
};

?>
