#ifndef APG_USER_REG__OBJECT_INITIALIZER_H
#define APG_USER_REG__OBJECT_INITIALIZER_H

// includes
#include "protocol.h"

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
 );

// base messages

void initialize( Request * res
 );
void initialize( BackwardMessage * res
 );

// messages

void initialize( RegisterUserRequest * res
    , const User &  lead
 );
void initialize( RegisterUserResponse * res
 );
void initialize( ConfirmRegistrationRequest * res
    , const std::string &  registration_key
 );
void initialize( ConfirmRegistrationResponse * res
 );

// messages (constructors)

RegisterUserRequest * create_RegisterUserRequest(
    const User &  lead
 );
RegisterUserResponse * create_RegisterUserResponse(
 );
ConfirmRegistrationRequest * create_ConfirmRegistrationRequest(
    const std::string &  registration_key
 );
ConfirmRegistrationResponse * create_ConfirmRegistrationResponse(
 );

} // namespace user_reg_protocol

#endif // APG_USER_REG__OBJECT_INITIALIZER_H
