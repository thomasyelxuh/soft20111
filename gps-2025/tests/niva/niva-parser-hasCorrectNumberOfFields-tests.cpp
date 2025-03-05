#include <boost/test/unit_test.hpp>

#include <string>

#include "niva/niva-data_reading.h"
#include "niva/niva-parser.h"

using namespace GPS;
using namespace NIVA;

BOOST_AUTO_TEST_SUITE( HasCorrectNumberOfFields )

BOOST_AUTO_TEST_CASE( CorrectFieldsNEIL )
{
    const DataReading theDataReading = { "NEIL", {"+45.67","-23.24","231.56","19:44:21"} };

    BOOST_CHECK( hasCorrectNumberOfFields(theDataReading) );
}

BOOST_AUTO_TEST_CASE( CorrectFieldsISMA )
{
    const DataReading theDataReading = { "ISMAHANE", {"78o36'45''","N","23o42'56''","W","23.62"} };

    BOOST_CHECK( hasCorrectNumberOfFields(theDataReading) );
}

BOOST_AUTO_TEST_CASE( CorrectFieldsALICIA )
{
    const DataReading theDataReading = { "ALICIA", {"78o36.75'","N","23o42.9333'","W","23.62"} };

    BOOST_CHECK( hasCorrectNumberOfFields(theDataReading) );
}

BOOST_AUTO_TEST_CASE( CorrectFieldsVISHAL )
{
    const DataReading theDataReading = { "VISHAL", {"09:33:21","78o36'45''","N","23o13'56''","E","56.89"} };

    BOOST_CHECK( hasCorrectNumberOfFields(theDataReading) );
}

BOOST_AUTO_TEST_CASE( MissingFields )
{
    const DataReading theDataReading = { "ISMAHANE", {"N","23o42'56''","W"} };

    BOOST_CHECK( ! hasCorrectNumberOfFields(theDataReading) );
}

BOOST_AUTO_TEST_CASE( ExtraFields )
{
    const DataReading theDataReading = { "ISMAHANE", {"78o36'45''","N","23o42'56''","E","23.62","17:43:07","14/08/74"} };

    BOOST_CHECK( ! hasCorrectNumberOfFields(theDataReading) );
}

BOOST_AUTO_TEST_CASE( ZeroFields )
{
    const DataReading theDataReading = { "NEIL", {} };

    BOOST_CHECK( ! hasCorrectNumberOfFields(theDataReading) );
}

BOOST_AUTO_TEST_SUITE_END()
