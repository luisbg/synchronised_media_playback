project('sync_playback', 'c',
  version : '0.1',
  meson_version : '>= 0.36.0',
  default_options : ['warning_level=1'])

gst_req = '>= 1.0.0'
gst_dep = dependency('gstreamer-1.0', version : gst_req)
gst_net_dep = dependency('gstreamer-net-1.0', version : gst_req)

executable('follower', 'follower.c', dependencies : [gst_dep, gst_net_dep])
executable('leader', 'leader.c', dependencies : [gst_dep, gst_net_dep])
