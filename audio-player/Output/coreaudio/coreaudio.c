#include "coreaudio.h"

OutputPlugin coreaudio_op =
{
	NULL,
	NULL,
	NULL,
	coreaudio_init,
	coreaudio_about,
	coreaudio_configure,
	coreaudio_get_volume,
	coreaudio_set_volume,
	coreaudio_open,
	coreaudio_write,
	coreaudio_close,
	coreaudio_flush,
	coreaudio_pause,
	coreaudio_free,
	coreaudio_playing,
	coreaudio_get_output_time,
	coreaudio_get_written_time
};

OutputPlugin *get_oplugin_info(void)
{
	coreaudio_op.description = g_strdup_printf(_("CoreAudio %s output plugin"), "1.0");
	return &coreaudio_op;
}
