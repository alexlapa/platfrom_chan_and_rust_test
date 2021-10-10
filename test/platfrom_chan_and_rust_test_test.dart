import 'package:flutter/services.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:platfrom_chan_and_rust_test/platfrom_chan_and_rust_test.dart';

void main() {
  const MethodChannel channel = MethodChannel('platfrom_chan_and_rust_test');

  TestWidgetsFlutterBinding.ensureInitialized();

  setUp(() {
    channel.setMockMethodCallHandler((MethodCall methodCall) async {
      return '42';
    });
  });

  tearDown(() {
    channel.setMockMethodCallHandler(null);
  });

  test('getPlatformVersion', () async {
    expect(await PlatfromChanAndRustTest.platformVersion, '42');
  });
}
