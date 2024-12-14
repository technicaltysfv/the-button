#ifndef CHRISTMASMODE_H
#define CHRISTMASMODE_H

#define NUM_SNOWFLAKES 30

#define NUM_COMMANDS 5
static const char *commands[NUM_COMMANDS] = {
	"$MediaPlayer = [Windows.Media.Playback.MediaPlayer, Windows.Media, ContentType = WindowsRuntime]::New()",
	"$MediaPlayer.Source = [Windows.Media.Core.MediaSource]::CreateFromUri('https://ia803101.us.archive.org/0/items/mariahcareyalliwantforchristmasisyou_201912/Mariah%20Carey%20-%20All%20I%20Want%20For%20Christmas%20Is%20You.mp3')",
	"$MediaPlayer.Play()",
	"[Console]::CursorVisible = $false",
	"cls"};

#define PICTURE_WIDTH 55
#define PICTURE_HEIGHT 16
static const char *asciiPicture[PICTURE_HEIGHT] = {
	"                                                       ",
	"                                                       ",
	"                                                       ",
	"                                                       ",
	"                                                       ",
	"                                                       ",
	"                                                       ",
	"                                                       ",
	"                                                       ",
	"                                                       ",
	"      ___ __  __        _      __   ______      _   __ ",
	" /l/l(_  /__)/__)(__/  / ))__//__)/(   /  /l/l /_l (   ",
	"/   I/__/ ( / (   /   (__/  // ( (__) (  /   I(  I__)  ",
	"-----------press button to stop animation--------------",
	"source code and instructions at:                       ",
	"                github.com/technicaltysfv/the-button   "};

struct POSITION
{
	unsigned int x;
	unsigned int y;
};

void StopChristmasMode();
void StartChristmasMode();
void SnowFall();

#endif
