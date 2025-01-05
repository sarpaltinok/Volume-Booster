#include <stdio.h>
#include <stdlib.h>
#include "wav_utils.h"

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Usage: ./volume_booster input.wav output.wav factor\n");
        return 1;
    }

    // Komut satırı argümanlarını al
    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float factor = atof(argv[3]);

    // WAV dosyasını oku
    WAVHeader header;
    BYTE2 *audio_data = NULL;
    size_t num_samples = 0;

    if (read_wav(input_file, &header, &audio_data, &num_samples) != 0)
    {
        printf("Error reading WAV file.\n");
        return 1;
    }

    // Ses verilerini işleme
    process_audio(audio_data, num_samples, factor);

    // İşlenmiş veriyi yeni dosyaya yaz
    if (write_wav(output_file, &header, audio_data, num_samples) != 0)
    {
        printf("Error writing WAV file.\n");
        free(audio_data);
        return 1;
    }

    printf("Volume boosted successfully!\n");

    // Belleği temizle
    free(audio_data);
    return 0;
}
