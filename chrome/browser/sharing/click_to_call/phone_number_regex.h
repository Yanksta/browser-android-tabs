// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_SHARING_CLICK_TO_CALL_PHONE_NUMBER_REGEX_H_
#define CHROME_BROWSER_SHARING_CLICK_TO_CALL_PHONE_NUMBER_REGEX_H_

namespace re2 {
class RE2;
}  // namespace re2

// Phone number regex to use to detect numbers from text selections.
enum class PhoneNumberRegexVariant {
  kSimple = 0,
  kLowConfidenceModified = 1,
};

// Returns an RE2 instance for the given |variant| to detect phone numbers.
const re2::RE2& GetPhoneNumberRegex(PhoneNumberRegexVariant variant);

// Precompile regexes on a best effort task 15 seconds after startup.
void PrecompilePhoneNumberRegexesAsync();

#endif  // CHROME_BROWSER_SHARING_CLICK_TO_CALL_PHONE_NUMBER_REGEX_H_
