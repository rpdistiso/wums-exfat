#include "ExFATModule.hpp"
#include <exfat.h>

ExFATModule& ExFATModule::getInstance() {
    static ExFATModule instance;
    return instance;
}

bool ExFATModule::mount() {
    if (mounted) return true;
    
    if (fatMount(mountPoint.c_str(), &exfat_interface, 0, 4, 64)) {
        mounted = true;
        return true;
    }
    return false;
}

bool ExFATModule::unmount() {
    if (!mounted) return true;
    
    if (fatUnmount(mountPoint.c_str())) {
        mounted = false;
        return true;
    }
    return false;
}
