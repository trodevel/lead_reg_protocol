// includes
#include "dummy_creator.h"
#include "generic_protocol/dummy_creator.h"
#include "basic_parser/dummy_creator.h"
#include "basic_objects/dummy_creator.h"
#include "object_initializer.h"

namespace user_reg_protocol
{

namespace dummy
{

// enums

// objects

User create__User()
{
    User res;

    ::user_reg_protocol::initialize( & res
        , ::basic_objects::dummy::create__gender_e()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__string()
        , ::basic_objects::dummy::create__Email()
        , ::basic_parser::dummy::create__string()
        , ::basic_objects::dummy::create__Date()
        );

    return res;
}

// messages

RegisterUserRequest * create__RegisterUserRequest()
{
    auto res = new RegisterUserRequest;

    ::user_reg_protocol::initialize( res
        , dummy::create__User()
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

RegisterUserResponse * create__RegisterUserResponse()
{
    auto res = new RegisterUserResponse;

    ::user_reg_protocol::initialize( res
        );

    return res;
}

ConfirmRegistrationRequest * create__ConfirmRegistrationRequest()
{
    auto res = new ConfirmRegistrationRequest;

    ::user_reg_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

ConfirmRegistrationResponse * create__ConfirmRegistrationResponse()
{
    auto res = new ConfirmRegistrationResponse;

    ::user_reg_protocol::initialize( res
        );

    return res;
}

} // namespace dummy

} // namespace user_reg_protocol

