#ifndef _STAT_H
#define _STAT_H

struct stat {
	long	st_size;
	long	st_blksize;
};

int stat(const char *path, struct stat *buf);
int fstat(int fildes, struct stat *buf);

#endif /* _STAT_H */
