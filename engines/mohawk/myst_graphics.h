/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef MOHAWK_MYST_GRAPHICS_H
#define MOHAWK_MYST_GRAPHICS_H

#include "mohawk/graphics.h"

#include "common/file.h"

namespace Mohawk {

class MystBitmap;
class MohawkEngine_Myst;

enum RectState {
	kRectEnabled,
	kRectDisabled,
	kRectUnreachable
};

class MystGraphics : public GraphicsManager {
public:
	MystGraphics(MohawkEngine_Myst *vm);
	~MystGraphics();

	void copyImageSectionToScreen(uint16 image, Common::Rect src, Common::Rect dest);
	void copyImageSectionToBackBuffer(uint16 image, Common::Rect src, Common::Rect dest);
	void copyImageToScreen(uint16 image, Common::Rect dest);
	void copyImageToBackBuffer(uint16 image, Common::Rect dest);
	void copyBackBufferToScreen(Common::Rect r);
	void runTransition(TransitionType type, Common::Rect rect, uint16 steps, uint16 delay);
	void drawRect(Common::Rect rect, RectState state);
	void drawLine(const Common::Point &p1, const Common::Point &p2, uint32 color);
	void enableDrawingTimeSimulation(bool enable);
	void fadeToBlack();
	void fadeFromBlack();

	void clearScreenPalette();
	void setBasePalette();
	void setPaletteToScreen();
	const byte *getPalette() const { return _palette; }

protected:
	MohawkSurface *decodeImage(uint16 id);
	MohawkEngine *getVM() { return (MohawkEngine *)_vm; }

private:
	MohawkEngine_Myst *_vm;
	MystBitmap *_bmpDecoder;

	Graphics::Surface *_backBuffer;
	Graphics::PixelFormat _pixelFormat;
	Common::Rect _viewport;
	byte _palette[256 * 3];

	int _enableDrawingTimeSimulation;
	uint32 _nextAllowedDrawTime;
	static const uint _constantDrawDelay = 10; // ms
	static const uint _proportionalDrawDelay = 500; // pixels per ms

	void simulatePreviousDrawDelay(const Common::Rect &dest);
	void transitionDissolve(Common::Rect rect, uint step);
	void transitionSlideToLeft(Common::Rect rect, uint16 steps, uint16 delay);
	void transitionSlideToRight(Common::Rect rect, uint16 steps, uint16 delay);
	void transitionSlideToTop(Common::Rect rect, uint16 steps, uint16 delay);
	void transitionSlideToBottom(Common::Rect rect, uint16 steps, uint16 delay);
	void transitionPartialToRight(Common::Rect rect, uint32 width, uint32 steps);
	void transitionPartialToLeft(Common::Rect rect, uint32 width, uint32 steps);
};

} // End of namespace Mohawk

#endif
