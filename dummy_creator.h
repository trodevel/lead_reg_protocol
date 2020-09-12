#ifndef APG_USER_REG__DUMMY_CREATOR_H
#define APG_USER_REG__DUMMY_CREATOR_H

// includes
#include "protocol.h"

namespace user_reg_protocol
{

namespace dummy
{

// enums


// objects

User create__User();

// messages

RegisterUserRequest * create__RegisterUserRequest();
RegisterUserResponse * create__RegisterUserResponse();
ConfirmRegistrationRequest * create__ConfirmRegistrationRequest();
ConfirmRegistrationResponse * create__ConfirmRegistrationResponse();

} // namespace dummy

} // namespace user_reg_protocol

#endif // APG_USER_REG__DUMMY_CREATOR_H
