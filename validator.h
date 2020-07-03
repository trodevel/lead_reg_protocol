#ifndef APG_USER_REG__VALIDATOR_H
#define APG_USER_REG__VALIDATOR_H

// includes
#include "protocol.h"

namespace user_reg_protocol
{

namespace validator
{

// enums
bool validate( const std::string & prefix, const gender_e r );

// objects
bool validate( const std::string & prefix, const User & r );

// base messages
bool validate( const Request & r );
bool validate( const BackwardMessage & r );

// messages
bool validate( const RegisterUserRequest & r );
bool validate( const RegisterUserResponse & r );
bool validate( const ConfirmRegistrationRequest & r );
bool validate( const ConfirmRegistrationResponse & r );

} // namespace validator

} // namespace user_reg_protocol

#endif // APG_USER_REG__VALIDATOR_H
