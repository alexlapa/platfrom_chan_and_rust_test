run:
	cd rust && cargo build && \
	cp target/debug/libmylib.a ../linux/rust/lib/libmylib.a && \
	cd ../example && flutter run

