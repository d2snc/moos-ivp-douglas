/**
 *      _____
 *     /  _  \
 *    / _/ \  \
 *   / / \_/   \
 *  /  \_/  _   \  ___  _    ___   ___   ____   ____   ___   _____  _   _
 *  \  / \_/ \  / /  _\| |  | __| / _ \ | ++ \ | ++ \ / _ \ |_   _|| | | |
 *   \ \_/ \_/ /  | |  | |  | ++ | |_| || ++ / | ++_/| |_| |  | |  | +-+ |
 *    \  \_/  /   | |_ | |_ | ++ |  _  || |\ \ | |   |  _  |  | |  | +-+ |
 *     \_____/    \___/|___||___||_| |_||_| \_\|_|   |_| |_|  |_|  |_| |_|
 *             ROBOTICS™ 
 *
 *  File: keyboard_raw_ctrl.h
 *  Auth: Ryan Gariepy
 *
 *  Copyright (c) 2011, Clearpath Robotics, Inc. 
 *  All Rights Reserved
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:

 *     * Redistributions of source code must retain the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *     * Neither the name of Clearpath Robotics, Inc. nor the names of
 *       its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written
 *       permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 * CLEARPATH ROBOTICS, INC. BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * Please send comments, questions, or patches to
 * skynet@clearpathrobotics.com
 *
 */

#ifndef KEYBOARD_CTRL_H
#define KEYBOARD_CTRL_H

class KeyboardRawController {
private:
  enum _special_chars {
    BACKSPACE=0x7f,
    ESCAPE=   0x1b,
    BRACKET=  0x5b,
    /* Arrow keys follow a \x1b\x5b escape sequence: */
    LEFT=     0x44,
    RIGHT=    0x43,
    UP=       0x41,
    DOWN=     0x42
  };
  
  enum _input_states {
    // initial state.  Waiting for 'q', or an escape
    BASE,          
    // an escape char has been received.  Looking for an opening bracket
    HAVE_ESCAPE,   
    // have the escape and bracket.  Now we're looking for the special char
    HAVE_BRACKET   
  }              m_inputState;
  int            m_stdinOrigFlags;
  struct termios m_originalTermios;
  
  double m_fwdRaw;
  double m_turnRaw;
  double m_turnWeight;
  
  long timeMillis();
  void pollStdin();
  
 public:
  KeyboardRawController();
  ~KeyboardRawController();
  
  void spin();
};

#endif // KEYBOARD_CTRL_H

