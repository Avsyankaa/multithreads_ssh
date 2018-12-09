// Copyright 2018 Avsyankaa <Avsyankaa@gmail.com>
#include <multithreads.hpp>
void init() {
  logging::add_file_log("home/travis/build/bmstu-iu8-34-cpp-2018/lab-06-multithreads-Avsyankaa/sample.log");
  logging::core::get()->set_filter
    (
        logging::trivial::severity >= logging::trivial::info
    );
} 

int main() {
	Multithreads m;
	init();
  logging::add_common_attributes();
  src::severity_logger< severity_level > lg;
    m.Make_counting_in_threads(4, lg);
}
