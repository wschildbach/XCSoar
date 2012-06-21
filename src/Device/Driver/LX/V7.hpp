/*
Copyright_License {

  XCSoar Glide Computer - http://www.xcsoar.org/
  Copyright (C) 2000-2012 The XCSoar Project
  A detailed list of copyright holders can be found in the file "AUTHORS".

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
}
*/

#ifndef XCSOAR_DEVICE_DRIVER_LX_V7_HPP
#define XCSOAR_DEVICE_DRIVER_LX_V7_HPP

#include "Device/Port/Port.hpp"
#include "Device/Internal.hpp"

/**
 * Code specific to LXNav varios (e.g. V7).
 *
 * Source: V7 Dataport specification Version 1.98
 */
namespace V7 {
  /**
   * Enable direct link with GPS port.
   */
  static bool
  ModeDirect(Port &port)
  {
    return PortWriteNMEA(port, "PLXV0,CONNECTION,W,DIRECT");
  }

  /**
   * Enable communication with V7.
   */
  static bool
  ModeVSeven(Port &port)
  {
    return PortWriteNMEA(port, "PLXV0,CONNECTION,W,VSEVEN");
  }

  /**
   * Set up the NMEA sentences sent by the V7 vario:
   *
   * - PLXVF at 2 Hz
   * - PLXVS every 5 seconds
   * - LXWP0 every second
   * - LXWP1 disabled (we don't parse it yet)
   * - LXWP2 every 30 seconds
   * - LXWP3 disabled (we don't parse it)
   * - LXWP5 disabled (we don't parse it)
   */
  static bool
  SetupNMEA(Port &port)
  {
    return PortWriteNMEA(port, "PLXV0,NMEARATE,W,2,5,1,0,30,0,0");
  }
}

#endif
