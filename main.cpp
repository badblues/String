#include <iostream>
#include <cstdio>

int main(int argc, char** argv) {
    unsigned int a;
//    int a;
//    long b;
//    long long c;
//    short d;
//    unsigned e;
//    long unsigned q;
//    long long unsigned w;
//    short unsigned r;
//    sscanf("1123123412341234213421341221431234", "%d", &a);
//    sscanf("11231234123412342123412421341431234", "%ld", &b);
//    sscanf("1123123412341234214312342134213421341234121234", "%lld", &c);
//    sscanf("1123123412341234214312121235134512455125234", "%hd", &d);
//    printf("%d\n", a);
//    printf("%ld\n", b);
//    printf("%lld\n", c);
//    printf("%hd\n", d);
    sscanf("0x123", "%o", &a);
    printf("%o\n", a);
    return 0;
}