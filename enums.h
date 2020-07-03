#ifndef APG_USER_REG__ENUMS_H
#define APG_USER_REG__ENUMS_H

namespace user_reg_protocol
{

enum class request_type_e
{
    UNDEF,
    RegisterUserRequest,
    RegisterUserResponse,
    ConfirmRegistrationRequest,
    ConfirmRegistrationResponse,
};

} // namespace user_reg_protocol

#endif // APG_USER_REG__ENUMS_H
