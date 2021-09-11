#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "string.h"
#include <string>

TEST_CASE("STRING IS WORKING", "[STRING]") {
    String str("qwerty");

    REQUIRE(str.getSize() == 6);
    REQUIRE(str.getMaxSize() == 6);
    REQUIRE(strcmp(str.getStr(), "qwerty") == 0);

    SECTION (" adding word ") {
        str.catStr("qwe");

        REQUIRE(str.getSize() == 9);
        REQUIRE(str.getMaxSize() == 12);
    }

    SECTION (" resetting str ") {
        str.setStr("");

        REQUIRE(str.getSize() == 0);
        REQUIRE(str.getMaxSize() == 0);
    }

    SECTION (" finding substring ") {
        REQUIRE(str.findStr("r") - str.getStr() == 3);
        REQUIRE(str.findStr("a") == nullptr);
    }

}
