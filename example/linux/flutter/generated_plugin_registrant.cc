//
//  Generated file. Do not edit.
//

// clang-format off

#include "generated_plugin_registrant.h"

#include <platfrom_chan_and_rust_test/platfrom_chan_and_rust_test_plugin.h>

void fl_register_plugins(FlPluginRegistry* registry) {
  g_autoptr(FlPluginRegistrar) platfrom_chan_and_rust_test_registrar =
      fl_plugin_registry_get_registrar_for_plugin(registry, "PlatfromChanAndRustTestPlugin");
  platfrom_chan_and_rust_test_plugin_register_with_registrar(platfrom_chan_and_rust_test_registrar);
}
