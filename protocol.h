#ifndef APG_USER_REG__PROTOCOL_H
#define APG_USER_REG__PROTOCOL_H

// system includes
#include <vector>
#include <map>

// includes
#include "basic_parser/object.h"

// includes for used modules
#include "basic_objects/protocol.h"

namespace user_reg_protocol
{

// Enum
enum class gender_e
{
    UNDEF                = 0,
    MALE                 = 1,
    FEMALE               = 2,
};

// Object
struct User
{
    gender_e             gender    ;
    std::string          name      ;
    std::string          first_name;
    basic_objects::Email email     ;
    std::string          phone     ;
    basic_objects::Date  birthday  ;
};

// Base message
struct Request: public basic_parser::Object
{
};

// Base message
struct BackwardMessage: public basic_parser::Object
{
};

// Message
struct RegisterUserRequest: public Request
{
    enum
    {
        message_id = 2862506222
    };

    User                 lead      ;
};

// Message
struct RegisterUserResponse: public BackwardMessage
{
    enum
    {
        message_id = 434652094
    };
};

// Message
struct ConfirmRegistrationRequest: public Request
{
    enum
    {
        message_id = 3250536916
    };

    std::string          registration_key;
};

// Message
struct ConfirmRegistrationResponse: public BackwardMessage
{
    enum
    {
        message_id = 3750738733
    };
};

} // namespace user_reg_protocol

#endif // APG_USER_REG__PROTOCOL_H

