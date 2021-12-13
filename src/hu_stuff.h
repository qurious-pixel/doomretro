/*
========================================================================

                           D O O M  R e t r o
         The classic, refined DOOM source port. For Windows PC.

========================================================================

  Copyright © 1993-2022 by id Software LLC, a ZeniMax Media company.
  Copyright © 2013-2022 by Brad Harding <mailto:brad@doomretro.com>.

  DOOM Retro is a fork of Chocolate DOOM. For a list of credits, see
  <https://github.com/bradharding/doomretro/wiki/CREDITS>.

  This file is a part of DOOM Retro.

  DOOM Retro is free software: you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the
  Free Software Foundation, either version 3 of the License, or (at your
  option) any later version.

  DOOM Retro is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with DOOM Retro. If not, see <https://www.gnu.org/licenses/>.

  DOOM is a registered trademark of id Software LLC, a ZeniMax Media
  company, in the US and/or other countries, and is used without
  permission. All other trademarks are the property of their respective
  holders. DOOM Retro is in no way affiliated with nor endorsed by
  id Software.

========================================================================
*/

#if !defined(__HU_STUFF_H__)
#define __HU_STUFF_H__

#include "r_defs.h"

//
// Globally visible constants.
//
#define HU_FONTSTART                '!'     // the first font character
#define HU_FONTEND                  '_'     // the last font character

// Calculate # of characters in font.
#define HU_FONTSIZE                 (HU_FONTEND - HU_FONTSTART + 1)

#define HU_MSGX                     3
#define HU_MSGY                     2
#define HU_MSGHEIGHT                1       // in lines

#define HU_MSGTIMEOUT               (4 * TICRATE)

#define HUD_HEALTH_X                55
#define HUD_HEALTH_Y                (SCREENHEIGHT - 28)
#define HUD_HEALTH_MIN              10
#define HUD_HEALTH_WAIT             250
#define HUD_HEALTH_HIGHLIGHT_WAIT   250

#define HUD_ARMOR_X                 124
#define HUD_ARMOR_Y                 HUD_HEALTH_Y
#define HUD_ARMOR_HIGHLIGHT_WAIT    250

#define HUD_KEYS_X                  (SCREENWIDTH - 88)
#define HUD_KEYS_Y                  HUD_HEALTH_Y

#define HUD_AMMO_X                  (SCREENWIDTH - 51)
#define HUD_AMMO_Y                  HUD_HEALTH_Y
#define HUD_AMMO_MIN                10
#define HUD_AMMO_WAIT               250
#define HUD_AMMO_HIGHLIGHT_WAIT     250

#define HUD_KEY_WAIT                250

#define ALTHUD_LEFT_X               56
#define ALTHUD_RIGHT_X              (SCREENWIDTH - 179)
#define ALTHUD_Y                    (SCREENHEIGHT - 37)

//
// HEADS UP TEXT
//
void HU_Init(void);
void HU_SetTranslucency(void);
void HU_Start(void);

void HU_Ticker(void);
void HU_Drawer(void);
void HU_Erase(void);

void HU_SetPlayerMessage(char *message, dboolean group, dboolean external);
void HU_PlayerMessage(char *message, dboolean group, dboolean external);

void HU_ClearMessages(void);
void HU_DrawDisk(void);

extern patch_t  *hu_font[HU_FONTSIZE];
extern patch_t  *minuspatch;

extern int      healthhighlight;
extern int      ammohighlight;
extern int      armorhighlight;
extern dboolean drawdisk;
extern dboolean idbehold;
extern int      message_counter;
extern dboolean message_dontfuckwithme;
extern dboolean message_fadeon;
extern short    minuspatchwidth;

#endif
