#include <iostream>

#include "generic_request/request_parser.h"
#include "generic_request/request_decoder.h"    // decode_request

#include "user_reg_protocol.h"
#include "request_parser.h"
#include "response_gen.h"           // create_RegisterLeadResponse
#include "str_helper.h"             // StrHelper::to_string()
#include "csv_response_encoder.h"   // CsvResponseEncoder::to_csv()


void test( const std::string & str )
{
    std::cout << "REQ = " << str << " - ";

    try
    {
        generic_request::Request grx = generic_request::RequestParser::to_request( str );

        generic_request::Request gr = generic_request::decode_request( grx );

        auto * r = user_reg_protocol::RequestParser::to_forward_message( gr );

        if( r == nullptr )
        {
            throw std::runtime_error( "cannot parse " + str );
        }

        delete r;

        std::cout << "ok\n";
    }
    catch( std::exception & e )
    {
        std::cout << "FAILED - " << e.what() << "\n";
    }
}

void test_RegisterLeadResponse()
{
    auto s = user_reg_protocol::create_RegisterLeadResponse();

    std::cout << user_reg_protocol::CsvResponseEncoder::to_csv( *s ) << std::endl;

    delete s;
}

int main()
{
    test_RegisterLeadResponse();

    std::cout << "\n*********************************\n" << std::endl;

    test( "CMD=user_reg/RegisterLeadRequest&SESSION_ID=af&GENDER=&NAME=&FIRST_NAME=&EMAIL=&PHONE=&BIRTHDAY=" );
    test( "CMD=user_reg/RegisterLeadRequest&SESSION_ID=af&GENDER=0&NAME=&FIRST_NAME=&EMAIL=&PHONE=&BIRTHDAY=" );
    test( "CMD=user_reg/RegisterLeadRequest&SESSION_ID=af&GENDER=1&NAME=&FIRST_NAME=&EMAIL=&PHONE=&BIRTHDAY=" );
    test( "CMD=user_reg/RegisterLeadRequest&SESSION_ID=af&GENDER=2&NAME=&FIRST_NAME=&EMAIL=&PHONE=&BIRTHDAY=" );

    test( "CMD=user_reg/RegisterLeadRequest&SESSION_ID=af&GENDER=2&NAME=aaa&FIRST_NAME=&EMAIL=&PHONE=&BIRTHDAY=" );
    test( "CMD=user_reg/RegisterLeadRequest&SESSION_ID=af&GENDER=2&NAME=&FIRST_NAME=aaa&EMAIL=&PHONE=&BIRTHDAY=" );
    test( "CMD=user_reg/RegisterLeadRequest&SESSION_ID=af&GENDER=2&NAME=aaa&FIRST_NAME=bbb&EMAIL=&PHONE=&BIRTHDAY=" );

    test( "CMD=user_reg/RegisterLeadRequest&SESSION_ID=af&GENDER=2&NAME=aaa&FIRST_NAME=bbb&EMAIL=gjg&PHONE=&BIRTHDAY=" );
    test( "CMD=user_reg/RegisterLeadRequest&SESSION_ID=af&GENDER=2&NAME=aaa&FIRST_NAME=bbb&EMAIL=gjg@hjggh.de&PHONE=&BIRTHDAY=" );
    test( "CMD=user_reg/RegisterLeadRequest&SESSION_ID=af&GENDER=2&NAME=aaa&FIRST_NAME=bbb&EMAIL=gjg@hjggh.de&PHONE=&BIRTHDAY=" );
    test( "CMD=user_reg/RegisterLeadRequest&SESSION_ID=af&GENDER=2&NAME=aaa&FIRST_NAME=bbb&EMAIL=&PHONE=12345&BIRTHDAY=" );
    test( "CMD=user_reg/RegisterLeadRequest&SESSION_ID=af&GENDER=2&NAME=aaa&FIRST_NAME=bbb&EMAIL=&PHONE=12345&BIRTHDAY=" );
    test( "CMD=user_reg/RegisterLeadRequest&SESSION_ID=af&GENDER=2&NAME=aaa&FIRST_NAME=bbb&EMAIL=&PHONE=12345&BIRTHDAY=456789" );

    test( "CMD=user_reg/RegisterLeadRequest&GENDER=1&NAME:X=446f65&FIRST_NAME:X=4a6f686e&PHONE:X=2b3439313233343536373839&EMAIL:X=6a6f686e646f65406578616d706c652e636f6d&BIRTHDAY=19780706&SESSION_ID=afafaf&" );

    return 0;
}
