#ifndef __JITTERDEFS_H__
#define __JITTERDEFS_H__

#define LARGE_NUMBER 1024
#define JITTER_TABLE_SIZE 1024
#define JITTER_MASK (JITTER_TABLE_SIZE-1)

extern int ijitter[JITTER_TABLE_SIZE];
extern float ujitter[JITTER_TABLE_SIZE];
extern float vjitter[JITTER_TABLE_SIZE];

#endif
