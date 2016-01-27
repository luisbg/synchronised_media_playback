#include <gst/gst.h>

int main(int argc, char *argv[]) {
  GstElement *playbin;
  GstBus *bus;
  GMainLoop *main_loop;
  GstStateChangeReturn ret;

  /* Initialize GStreamer */
  gst_init (&argc, &argv);

  /* Create the elements */
  playbin = gst_element_factory_make ("playbin", "playbin");

  if (!playbin) {
    g_printerr ("Playbin could be created.\n");
    return -1;
  }

  /* Set the URI to play */
  g_object_set (playbin, "uri",
                "file:///home/luisbg/samples/big_buck_bunny_1080p_h264.mov",
                NULL);

  /* Add a bus watch, so we get notified when a message arrives */
  bus = gst_element_get_bus (playbin);
  // gst_bus_add_watch (bus, (GstBusFunc)handle_message, &data);

  /* Start playing */
  ret = gst_element_set_state (playbin, GST_STATE_PLAYING);
  if (ret == GST_STATE_CHANGE_FAILURE) {
    g_printerr ("Unable to set the pipeline to the playing state.\n");
    gst_object_unref (playbin);
    return -1;
  }

  /* Create a GLib Main Loop and set it to run */
  main_loop = g_main_loop_new (NULL, FALSE);
  g_main_loop_run (main_loop);

  /* Free resources */
  g_main_loop_unref (main_loop);
  gst_object_unref (bus);
  gst_element_set_state (playbin, GST_STATE_NULL);
  gst_object_unref (playbin);
  return 0;
}
