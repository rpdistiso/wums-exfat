#pragma once
#include <sys/iosupport.h>
#include <string>

class ExFATDevoptab {
public:
    static devoptab_t* getDevOptab();
    
private:
    static int open_r(struct _reent *r, void *fileStruct, const char *path, int flags, int mode);
    static int close_r(struct _reent *r, void *fd);
    static ssize_t write_r(struct _reent *r, void *fd, const char *ptr, size_t len);
    static ssize_t read_r(struct _reent *r, void *fd, char *ptr, size_t len);
    static off_t seek_r(struct _reent *r, void *fd, off_t pos, int dir);
    static int stat_r(struct _reent *r, const char *path, struct stat *st);
    
    static devoptab_t devoptab;
};
