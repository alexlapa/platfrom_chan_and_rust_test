#ifndef FLUTTER_PLUGIN_PLATFROM_CHAN_AND_RUST_TEST_PLUGIN_H_
#define FLUTTER_PLUGIN_PLATFROM_CHAN_AND_RUST_TEST_PLUGIN_H_

#include <flutter_linux/flutter_linux.h>

G_BEGIN_DECLS

#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __attribute__((visibility("default")))
#else
#define FLUTTER_PLUGIN_EXPORT
#endif

typedef struct _PlatfromChanAndRustTestPlugin PlatfromChanAndRustTestPlugin;
typedef struct {
  GObjectClass parent_class;
} PlatfromChanAndRustTestPluginClass;

FLUTTER_PLUGIN_EXPORT GType platfrom_chan_and_rust_test_plugin_get_type();

FLUTTER_PLUGIN_EXPORT void platfrom_chan_and_rust_test_plugin_register_with_registrar(
    FlPluginRegistrar* registrar);

G_END_DECLS

#endif  // FLUTTER_PLUGIN_PLATFROM_CHAN_AND_RUST_TEST_PLUGIN_H_
