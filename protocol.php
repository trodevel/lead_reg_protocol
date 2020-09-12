<?php

namespace user_reg_protocol;


// includes
require_once __DIR__.'/../basic_parser/object.php';
require_once __DIR__.'/../generic_protocol/protocol.php';

// includes for used modules
require_once __DIR__.'/../basic_objects/protocol.php';

// Object
class User
{
    public $gender              ; // type: basic_objects\gender_e
    public $login               ; // type: string
    public $last_name           ; // type: string
    public $first_name          ; // type: string
    public $email               ; // type: basic_objects\Email
    public $phone               ; // type: string
    public $birthday            ; // type: basic_objects\Date
};

// Base message
class Request extends \basic_parser\Object
{
    function __construct()
    {
    }
};

// Base message
class BackwardMessage extends \generic_protocol\BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }
};

// Message
class RegisterUserRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 2862506222;

    public $lead                ; // type: User
};

// Message
class RegisterUserResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 434652094;
};

// Message
class ConfirmRegistrationRequest extends Request
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3250536916;

    public $registration_key    ; // type: string // size constrain: [1, 256]
};

// Message
class ConfirmRegistrationResponse extends BackwardMessage
{
    function __construct()
    {
        parent::__construct();
    }

    const MESSAGE_ID = 3750738733;
};

# namespace_end user_reg_protocol


?>

