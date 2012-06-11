#include "FeOSMusic.h"

char prev[1024];
int state = SINGLE;

static void onEof(void* context)
{
	if(getPlayLstState()==REPEAT) {
		cur_codec.seek(0);
	}
}

int playFile(const char* name)
{
	if(provideCodec(name)) {
		if(state==REPEAT)
			audioCallbacks.onEof = onEof;
		else
			audioCallbacks.onEof = NULL;
		strcpy(prev, name);
		startStream(name, streamIdx);
		return 1;
	}
	return 0;
}

void shuffle(void)
{
	/*if(strlen(prev)>0) {
		int val, files = (numEnt-lastDir);
		char* file = prev;
		if(files>1) {
			if(files > 2) {
				val = rand() % files;
select:
				if(!strcmp(prev, &list[val+lastDir+1][ENTRY_NAME]))
					goto select;
				strcpy(prev, &list[val+lastDir+1][ENTRY_NAME]);
			}
			playFile(file);
		}
	}
	 */
}

void updatePlayList(void)
{
	switch(state) {
	case SINGLE:
		return;
	case REPEAT:
		return; // handled automatically by onEof callback
	case SHUFFLE:
		if(getStreamState() == STREAM_STOP) {
			shuffle();
		}
		return;
	}
}

int getPlayLstState(void)
{
	return state;
}

void setPlayLstState(int stat)
{
	state = stat;
	if(state==REPEAT)
		audioCallbacks.onEof = onEof;
	else
		audioCallbacks.onEof = NULL;
}