#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "errors.h"
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

TEST_CASE("OPERATORS IS WORKING", "[STRING]") {
    String str1("qwerty");
    String str2("wer");

    SECTION(" addition ") {
        String res = str1 + str2;
        REQUIRE(strcmp(res.getStr(), "qwertywer") == 0);
        res = res + "kek";
        REQUIRE(strcmp(res.getStr(), "qwertywerkek") == 0);
        res = res + "111";
        REQUIRE(strcmp(res.getStr(), "qwertywerkek111") == 0);
    }

    SECTION(" subtraction ") {
        String res = str1 - str2;
        REQUIRE(strcmp(res.getStr(), "qty") == 0);
        res = res - "q";
        REQUIRE(strcmp(res.getStr(), "ty") == 0);
        res = res - "tt";
        REQUIRE(strcmp(res.getStr(), "ty") == 0);
    }

    SECTION (" indexation ") {
        REQUIRE(str1[0] == 6);
        REQUIRE(str1[1] == 6);
        REQUIRE(str2[0] == 3);
        REQUIRE(str2[1] == 3);
    }
}

TEST_CASE("EXCEPTIONS IS WORKING", "[STRING]") {
    String str("qwerty");

    SECTION(" setting nullptr as string ") {
        try {
            String temp(nullptr);
        }
        catch(Error& ex) {
            REQUIRE(strcmp("str is nullptr\n", ex.getMessage()) == 0);
        }
    }
    SECTION(" setting nullptr as const string ") {
        try {
            String temp("");
            REQUIRE(strcmp("", temp.getStr()) == 0);
        }
        catch(Error& ex1) {

        }
    }
}