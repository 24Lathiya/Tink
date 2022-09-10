// Copyright 2017 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef TINK_SIGNATURE_PUBLIC_KEY_VERIFY_WRAPPER_H_
#define TINK_SIGNATURE_PUBLIC_KEY_VERIFY_WRAPPER_H_

#include "absl/strings/string_view.h"
#include "tink/primitive_set.h"
#include "tink/primitive_wrapper.h"
#include "tink/public_key_verify.h"
#include "tink/util/status.h"
#include "tink/util/statusor.h"
#include "proto/tink.pb.h"

namespace crypto {
namespace tink {

// Wraps a set of PublicKeyVerify-instances that correspond to a keyset,
// and combines them into a single PublicKeyVerify-primitive,
// that for the actual verification uses the instance that matches the
// signature prefix.
class PublicKeyVerifyWrapper
    : public PrimitiveWrapper<PublicKeyVerify, PublicKeyVerify> {
 public:
  // Returns an PublicKeyVerify-primitive that uses the primary
  // PublicKeyVerify-instance provided in 'public_key_verify_set',
  // which must be non-NULL (and must contain a primary instance).
  crypto::tink::util::StatusOr<std::unique_ptr<PublicKeyVerify>> Wrap(
      std::unique_ptr<PrimitiveSet<PublicKeyVerify>> public_key_verify_set)
      const override;
};

}  // namespace tink
}  // namespace crypto

#endif  // TINK_SIGNATURE_PUBLIC_KEY_VERIFY_WRAPPER_H_
