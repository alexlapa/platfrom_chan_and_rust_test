
import 'dart:async';

import 'package:flutter/services.dart';

class PlatfromChanAndRustTest {
  static const MethodChannel _channel = MethodChannel('platfrom_chan_and_rust_test');

  static Future<String?> get platformVersion async {
    final String? version = await _channel.invokeMethod('getPlatformVersion');
    return version;
  }
}
