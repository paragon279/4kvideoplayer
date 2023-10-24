#ifndef __FANPLAYER_FFPLAYER_H__
#define __FANPLAYER_FFPLAYER_H__

// include header file
#include "stdefine.h"

#define FANPLAYER_VERSION "v1.9.4"

#ifdef __cplusplus
extern "C" {
#endif

// constant definition
// message
#define MSG_FANPLAYER         (WM_APP + 1)
#define MSG_OPEN_DONE         (('O' << 24) | ('P' << 16) | ('E' << 8) | ('N' << 0))
#define MSG_OPEN_FAILED       (('F' << 24) | ('A' << 16) | ('I' << 8) | ('L' << 0))
#define MSG_PLAY_COMPLETED    (('E' << 24) | ('N' << 16) | ('D' << 8) | (' ' << 0))
#define MSG_TAKE_SNAPSHOT     (('S' << 24) | ('N' << 16) | ('A' << 8) | ('P' << 0))
#define MSG_STREAM_CONNECTED  (('C' << 24) | ('N' << 16) | ('C' << 8) | ('T' << 0))
#define MSG_STREAM_DISCONNECT (('D' << 24) | ('I' << 16) | ('S' << 8) | ('C' << 0))
#define MSG_VIDEO_RESIZED     (('S' << 24) | ('I' << 16) | ('Z' << 8) | ('E' << 0))
#define MSG_D3D_DEVICE_LOST   (('L' << 24) | ('O' << 16) | ('S' << 8) | ('T' << 0))
#define MSG_AV1_CODEC         (('A' << 24) | ('V' << 16) | ('1' << 8) | (' ' << 0))
#define MSG_NOT_4K            (('N' << 24) | ('0' << 16) | ('4' << 8) | ('K' << 0))
#define MSG_GET_FPS           (('F' << 24) | ('P' << 16) | ('S' << 8) | (' ' << 0))

// adev render type
enum {
    ADEV_RENDER_TYPE_WAVEOUT,
    ADEV_RENDER_TYPE_MAX_NUM,
};

// vdev render type
enum {
    VDEV_RENDER_TYPE_GDI,
    VDEV_RENDER_TYPE_D3D,
    VDEV_RENDER_TYPE_MAX_NUM,
};

// render mode
enum {
    VIDEO_MODE_LETTERBOX,
    VIDEO_MODE_STRETCHED,
    VIDEO_MODE_MAX_NUM,
};

// visual effect
enum {
    VISUAL_EFFECT_DISABLE,
    VISUAL_EFFECT_WAVEFORM,
    VISUAL_EFFECT_SPECTRUM,
    VISUAL_EFFECT_MAX_NUM,
};

// seek flags
enum {
    SEEK_STEP_FORWARD = 1,
    SEEK_STEP_BACKWARD,
};

// param
enum {
    //++ public
    // duration & position
    PARAM_MEDIA_DURATION = 0x1000,
    PARAM_MEDIA_POSITION,

    // media detail info
    PARAM_VIDEO_WIDTH,
    PARAM_VIDEO_HEIGHT,

    // video display mode
    PARAM_VIDEO_MODE,

    // audio volume control
    PARAM_AUDIO_VOLUME,
    
    // which video is completed.
    PARAM_WHICH_VIDEO_FISHIED,

    // playback speed control
    PARAM_PLAY_SPEED_VALUE,
    PARAM_PLAY_SPEED_TYPE,

    // visual effect mode
    PARAM_VISUAL_EFFECT,

    // audio/video sync diff
    PARAM_AVSYNC_TIME_DIFF,

    // get player init params
    PARAM_PLAYER_INIT_PARAMS,

    // definition evaluation
    PARAM_DEFINITION_VALUE,

    PARAM_DATARATE_VALUE,
    PARAM_FRAMERATE_VALUE,
    PARAM_OBJECT_DETECT,
    //-- public

    //++ for adev
    PARAM_ADEV_GET_CONTEXT = 0x2000,
    //-- for adev

    //++ for vdev
    PARAM_VDEV_GET_CONTEXT = 0x3000,
    PARAM_VDEV_POST_SURFACE,
    PARAM_VDEV_GET_D3DDEV,
    PARAM_VDEV_D3D_ROTATE,
    PARAM_VDEV_GET_OVERLAY_HDC,
    PARAM_VDEV_SET_OVERLAY_RECT,
    PARAM_VDEV_GET_VRECT,
    PARAM_VDEV_SET_BBOX,
    //-- for vdev

    //++ for render
    PARAM_RENDER_GET_CONTEXT = 0x4000,
    PARAM_RENDER_STEPFORWARD,
    PARAM_RENDER_VDEV_WIN,
    PARAM_RENDER_SOURCE_RECT,
    //-- for render

    //++ for ffrdp
    PARAM_FFRDP_SENDDATA = 0x5000,
    //-- for ffrdp
};

enum {
    AVSYNC_MODE_AUTO, // automatic
    AVSYNC_MODE_FILE, // file playback mode
    AVSYNC_MODE_LIVE_SYNC0, // live mode, give up audio and video synchronization
    AVSYNC_MODE_LIVE_SYNC1, // Live mode, do audio and video synchronization
};

// Initialization parameter description
// PLAYER_INIT_PARAMS is the initialization parameter of the player, which is passed in when player_open, and some parameter information after the video file is opened can be obtained
// The player_open function will only read the content of the passed in initialization parameter, but will not change its content. Want to get the new parameter value after the video file is opened
// Need to pass player_getparam(PARAM_PLAYER_INIT_PARAMS, &params); such an interface
// In the structure, r indicates that the parameter is read-only, w indicates that the parameter is write-only, and wr indicates that the parameter is configurable, but whether the configuration is successful can be read and judged after player_open
// Note: v1.9.3 and later versions only support asynchronous open mode. After calling player_open, after receiving MSG_OPEN_DONE message, call
// Other interface functions can be executed correctly.
typedef struct {
    int video_vwidth; // wr video actual width
    int video_vheight; // wr video actual height
    int video_owidth; // r video output width (after rotate)
    int video_oheight; // r video output height (after rotate)
    int video_frame_rate; // wr video frame rate
    int video_stream_total; // r Total number of video streams
    int video_stream_cur; // wr current video stream
    int video_thread_count; // wr video decoding thread count
    int video_hwaccel; // wr video hard decoding enable
    int video_deinterlace; // wr enable video deinterlace
    int video_rotate; // wr video rotation angle
    int video_codecid; // codecid of wr video decoder
    int video_bufpktn; // wr video pkt buffer number
    int audio_channels; // r the number of audio channels
    int audio_sample_rate; // r audio sample rate
    int audio_stream_total; // r Total number of audio streams
    int audio_stream_cur; // wr current audio stream
    int audio_bufpktn; // wr audio pkt buffer number

    int subtitle_stream_total; // r total number of subtitle streams
    int subtitle_stream_cur; // wr current subtitle stream

    int vdev_render_type; // w vdev type
    int adev_render_type; // w adev type

    int init_timeout; // w Player initialization timeout, unit ms, set when opening network streaming media to prevent stuck
    int open_autoplay; // w The player automatically plays after opening, no need to manually respond to the MSG_OPEN_DONE message to call the player_play interface function
    int auto_reconnect; // w The timeout of automatic reconnection when playing streaming media, in milliseconds
    int rtsp_transport; // w rtsp transport mode, 0 - auto, 1 - udp, 2 - tcp
    int avts_syncmode; // wr audio and video timestamp synchronization mode, 0 - automatic, 1 - file playback mode, 2 - live mode, do audio and video synchronization, 3 - live mode, give up audio and video synchronization
    char filter_string[256]; // w custom video filter string
    char ffrdp_tx_key[32]; // w AES256 encryption key used to send data by ffrdp protocol
    char ffrdp_rx_key[32]; // w aes256 decryption key used by ffrdp protocol to receive data
    int swscale_type; // type of swscale image scaling algorithm used by w ffrender
    int waveout_device_id; // w specifies the ID of the waveout device on the windows platform
} PLAYER_INIT_PARAMS;
// The two parameters video_stream_cur and audio_stream_cur, if set to -1, can disable the corresponding decoding action
// Application scenario: When playing a video, the window retreats to the background, or I just want to listen to the sound, you can set video_stream_cur to -1
// In this way, the player will only decode audio but not video, which can reduce cpu usage
//++ player common variables
typedef struct { // for internal use only
    PLAYER_INIT_PARAMS *init_params;
    int64_t start_time;
    int64_t start_tick;
    int64_t start_pts ;
    int64_t apts;  // current apts
    int64_t vpts;  // current vpts
    int     apktn; // available audio packet number in pktqueue
    int     vpktn; // available video packet number in pktqueue
    void   *winmsg;
} CMNVARS;
//-- player common variables

#ifdef WIN32
typedef struct {
    int srcx, srcy, srcw, srch;
    int dstx, dsty, dstw, dsth;
    #define OVERLAY_COPY_BITBLT 1 // bitblt
    #define OVERLAY_TRANSPARENT 2 // bitblt for transparent color
    #define OVERLAY_CONST_ALPHA 3 // Transparent blending with a fixed alpha value
    #define OVERLAY_PIXEL_ALPHA 4 // Transparent blending pixel by pixel
    int type, alpha, transparent;
} RECTOVERLAY;
#endif

// function declaration
void* player_open      (char *file, void *appdata, PLAYER_INIT_PARAMS *params);
void* playBackwordVideo(char* rearvideo_path, char* frontvideo_path, void* appdata, PLAYER_INIT_PARAMS* params);
void  player_close     (void *hplayer);
void  player_play      (void *hplayer);
void  player_pause     (void *hplayer);
void  player_seek      (void *hplayer, int64_t ms, int type);
void  player_setrect   (void *hplayer, int type, int x, int y, int w, int h); // type: 0 - video rect, 1 - visual effect rect
int   player_snapshot  (void *hplayer, char *file, int w, int h, int waitt);
int   player_record    (void *hplayer, char *file);
void  player_setparam  (void *hplayer, int id, void *param);
void  player_getparam  (void *hplayer, int id, void *param);

// internal helper function
void  player_send_message(void *extra, int32_t msg, void *param);
void  player_load_params (PLAYER_INIT_PARAMS *params, char *str);

// function description
/*
player_open creates a single video player object
     file - file path
     appdata - The win32 platform passes in the window handle
     params - player initialization parameters
     Return value - void* pointer type, pointing to the player object
playBackwordVideo creates a rear video player object
    *rear video and front video must be recorded at the same time. but the end time can be different*
    rearvideo_path - rear video path
    frontvideo_path - front video path
    win - The win32 platform passes in the window handle
    params - player initialization parameters
    Return value - void* pointer type, pointing to the player object

player_close closes the player
     hplayer - Pointer to the player object returned by player_open

player_play start playing
     hplayer - Pointer to the player object returned by player_open

player_pause pause playback
     hplayer - Pointer to the player object returned by player_open

player_seek Jump to the specified position
     hplayer - Pointer to the player object returned by player_open
     ms - the specified position in milliseconds
     type - the specified type, 0 / SEEK_STEP_FORWARD / SEEK_STEP_BACKWARD
     If type is 0, it is a normal seek operation, and ms specifies the seek position, in milliseconds
     If type is SEEK_STEP_FORWARD, it will step forward 10 seconds
     If type is SEEK_STEP_FORWARD, it will step backward 10 seconds

player_serect sets the display area, there are two display areas, video display area and visual effect display area
     hplayer - Pointer to the player object returned by player_open
     type - specifies the area type 0 - video rect, 1 - visual effect rect
     x,y,w,h - specify the display area


player_setparam set parameters
     hplayer - Pointer to the player object returned by player_open
     id - the parameter id
     param - the parameter pointer

player_getparam get parameters
     hplayer - Pointer to the player object returned by player_open
     id - the parameter id
     param - the parameter pointer
  */

  // Dynamic parameter description
  /*
  PARAM_MEDIA_DURATION and PARAM_MEDIA_POSITION
  Used to get the total length and current playback position of the multimedia file (in milliseconds)
  LONGLONG total = 1, pos = 0;
  player_getparam(g_hplayer, PARAM_MEDIA_DURATION, &total);
  player_getparam(g_hplayer, PARAM_MEDIA_POSITION, &pos );

  PARAM_VIDEO_WIDTH and PARAM_VIDEO_HEIGHT
  Used to get the video width and height of the multimedia file (in pixels)
  int vw = 0, vh = 0;
  player_getparam(g_hplayer, PARAM_VIDEO_WIDTH , &vw);
  player_getparam(g_hplayer, PARAM_VIDEO_HEIGHT, &vh);

  PARAM_AUDIO_VOLUME
  Used to set the playback volume, different from the system volume, fanplayer has a software volume control unit from -30dB to +12dB inside
  Volume range: [-182, 73], -182 corresponds to -30dB, 73 corresponds to +12dB
  Special values: 0 for 0dB gain, -255 for mute, +255 for maximum gain
  int volume = -0;
  player_setparam(g_hplayer, PARAM_AUDIO_VOLUME, &volume);

  PARAM_AVSYNC_TIME_DIFF
  Used to set the time synchronization difference between audio and video (in milliseconds)
  int diff = 100;
  player_setparam(g_hplayer, PARAM_AVSYNC_TIME_DIFF, &diff);
  With a setting of 100 the audio will be 100ms faster than the video, with a setting of -100 it will be 100ms slower

  PARAM_PLAYER_INIT_PARAMS
  Used to obtain player initialization parameters, using method:
  PLAYER_INIT_PARAMS params;
  player_getparam(g_hplayer, PARAM_PLAYER_INIT_PARAMS, &params);
  For the meaning of the parameters, please refer to the description of the player initialization parameters

  All parameters can be get, but not all parameters can be set, because some parameters are read-only.
  */

#ifdef __cplusplus
}
#endif

#endif



