#include <stdio.h>
#include <errno.h>
#include <ansi_private.h>

#include "stat.h"


int stat(const char *path, struct stat *st)
{
	char buf[FILENAME_MAX];
	FileParam pb;
	
	pb.ioNamePtr = __c2p(path, buf);
	pb.ioVRefNum = 0;
	pb.ioFVersNum = 0;
	pb.ioFDirIndex = 0;
	
	if (PBGetFInfoSync(&pb) != noErr) {
		errno = ENOENT;
		return -1;
	}
	
	st->st_size = pb.ioFlLgLen;
	st->st_blksize = 512;
	
	return 0;
}


int fstat(int fildes, struct stat *st)
{
	IOParam pb;
	
	pb.ioRefNum = __file[fildes].refnum;
	
	if (PBGetEOFSync(&pb) != noErr) {
		errno = ENOENT;
		return -1;
	}
	
	st->st_size = (long)pb.ioMisc;
	st->st_blksize = 512;

	return 0;
}
