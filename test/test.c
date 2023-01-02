#include <stdio.h>
#include "wave.h"

int main(int argc, char **argv)
{
    wavHdr_t wHdr;

    cfgWave(&wHdr, MONO, SR_44K, BD_16);

    // Check that the fields have been set correctly
    printf("riffStr: %s\n", wHdr.riffStr);
    printf("fileSize: %u\n", wHdr.fileSize);
    printf("format: %s\n", wHdr.format);
    printf("fmtHdr: %s\n", wHdr.fmtHdr);
    printf("fmtChunkSize: %u\n", wHdr.fmtChunkSize);
    printf("audio_format: %u\n", wHdr.audio_format);
    printf("numChannels: %u\n", wHdr.numChannels);
    printf("sampleRate: %u\n", wHdr.sampleRate);
    printf("byteRate: %u\n", wHdr.byteRate);
    printf("blockAlign: %u\n", wHdr.blockAlign);
    printf("bitDepth: %u\n", wHdr.bitDepth);
    printf("dataHdr: %s\n", wHdr.dataHdr);
    printf("data_bytes: %u\n", wHdr.data_bytes);

    return 0;
}
