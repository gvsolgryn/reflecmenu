#pragma once

#include <tchar.h>
#include <sys/timeb.h>

/* Seconds to wait for a selection before booting the default option */
#define TIMEOUT_SECONDS       5

/* Constants for limitations on how long INI file pieces can be */
#define MAX_GAME_NAME_LENGTH 63
#define MAX_GAME_LOCATION_LENGTH 511

/* Number of games to display on one screen */
#define GAMES_PER_PAGE 9

typedef struct
{
	char location[MAX_GAME_LOCATION_LENGTH + 1];
	char name[MAX_GAME_NAME_LENGTH + 1];
} launcher_program_t;

class Menu
{
	public:
		Menu(_TCHAR *inifile);
		~Menu(void);

		unsigned int NumberOfEntries() { return num_programs; }
		char *GetEntryName(unsigned int game) { return settings[game].name; }
		char *GetEntryPath(unsigned int game) { return settings[game].location; }

		void Tick();
		void ResetTimeout();
		bool ShouldBootDefault();
	private:
		unsigned int num_programs;
		launcher_program_t *settings;
		struct timeb beginning;
		struct timeb current;

		launcher_program_t *LoadSettings( _TCHAR *ini_file, unsigned int *final_length );
};
