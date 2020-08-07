/*
 * Copyright 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <ui/GraphicTypes.h>
#include <ui/Transform.h>

#include "RenderArea.h"

namespace android {

class DisplayDevice;

class DisplayRenderArea : public RenderArea {
public:
    static std::unique_ptr<RenderArea> create(wp<const DisplayDevice>, const Rect& sourceCrop,
                                              ui::Size reqSize, ui::Dataspace,
                                              RotationFlags rotation,
                                              bool allowSecureLayers = true);

    const ui::Transform& getTransform() const override;
    Rect getBounds() const override;
    int getHeight() const override;
    int getWidth() const override;
    bool isSecure() const override;
    sp<const DisplayDevice> getDisplayDevice() const override;
    bool needsFiltering() const override;
    Rect getSourceCrop() const override;

private:
    DisplayRenderArea(sp<const DisplayDevice>, const Rect& sourceCrop, ui::Size reqSize,
                      ui::Dataspace, RotationFlags rotation, bool allowSecureLayers = true);

    const sp<const DisplayDevice> mDisplay;
    const Rect mSourceCrop;
    const ui::Transform mTransform;
};

} // namespace android