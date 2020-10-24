#include <cxsher.hpp>
int main(int argc, char const *argv[]){
    using namespace std;
    using namespace Cxsher;
    using namespace Cxsher::Debug;
    logger
        .info("This is an info.")
        .warn("This is a warning.")
        .error("This is an error.");
    return 0;
}