// system includes
#include <map>

// includes
#include "request_type_parser.h"

namespace user_reg_protocol
{

#define TUPLE_VAL_STR(_x_)  _x_,"user_reg/"+std::string(#_x_)

template< typename _U, typename _V >
std::pair<_V,_U> make_inverse_pair( _U first, _V second )
{
    return std::make_pair( second, first );
}

request_type_e RequestTypeParser::to_request_type( const std::string & s )
{
    typedef std::string KeyType;
    typedef request_type_e Type;

    typedef std::map< KeyType, Type > Map;
    static const Map m =
    {
        make_inverse_pair( Type:: TUPLE_VAL_STR( RegisterUserRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( RegisterUserResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( ConfirmRegistrationRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( ConfirmRegistrationResponse ) ),
    };

    auto it = m.find( s );

    if( it == m.end() )
        return request_type_e::UNDEF;

    return it->second;
}
} // namespace user_reg_protocol

