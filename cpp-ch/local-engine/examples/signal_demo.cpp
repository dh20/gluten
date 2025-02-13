/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <base/sleep.h>
#include <Common/GlutenSignalHandler.h>
#include <Common/Logger.h>
#include <Common/logger_useful.h>
#include <IO/WriteBufferFromFileDescriptorDiscardOnFailure.h>
#include <IO/WriteHelpers.h>


using namespace DB;
using namespace local_engine;


int main(int  /*argc*/, char * /*argv*/[])
{
    local_engine::Logger::initConsoleLogger("trace");
    Poco::Logger * logger = &Poco::Logger::get("signal_demo");
    SignalHandler::instance().init();

    for (int j = 0; j < 10 ; j++) {
        LOG_TRACE(logger, "counter {}", j);

        if( j ){
            int *x = nullptr;
            *x = 1;
        }
        sleepForSeconds(3);
    }

    LOG_TRACE(logger, "byb bye!");
    return 0;
}
