# FanPlayer - Portable Video Player for Windows

## Overview

FanPlayer is a lightweight, portable video player designed for the Windows platform. It utilizes the FFmpeg framework as its core, offering a simplified and efficient video playback solution without relying on additional third-party libraries such as SDL. Written primarily in the C language, FanPlayer follows the "Keep It Simple and Stupid" (KISS) principle, making its source code easy to read and comprehend.

## Key Features

- **Efficient Core:** FanPlayer's core code is streamlined for optimal performance. It directly interfaces with video and audio rendering devices on Windows, eliminating unnecessary layers and dependencies. For video rendering, FanPlayer leverages the GDI (Graphics Device Interface) and Direct3D API, while for audio rendering, it utilizes the WaveOut API.

- **High Performance:** FanPlayer excels in terms of performance, offering smooth playback for various video file formats. It distinguishes itself with its lower CPU and memory usage compared to the official FFmpeg-based player, ffplay. This efficient resource management ensures a seamless and responsive user experience.

- **Stability and Compatibility:** FanPlayer is engineered to deliver a stable and highly compatible video playback experience. It is capable of handling a wide range of video formats, enhancing its versatility as a go-to video player.

- **Audio and Video Synchronization:** A hallmark of FanPlayer is its impeccable audio and video synchronization. Viewers can expect perfect alignment between audio and video, ensuring a captivating multimedia experience.

## Test Player: testplayer

Included within the FanPlayer repository is "testplayer," a simple test application for assessing FanPlayer's capabilities. This test player provides a glimpse into the functionality of FanPlayer and serves as a handy tool for evaluating its performance. It includes the following hotkeys for interactive testing:

- **Ctrl+1:** Open a file in single video player mode.
- **Ctrl+2:** Open files in repeat video player mode.
- **Ctrl+F:** Step forward to seek within the video.
- **Ctrl+B:** Step backward to seek within the video.
- **Ctrl+Right:** Increase the volume.
- **Ctrl+Left:** Decrease the volume.

## User-Friendly Video Position Adjustment

To fine-tune the video's play position, FanPlayer offers an intuitive feature. Users can simply click on the bottom of the progress bar in the video player, enabling precise control over where they are in the video.

FanPlayer is your reliable choice for a lightweight, efficient, and high-performance video player on the Windows platform. Enjoy an exceptional video playback experience without the hassle of additional third-party dependencies. Elevate your multimedia journey with FanPlayer today.

*For more information, updates, and support, please visit the FanPlayer repository.*
