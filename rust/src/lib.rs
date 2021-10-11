use std::{
    ptr, ffi::CString, os::raw::c_char
};

#[no_mangle]
pub extern "C" fn get_uname() -> ptr::NonNull<c_char> {
    let info = uname::uname().unwrap();

    string_into_c_str(format!("{:?}", info))
}

#[no_mangle]
pub unsafe extern "C" fn string_free(s: ptr::NonNull<c_char>) {
    CString::from_raw(s.as_ptr());
}

fn string_into_c_str(string: String) -> ptr::NonNull<c_char> {
    ptr::NonNull::new(CString::new(string).unwrap().into_raw()).unwrap()
}