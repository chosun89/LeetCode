#include "buildtree.h"

int main() {
    auto res = split ( "hello,world,null", ',');
    for (auto s : res) cout << s << endl;
}
