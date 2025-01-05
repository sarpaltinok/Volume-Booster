#ifndef WAV_UTILS_H
#define WAV_UTILS_H

#include <stdint.h>
#include <stddef.h>

typedef uint8_t BYTE;
typedef int16_t BYTE2;

// WAV header yapısı
typedef struct
{
    char chunk_id[4];
    uint32_t chunk_size;
    char format[4];
    char subchunk1_id[4];
    uint32_t subchunk1_size;
    uint16_t audio_format;
    uint16_t num_channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bits_per_sample;
    char subchunk2_id[4];
    uint32_t subchunk2_size;
} WAVHeader;

// Fonksiyon prototipleri
int read_wav(const char *filename, WAVHeader *header, BYTE2 **audio_data, size_t *num_samples);
int write_wav(const char *filename, const WAVHeader *header, const BYTE2 *audio_data, size_t num_samples);
void process_audio(BYTE2 *audio_data, size_t num_samples, float factor);

#endif
