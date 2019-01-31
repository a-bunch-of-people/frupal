#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

const bool a = true;
const bool b = false;

TEST_CASE("Values are computed", "[values]") {
    REQUIRE(a == true);
    REQUIRE(b == false);

    REQUIRE(b == false);
    REQUIRE(a == true);
}
