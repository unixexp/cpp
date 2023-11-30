#include "coreaudio.h"
#include <ctype.h>
#include <pthread.h>
#include <math.h>

int coreaudio_playing(void)
{
	return FALSE;
}

int coreaudio_free(void)
{
	return 0;
}

void coreaudio_close(void)
{
	return;
}

void coreaudio_pause(short p) {
	return;
}

void coreaudio_flush(int time)
{
	return;
}

int coreaudio_get_mixer(int **mixer, int card)
{
	return 0;
}

void coreaudio_get_volume(int *l, int *r)
{
	return;
}

void coreaudio_set_volume(int l, int r)
{
	return;
}

void coreaudio_write(void *ptr, int length)
{
	return;
}

int coreaudio_open(AFormat fmt, int rate, int nch)
{
	return 1;
}

int coreaudio_get_output_time(void)
{
	return 0;
}

int coreaudio_get_written_time(void)
{
	return 0;
}