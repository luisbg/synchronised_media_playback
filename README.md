# Synchronised Media Playback

This is the sample code that goes along the FOSDEM talk:
**Syncronised multi-device media playback with GStreamer**

https://fosdem.org/2016/schedule/event/synchronised_gstreamer/

## To run:
* in both leader.c and follower.c
 * edit lines g_object_set (playbin, "uri", ...) to point to an existing media file
* sh compile
* ./leader
* ./follower
* as many followers as you would like
