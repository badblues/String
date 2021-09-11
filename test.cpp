#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "string.h"

TEST_CASE("STRING IS WORKING", "[STRING]") {
    String a;
    char qwe[4] = "qwe";
    a.setStr(qwe);

    REQUIRE(a.getSize() == 3);

    a.catStr(qwe);

    REQUIRE(a.getSize() == 6);
}
