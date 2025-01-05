# Volume Booster

A simple C program to boost the volume of WAV files. This program reads an input WAV file, amplifies the audio data by a specified factor, and writes the result to an output WAV file.

## Features
- Supports **16-bit PCM WAV files**.
- Allows user-defined amplification factor.
- Easy-to-use command-line interface.

---

## How to Use

1. **Compile the program**:
   ```bash
   make
2. **Run the program**:
   ```bash
   ./volume_booster input.wav output.wav factor
   
- Replace input.wav with the path to your input WAV file.
- Replace output.wav with the desired name of the output file.
- Replace factor with the amplification factor (e.g., 2.0 to double the volume).   

3. **Example**:
   ```bash
   ./volume_booster input.wav boosted.wav 1.5


## Requirements
- GCC or any C compiler
- Make utility (for Makefile)
- Standard C libraries
  
## Project Structure
- ├── volume_booster.c   # Main program file
- ├── wav_utils.c        # Helper functions to read, process, and write WAV files
- ├── wav_utils.h        # Header file for WAV utility functions
- ├── Makefile           # Build configuration
- ├── input.wav          # Sample input file (you can replace this)
- ├── output.wav         # Processed output file

  
