#include <include/ExFATModule.hpp>

WUMS_MODULE_NAME("exfat_support");
WUMS_MODULE_AUTHOR("Blackjay07");
WUMS_MODULE_VERSION("1.0");
WUMS_MODULE_LICENSE("GNU3");

extern "C" int WUMS_Load() {
    return ExFATModule::getInstance().mount() ? 0 : -1;
}

extern "C" int WUMS_Unload() {
    return ExFATModule::getInstance().unmount() ? 0 : -1;
}
