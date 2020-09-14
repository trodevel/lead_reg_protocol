// includes
#include "object_initializer.h"
#include "generic_protocol/object_initializer.h"
#include "basic_objects/object_initializer.h"

namespace user_reg_protocol
{

// objects

void initialize( User * res
    , basic_objects::gender_e gender
    , const std::string &  login
    , const std::string &  last_name
    , const std::string &  first_name
    , const basic_objects::Email &  email
    , const std::string &  phone
    , const basic_objects::Date &  birthday
 )
{
    res->gender = gender;
    res->login = login;
    res->last_name = last_name;
    res->first_name = first_name;
    res->email = email;
    res->phone = phone;
    res->birthday = birthday;
}

// base messages

void initialize( Request * res
 )
{
    // no base class
}

void initialize( BackwardMessage * res
 )
{
    // base class
    ::generic_protocol::initialize( static_cast<generic_protocol::BackwardMessage*>( res ) );

}

// messages

void initialize( RegisterUserRequest * res
    , const User &  lead
    , const std::string &  password
 )
{
    // base class
    initialize( static_cast<Request*>( res ) );

    res->lead = lead;
    res->password = password;
}

void initialize( RegisterUserResponse * res
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

}

void initialize( ConfirmRegistrationRequest * res
    , const std::string &  registration_key
 )
{
    // base class
    initialize( static_cast<Request*>( res ) );

    res->registration_key = registration_key;
}

void initialize( ConfirmRegistrationResponse * res
 )
{
    // base class
    initialize( static_cast<BackwardMessage*>( res ) );

}

// messages (constructors)

RegisterUserRequest * create_RegisterUserRequest(
    const User &  lead
    , const std::string &  password
 )
{
    auto * res = new RegisterUserRequest;

    initialize( res, lead, password );

    return res;
}

RegisterUserResponse * create_RegisterUserResponse(
 )
{
    auto * res = new RegisterUserResponse;

    initialize( res );

    return res;
}

ConfirmRegistrationRequest * create_ConfirmRegistrationRequest(
    const std::string &  registration_key
 )
{
    auto * res = new ConfirmRegistrationRequest;

    initialize( res, registration_key );

    return res;
}

ConfirmRegistrationResponse * create_ConfirmRegistrationResponse(
 )
{
    auto * res = new ConfirmRegistrationResponse;

    initialize( res );

    return res;
}

} // namespace user_reg_protocol

