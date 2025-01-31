#include "ExFATDevoptab.hpp"

devoptab_t ExFATDevoptab::devoptab = {
    .name = "exfat",
    .structSize = 0,
    .open_r = ExFATDevoptab::open_r,
    .close_r = ExFATDevoptab::close_r,
    .write_r = ExFATDevoptab::write_r,
    .read_r = ExFATDevoptab::read_r,
    .seek_r = ExFATDevoptab::seek_r,
    .stat_r = ExFATDevoptab::stat_r
};

devoptab_t* ExFATDevoptab::getDevOptab() {
    return &devoptab;
}
