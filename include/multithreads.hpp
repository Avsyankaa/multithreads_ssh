// Copyright 2018 Avsyankaa <Avsyankaa@gmail.com>

#ifndef INCLUDE_MULTITHREADS_HPP_
#define INCLUDE_MULTITHREADS_HPP_

#include <picosha2.h>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <ostream>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/core.hpp>
#include <boost/core/null_deleter.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared_object.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/sources/record_ostream.hpp>
namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;

class Multithreads {
private:
    std::recursive_mutex m;
    std::vector<unsigned char> Fill_vector_by_random();
    bool Is_hash_needable(const std::string& hash);
    void Do_counting();

public:
    void init();
    unsigned threads_number;
    Multithreads() {
        threads_number = std::thread::hardware_concurrency();
    }
    void Make_counting_in_threads(unsigned threads_count);
};


#endif  // INCLUDE_MULTITHREADS_HPP_
