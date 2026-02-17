#include <jni.h>
#include <unistd.h>
#include <string>
#include "zygisk.hpp"

using zygisk::Api;
using zygisk::AppSpecializeArgs;

class MyModule : public zygisk::ModuleBase {
public:
    void onLoad(Api *api, JNIEnv *env) override {
        this->api = api;
        this->env = env;
    }

    void preAppSpecialize(AppSpecializeArgs *args) override {
        const char *process = env->GetStringUTFChars(args->nice_name, nullptr);
        if (process && std::string(process) == "com.dts.freefireth") {
            api->setOption(zygisk::Option::DLCLOSE_MODULE_LIBRARY);
        }
        env->ReleaseStringUTFChars(args->nice_name, process);
    }

private:
    Api *api;
    JNIEnv *env;
};

REGISTER_ZYGISK_MODULE(MyModule)
