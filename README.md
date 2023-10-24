A portable video player based on ffmpeg for windows platform.

It is a simple and light weight player implemention without SDL or other third party library. player core codes are written in C language, KISS and easy to read.

It directly access to video and audio rendering device on specific platforms. on win32 playform, using gdi & direct3d api implements video rendering, using waveout api implements audio rendering.

Currently, this player can smoothly playback many video files, with low cpu and memory usage (compared with ffplay of offical ffmpeg), high performance, compatibility and stability, and the audio/video also synchronized very well.


testplayer
==========
testplayer is a simple test player for fanplayer  
hot-keys for testplayer:  
ctrl+1    - open file with single video player mode 
ctrl+2    - open files with reat video player mode 
ctrl+F    - step seek forward  
ctrl+B    - step seek backward  
ctrl+right- volume up
ctrl+left - volume down

To adjust the play position of the video, we can simply click on the bottom of the progress bar in the video player.

