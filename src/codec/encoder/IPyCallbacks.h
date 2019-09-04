/**
 * Esri CityEngine SDK Geometry Encoder for Python
 *
 * Copyright 2014-2019 Esri R&D Zurich and VRBN
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "prt/Callbacks.h"

#include <string>
#include <vector>
#include <map>

using FloatMap = std::map<std::string, double>;
using StringMap = std::map<std::string, std::string>;
using BoolMap = std::map<std::string, bool>;

class IPyCallbacks : public prt::Callbacks {
public:

    virtual ~IPyCallbacks() override = default;

    virtual void addGeometry(
        const uint32_t& initialShapeIndex,
        const std::vector<double>& verticesCoord,
        const std::vector<std::vector<uint32_t>>& facesCoord
    ) = 0;

    virtual void addReports(
        const uint32_t& initialShapeIndex,
        const FloatMap& CGAfloatreport,
        const StringMap& CGAstringreport,
        const BoolMap& CGAboolreport
    ) = 0;

    virtual void addIndex(const uint32_t& initialShapeIndex) = 0;

};
