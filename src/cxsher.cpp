#include <cxsher.hpp>
#include <uv.h>
int main(int argc, char const *argv[]){
    using namespace std;
    uv_loop_t* loop = new uv_loop_t;
    uv_loop_init(loop);
    
    cout << "Now quitting." << endl;
    uv_run(loop, UV_RUN_DEFAULT);
    uv_loop_close(loop);
    delete loop;
    return 0;
}
