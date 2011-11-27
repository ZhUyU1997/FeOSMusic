#ifndef AAC_H
#define AAC_H

#include <feos.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MP4_TRACK_AUDIO 1
/* 
 * MP4 files are handled differently then plain aac files, but
 * info like sample rate are stored in the same decoder structure
 */
FEOS_EXPORT FILE* openFile(char * name);

FEOS_EXPORT int getSampleRate(void);
FEOS_EXPORT int getnChannels(void);
FEOS_EXPORT int seekPercentage(int perc);
FEOS_EXPORT int getPercentage(void);
FEOS_EXPORT void freeDecoder(void);
FEOS_EXPORT int decSamples(int length, unsigned char ** readBuf, short int * destBuf, int *dataLeft);

#endif /* AAC_H */