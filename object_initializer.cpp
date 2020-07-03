// includes
#include "object_initializer.h"

namespace user_reg_protocol
{

// objects

void initialize( User * res
    , gender_e gender
    , const std::string &  name
    , const std::string &  first_name
    , const basic_objects::Email &  email
    , const std::string &  phone
    , const basic_objects::Date &  birthday
 )
{
    res->gender = gender;
    res->name = name;
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
    // no base class
}

// messages

void initialize( RegisterUserRequest * res
    , const User &  lead
 )
{
    // base class
    initialize( static_cast<Request*>( res ) );

    res->lead = lead;
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
 )
{
    auto * res = new RegisterUserRequest;

    initialize( res, lead );

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

