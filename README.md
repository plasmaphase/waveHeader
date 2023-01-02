WAV Header Structure
====================

This code defines a C structure for representing the header of a WAV audio file. The header contains information about the format of the audio data, such as the number of channels, sample rate, and bit depth.

The structure contains 12 fields, as described below:
-   `riffStr`: A 4-byte string containing the characters "RIFF", which indicates the file is a RIFF (Resource Interchange File Format) file.
-   `fileSize`: A 4-byte unsigned integer representing the size of the file, minus 8 bytes. This value should be set to the total size of the file minus 8 bytes (the size of the "RIFF" and "WAVE" fields).
-   `format`: A 4-byte string containing the characters "WAVE", which indicates the file is a WAVE (Waveform Audio File Format) file.
-   `fmtHdr`: A 4-byte string containing the characters "fmt ", which indicates the start of the format header chunk.
-   `fmtChunkSize`: A 4-byte unsigned integer representing the size of the "fmt" chunk. This value should be set to the size of the format header chunk, which is 16 bytes for PCM audio.
-   `audio_format`: A 2-byte unsigned integer representing the audio format. A value of 1 indicates PCM (pulse-code modulation).
-   `numChannels`: A 2-byte unsigned integer representing the number of channels in the audio data. The code defines an enum type called channels_t that can be used to specify the number of channels. Possible values are 1 (mono) or 2 (stereo).
-   `sampleRate`: A 4-byte unsigned integer representing the sample rate of the audio data. The code defines an enum type called sampleRate_t that can be used to specify the sample rate. Possible values are 8KHz, 11KHz, 16KHz, 22KHz, 44KHz, 48KHz, 88KHz, 96KHz, 176KHz, 192KHz, 352KHz, or 384KHz.
-   `byteRate`: A 4-byte unsigned integer representing the number of bytes per second in the audio data. It is calculated as numChannels * sampleRate * bitDepth / 8.
-   `blockAlign: A 2-byte unsigned integer representing the number of bytes per sample in the audio data. It is calculated as numChannels * bitDepth / 8.
-   `bitDepth`: A 2-byte unsigned integer representing the bit depth of the audio data. The code defines an enum type called bitDepth_t that can be used to specify the bit depth. Possible values are 8, 16, 24, or 32.
-   `dataHdr`: A 4-byte string containing the characters "data", which indicates the start of the audio data chunk.
-   `data_bytes`: A 4-byte unsigned integer representing the number of bytes in the audio data chunk. It is calculated as the number of samples in the audio data multiplied by the number of channels multiplied by the size of each sample (in bytes).

Configuration Function
----------------------

The code also includes a function called `cfgWave` that can be used to configure the fields of a `wavHdr_t` structure.


This function takes four arguments:
-   `wHdr`: A pointer to a wavHdr_t structure that will be configured.
-   `channels`: The number of channels in the audio data, specified using the channels_t enum type. Possible values are 1 (mono) or 2 (stereo).
-   `sRate`: The sample rate of the audio data, specified using the sampleRate_t enum type. Possible values are 8KHz, 11KHz, 16KHz, 22KHz, 44KHz, 48KHz, 88KHz, 96KHz, 176KHz, 192KHz, 352KHz, or 384KHz.
-   `bDepth`: The bit depth of the audio data, specified using the bitDepth_t enum type. Possible values are 8, 16, 24, or 32.

The function sets the values of the constants in the structure and then configures the variable fields based on the arguments passed in. It also calculates the `byteRate` and `blockAlign` fields based on the other fields.

Example
-------

Here is an example of how you might use the `wavHdr_t` structure and `cfgWave` function in your code:

```
wavHdr_t header;

cfgWave(&header, MONO, SR_44K, BD_16);

header.data_bytes = num_samples * (BD_16 / 8);
header.fileSize = RIFF_HDR_SIZE + FMT_PCM_CHUNK_SIZE + (num_samples * (BD_16 / 8));

```

This code creates a wavHdr_t structure called header, configures it for mono audio with a sample rate of 44KHz and a bit depth of 16 bits, and sets the data_bytes and fileSize fields based on the number of samples in the audio data.