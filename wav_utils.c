#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wav_utils.h"

int read_wav(const char *filename, WAVHeader *header, BYTE2 **audio_data, size_t *num_samples)
{
    FILE *file = fopen(filename, "rb");
    if (!file)
        return 1;

    // WAV başlığını oku
    fread(header, sizeof(WAVHeader), 1, file);

    // Ses verilerini oku
    size_t data_size = header->subchunk2_size;
    *num_samples = data_size / sizeof(BYTE2);
    *audio_data = malloc(data_size);
    if (!*audio_data)
    {
        fclose(file);
        return 1;
    }
    fread(*audio_data, sizeof(BYTE2), *num_samples, file);
    fclose(file);
    return 0;
}

int write_wav(const char *filename, const WAVHeader *header, const BYTE2 *audio_data, size_t num_samples)
{
    FILE *file = fopen(filename, "wb");
    if (!file)
        return 1;

    // WAV başlığını yaz
    fwrite(header, sizeof(WAVHeader), 1, file);

    // Ses verilerini yaz
    fwrite(audio_data, sizeof(BYTE2), num_samples, file);
    fclose(file);
    return 0;
}

void process_audio(BYTE2 *audio_data, size_t num_samples, float factor)
{
    for (size_t i = 0; i < num_samples; i++)
    {
        audio_data[i] *= factor;

        // Taşmayı önle
        if (audio_data[i] > INT16_MAX)
            audio_data[i] = INT16_MAX;
        else if (audio_data[i] < INT16_MIN)
            audio_data[i] = INT16_MIN;
    }
}
