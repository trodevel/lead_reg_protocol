#ifndef APG_USER_REG__PROTOCOL_H
#define APG_USER_REG__PROTOCOL_H

// system includes
#include <vector>
#include <map>

// includes
#include "basic_parser/object.h"
#include "generic_protocol/protocol.h"

// includes for used modules
#include "basic_objects/protocol.h"

namespace user_reg_protocol
{

// Object
struct User
{
    basic_objects::gender_e gender    ;
    std::string          login     ;
    std::string          last_name ;
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
struct BackwardMessage: public generic_protocol::BackwardMessage
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
    std::string          password  ; // size constrain: [6, 40]
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

    std::string          registration_key; // size constrain: [1, 256]
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

