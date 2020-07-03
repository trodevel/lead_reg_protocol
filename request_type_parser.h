#ifndef APG_USER_REG__REQUEST_TYPE_PARSER_H
#define APG_USER_REG__REQUEST_TYPE_PARSER_H

// includes
#include "enums.h"

namespace user_reg_protocol
{

class RequestTypeParser
{
public:
    static request_type_e   to_request_type( const std::string & s );
};
} // namespace user_reg_protocol

#endif // APG_USER_REG__REQUEST_TYPE_PARSER_H
