<?php

namespace user_reg_protocol;


// includes
require_once __DIR__.'/../basic_parser/object.php';

// includes for used modules
require_once __DIR__.'/../basic_objects/protocol.php';

// Enum gender_e
const gender_e__UNDEF                = 0;
const gender_e__MALE                 = 1;
const gender_e__FEMALE               = 2;

// Object
class User
{
    public $gender              ; // type: gender_e
    public $name                ; // type: string
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
class BackwardMessage extends \basic_parser\Object
{
    function __construct()
    {
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

    public $registration_key    ; // type: string
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

