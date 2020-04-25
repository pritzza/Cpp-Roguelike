#ifndef MAIN_H
#define MAIN_H

extern constexpr int consoleWidth{ 120 };		  // x factor of map
extern constexpr int consoleHeight{ 38 };		  // y factor of map (is 38 to leave line at the bottom of the console for cin and stats)

extern char console[consoleHeight][consoleWidth];				// [y][x]

#endif