#include <include/ExFATModule.hpp>
#include <include/ExFATDevoptab.hpp>
#include <exfat.h>

ExFATModule& ExFATModule::getInstance() {
    static ExFATModule instance;
    return instance;
}

bool ExFATModule::mount() {
    if (mounted) return true;
    
    int dev = AddDevice(ExFATDevoptab::getDevOptab());
    if (dev == -1) return false;
    
    if (fatMount(mountPoint.c_str(), &exfat_interface, 0, 4, 64)) {
        mounted = true;
        return true;
    }
    
    RemoveDevice(mountPoint.c_str());
    return false;
}

bool ExFATModule::unmount() {
    if (!mounted) return true;
    
    if (fatUnmount(mountPoint.c_str())) {
        if (RemoveDevice(mountPoint.c_str()) != -1) {
            mounted = false;
            return true;
        }
        fatMount(mountPoint.c_str(), &exfat_interface, 0, 4, 64);
    }
    return false;
}
