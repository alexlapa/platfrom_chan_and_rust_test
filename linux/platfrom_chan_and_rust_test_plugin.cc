#include "include/platfrom_chan_and_rust_test/platfrom_chan_and_rust_test_plugin.h"

#include <flutter_linux/flutter_linux.h>
#include <gtk/gtk.h>
#include <sys/utsname.h>
#include <dlfcn.h>
#include <stdexcept>
#include <cstring>
#include <mylib.hpp>

#define PLATFROM_CHAN_AND_RUST_TEST_PLUGIN(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), platfrom_chan_and_rust_test_plugin_get_type(), \
                              PlatfromChanAndRustTestPlugin))

void* dl_handle = nullptr;

struct _PlatfromChanAndRustTestPlugin {
  GObject parent_instance;
};

G_DEFINE_TYPE(PlatfromChanAndRustTestPlugin, platfrom_chan_and_rust_test_plugin, g_object_get_type())

static void platfrom_chan_and_rust_test_plugin_dispose(GObject* object) {
  G_OBJECT_CLASS(platfrom_chan_and_rust_test_plugin_parent_class)->dispose(object);
}

static void platfrom_chan_and_rust_test_plugin_class_init(PlatfromChanAndRustTestPluginClass* klass) {
  G_OBJECT_CLASS(klass)->dispose = platfrom_chan_and_rust_test_plugin_dispose;
}

static void platfrom_chan_and_rust_test_plugin_init(PlatfromChanAndRustTestPlugin* self) { }

// Called when a method call is received from Flutter.
static void platfrom_chan_and_rust_test_plugin_handle_method_call(
    PlatfromChanAndRustTestPlugin* self,
    FlMethodCall* method_call) {
  g_autoptr(FlMethodResponse) response = nullptr;

  const gchar* method = fl_method_call_get_name(method_call);

  if (strcmp(method, "getPlatformVersion") == 0) {

    auto uname = mylib::get_uname();
    g_autofree gchar *data = g_strdup(uname);
    mylib::string_free(uname);

    g_autoptr(FlValue) result = fl_value_new_string(data);
    response = FL_METHOD_RESPONSE(fl_method_success_response_new(result));
  } else {
    response = FL_METHOD_RESPONSE(fl_method_not_implemented_response_new());
  }

  fl_method_call_respond(method_call, response, nullptr);
}

static void method_call_cb(FlMethodChannel* channel, FlMethodCall* method_call,
                           gpointer user_data) {
  PlatfromChanAndRustTestPlugin* plugin = PLATFROM_CHAN_AND_RUST_TEST_PLUGIN(user_data);
  platfrom_chan_and_rust_test_plugin_handle_method_call(plugin, method_call);
}

void platfrom_chan_and_rust_test_plugin_register_with_registrar(FlPluginRegistrar* registrar) {
  PlatfromChanAndRustTestPlugin* plugin = PLATFROM_CHAN_AND_RUST_TEST_PLUGIN(
      g_object_new(platfrom_chan_and_rust_test_plugin_get_type(), nullptr));

  g_autoptr(FlStandardMethodCodec) codec = fl_standard_method_codec_new();
  g_autoptr(FlMethodChannel) channel =
      fl_method_channel_new(fl_plugin_registrar_get_messenger(registrar),
                            "platfrom_chan_and_rust_test",
                            FL_METHOD_CODEC(codec));
  fl_method_channel_set_method_call_handler(channel, method_call_cb,
                                            g_object_ref(plugin),
                                            g_object_unref);

  g_object_unref(plugin);
}
