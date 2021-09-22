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

    SECTION(" constructors ") {
        String a("Hello", 1, 2);
        REQUIRE(strcmp(a.getStr(), "el") == 0);
        String b(str, 3, 3);
        REQUIRE(strcmp(b.getStr(), "rty") == 0);
    }

    SECTION (" adding word ") {
        str.catStr("qwe");

        REQUIRE(str.getSize() == 9);
        REQUIRE(str.getMaxSize() == 9);
        REQUIRE(strcmp(str.getStr(), "qwertyqwe") == 0);
    }

    SECTION (" resetting str ") {
        str.setStr("");
        REQUIRE(str.getSize() == 0);
        REQUIRE(str.getMaxSize() == 0);
        REQUIRE(strcmp(str.getStr(), "") == 0);

        str.setStr("WORLD", 2, 2);
        REQUIRE(str.getSize() == 2);
        REQUIRE(str.getMaxSize() == 2);
        REQUIRE(strcmp(str.getStr(), "RL") == 0);
    }

    SECTION (" finding substring ") {
        REQUIRE(str.findStr("r") - str.getStr() == 3);
        REQUIRE(str.findStr("a") == nullptr);
        REQUIRE(str.findStr("") == nullptr);
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
        REQUIRE(str1[0] == (int)'q');
        REQUIRE(str1[1] == (int)'w');
        REQUIRE(str2[0] == (int)'w');
        REQUIRE(str2[1] == (int)'e');
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
