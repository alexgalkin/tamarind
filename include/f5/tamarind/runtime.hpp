/**
    Copyright 2019 Red Anchor Trading Co. Ltd.

    Distributed under the Boost Software License, Version 1.0.
    See <http://www.boost.org/LICENSE_1_0.txt>
 */


#pragma once


#include <f5/makham/task.hpp>
#include <f5/tamarind/workflow.hpp>

#include <fost/core>

#include <future>


namespace f5::tamarind {


    /// # Language runtime
    /**
     */
    class runtime {
      public:
        struct impl;

      private:
        std::unique_ptr<impl> pimpl;
        std::promise<int> status_code;

      public:
        runtime();
        ~runtime();

        /// A future that will signify that the scripts have fully completed.
        /// This is intended for use in `main` so the return status can be
        /// returned correctly. This API can be called only once.
        std::future<int> completion();

        /// ## Script loading and starts
        void load(fostlib::fs::path);
    };


}
