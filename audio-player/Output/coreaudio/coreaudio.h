#ifndef COREAUDIO_H
#define COREAUDIO_H

#include <xmms/plugin.h>

#define COREAUDIO_HW_PARAMS_API
#define COREAUDIO_HW_PARAMS_API

// Put coreaudio headers here

extern OutputPlugin op;

void coreaudio_init(void);
void coreaudio_about(void);
void coreaudio_configure(void);
int coreaudio_get_mixer(int **mixer, int card);
void coreaudio_save_config(void);

void coreaudio_get_volume(int *l, int *r);
void coreaudio_set_volume(int l, int r);

int coreaudio_playing(void);
int coreaudio_free(void);
void coreaudio_write(void *ptr, int length);
void coreaudio_close(void);
void coreaudio_flush(int time);
void coreaudio_pause(short p);
int coreaudio_open(AFormat fmt, int rate, int nch);
int coreaudio_get_output_time(void);
int coreaudio_get_written_time(void);

#endif
