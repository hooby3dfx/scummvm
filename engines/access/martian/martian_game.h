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

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef ACCESS_MARTIAN_GAME_H
#define ACCESS_MARTIAN_GAME_H

#include "access/access.h"

namespace Access {

namespace Martian {

class MartianEngine : public AccessEngine {
private:
	bool _skipStart;

	/**
	 * Do the game introduction
	 */
	void doIntroduction();

	/**
	 * Do title sequence
	 */
	void doTitle();

	/**
	 * Do opening sequence
	 */
	void doOpening();

	/**
	 * Setup variables for the game
	 */
	void setupGame();

protected:
	/**
	 * Play the game
	 */
	virtual void playGame();

	virtual void dead(int deathId) {}
public:
	MartianEngine(OSystem *syst, const AccessGameDescription *gameDesc);

	virtual ~MartianEngine();

	void drawHelp();
	virtual void establish(int esatabIndex, int sub) {};
};

} // End of namespace Martian

} // End of namespace Access

#endif /* ACCESS_MARTIAN_GAME_H */
