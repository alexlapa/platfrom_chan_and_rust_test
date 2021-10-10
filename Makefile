run:
	cd rust && cargo build \
	&& cp target/debug/libmylib.so ../assets/libmylib.so
