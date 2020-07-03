#include "protocol.h"
#include "str_helper.h"
#include "csv_helper.h"
#include "dummy_creator.h"
#include "validator.h"

#include <iostream>       // std::cout

template <class T>
void validate( const T & o, const std::string & name )
{
    try
    {
        user_reg_protocol::validator::validate( o );
        std::cout << name << " : valid" << std::endl;
    }
    catch( std::exception & e )
    {
        std::cout << name << " : invalid : " << e.what() << std::endl;
    }
}

// enums

void example_gender_e()
{
    auto obj = user_reg_protocol::dummy::create__gender_e();

    std::cout << "gender_e : STR : " << user_reg_protocol::str_helper::to_string( obj ) << std::endl;
}


// objects

void example_User()
{
    auto obj = user_reg_protocol::dummy::create__User();

    std::cout << "User : STR : " << user_reg_protocol::str_helper::to_string( obj ) << std::endl;
}


// messages

void example_RegisterUserRequest()
{
    auto & obj = * user_reg_protocol::dummy::create__RegisterUserRequest();

    std::cout << "RegisterUserRequest : STR : " << user_reg_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "RegisterUserRequest : CSV : " << user_reg_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "RegisterUserRequest" );

    delete & obj;
}

void example_RegisterUserResponse()
{
    auto & obj = * user_reg_protocol::dummy::create__RegisterUserResponse();

    std::cout << "RegisterUserResponse : STR : " << user_reg_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "RegisterUserResponse : CSV : " << user_reg_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "RegisterUserResponse" );

    delete & obj;
}

void example_ConfirmRegistrationRequest()
{
    auto & obj = * user_reg_protocol::dummy::create__ConfirmRegistrationRequest();

    std::cout << "ConfirmRegistrationRequest : STR : " << user_reg_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "ConfirmRegistrationRequest : CSV : " << user_reg_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "ConfirmRegistrationRequest" );

    delete & obj;
}

void example_ConfirmRegistrationResponse()
{
    auto & obj = * user_reg_protocol::dummy::create__ConfirmRegistrationResponse();

    std::cout << "ConfirmRegistrationResponse : STR : " << user_reg_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "ConfirmRegistrationResponse : CSV : " << user_reg_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "ConfirmRegistrationResponse" );

    delete & obj;
}


int main( int argc, char ** argv )
{
    if( argc > 1 )
    {
        std::srand( std::stoi( std::string( argv[1] ) ) );
    }

    // enums

    example_gender_e();

    // objects

    example_User();

    // messages

    example_RegisterUserRequest();
    example_RegisterUserResponse();
    example_ConfirmRegistrationRequest();
    example_ConfirmRegistrationResponse();

    return 0;
}

