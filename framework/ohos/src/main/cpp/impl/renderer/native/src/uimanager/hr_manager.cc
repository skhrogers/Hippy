/*
 *
 * Tencent is pleased to support the open source community by making
 * Hippy available.
 *
 * Copyright (C) 2019 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "renderer/uimanager/hr_manager.h"

namespace hippy {
inline namespace render {
inline namespace native {

HRManager::HRManager(uint32_t instance_id) : instance_id_(instance_id) {
  
}

// void HRManager::InitViewManager(uint32_t root_id) {
//   auto view_manager = std::make_shared<HRViewManager>();
//   AddViewManager(root_id, view_manager);
//   auto virtual_view_manager = std::make_shared<HRVirtualViewManager>();
//   AddVirtualNodeManager(root_id, virtual_view_manager);
// }

std::shared_ptr<HRViewManager> HRManager::GetViewManager(uint32_t root_id) {
  auto it = view_manager_map_.find(root_id);
  if (it == view_manager_map_.end()) {
    auto view_manager = std::make_shared<HRViewManager>(instance_id_, root_id);
    AddViewManager(root_id, view_manager);
    return view_manager;
  }
  return it->second;
}

std::shared_ptr<HRVirtualViewManager> HRManager::GetVirtualNodeManager(uint32_t root_id) {
  auto it = virtual_view_manager_map_.find(root_id);
  if (it == virtual_view_manager_map_.end()) {
    auto virtual_view_manager = std::make_shared<HRVirtualViewManager>();
    AddVirtualNodeManager(root_id, virtual_view_manager);
    return virtual_view_manager;
  }
  return it->second;
}

void HRManager::AddViewManager(uint32_t root_id, std::shared_ptr<HRViewManager> &view_manager) {
  view_manager_map_[root_id] = view_manager;
}

void HRManager::AddVirtualNodeManager(uint32_t root_id, std::shared_ptr<HRVirtualViewManager> &virtual_view_manager) {
  virtual_view_manager_map_[root_id] = virtual_view_manager;
}

} // namespace native
} // namespace render
} // namespace hippy
