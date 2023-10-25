# Portable Video Player based on FFmpeg for Windows

**Description:**
A simple and lightweight video player implementation for Windows that is built upon FFmpeg. This player is designed to be minimalistic and easy to understand, with the core code written in C. It directly accesses video and audio rendering devices on specific platforms. On the Win32 platform, it utilizes GDI and Direct3D APIs for video rendering and WaveOut API for audio rendering.

**Features:**
- Smooth playback of various video files.
- Low CPU and memory usage compared to official FFmpeg's ffplay.
- High performance, compatibility, and stability.
- Well-synchronized audio and video playback.

## Test Player (testplayer)

**Description:**
Testplayer is a companion application for fanplayer, the main video player. It provides the following hotkeys for control:

- **Ctrl+1:** Open a file with single video player mode.
- **Ctrl+2:** Open files with repeat video player mode.
- **Ctrl+F:** Step seek forward.
- **Ctrl+B:** Step seek backward.
- **Ctrl+Right:** Increase volume.
- **Ctrl+Left:** Decrease volume.

To adjust the playback position of the video, simply click on the bottom of the progress bar in the video player.
