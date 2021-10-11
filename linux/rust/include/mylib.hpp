#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

namespace mylib {

extern "C" {

char *get_uname();

void string_free(char *s);

} // extern "C"

} // namespace mylib
