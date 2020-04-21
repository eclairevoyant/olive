/***

  Olive - Non-Linear Video Editor
  Copyright (C) 2019 Olive Team

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#ifndef VIEWERPANELBASE_H
#define VIEWERPANELBASE_H

#include "panel/pixelsampler/pixelsamplerpanel.h"
#include "panel/timebased/timebased.h"
#include "widget/viewer/viewer.h"

OLIVE_NAMESPACE_ENTER

class ViewerPanelBase : public TimeBasedPanel
{
  Q_OBJECT
public:
  ViewerPanelBase(const QString& object_name, QWidget* parent = nullptr);

  virtual void PlayPause() override;

  virtual void PlayInToOut() override;

  virtual void ShuttleLeft() override;

  virtual void ShuttleStop() override;

  virtual void ShuttleRight() override;

  void ConnectTimeBasedPanel(TimeBasedPanel* panel);

  void DisconnectTimeBasedPanel(TimeBasedPanel* panel);

  VideoRenderBackend* video_renderer() const;

  void ConnectPixelSamplerPanel(PixelSamplerPanel *psp);

  /**
   * @brief Wrapper for ViewerWidget::SetFullScreen()
   */
  void SetFullScreen(QScreen* screen = nullptr);

protected:
  void CreateScopePanel(ScopePanel::Type type);

private:
  int scope_panel_count_;

private slots:
  void ScopePanelClosed();

};

OLIVE_NAMESPACE_EXIT

#endif // VIEWERPANELBASE_H