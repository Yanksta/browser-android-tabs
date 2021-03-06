// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_UI_GLOBAL_MEDIA_CONTROLS_CAST_MEDIA_SESSION_CONTROLLER_H_
#define CHROME_BROWSER_UI_GLOBAL_MEDIA_CONTROLS_CAST_MEDIA_SESSION_CONTROLLER_H_

#include "base/macros.h"
#include "chrome/common/media_router/mojom/media_controller.mojom.h"
#include "mojo/public/cpp/bindings/remote.h"
#include "services/media_session/public/mojom/media_session.mojom.h"

namespace base {
class TimeDelta;
}  // namespace base

// Forwards media action commands to media_router::mojom::MediaController.
class CastMediaSessionController {
 public:
  CastMediaSessionController(
      mojo::Remote<media_router::mojom::MediaController> route_controller);
  CastMediaSessionController(const CastMediaSessionController&) = delete;
  CastMediaSessionController& operator=(const CastMediaSessionController&) =
      delete;
  virtual ~CastMediaSessionController();

  // Forwards |action| to the MediaController. No-ops if OnMediaStatusUpdated()
  // has not been called.
  virtual void Send(media_session::mojom::MediaSessionAction action);

  virtual void OnMediaStatusUpdated(
      media_router::mojom::MediaStatusPtr media_status);

  void FlushForTesting();

 private:
  base::TimeDelta PutWithinBounds(const base::TimeDelta& time);

  mojo::Remote<media_router::mojom::MediaController> route_controller_;
  media_router::mojom::MediaStatusPtr media_status_;
};

#endif  // CHROME_BROWSER_UI_GLOBAL_MEDIA_CONTROLS_CAST_MEDIA_SESSION_CONTROLLER_H_
