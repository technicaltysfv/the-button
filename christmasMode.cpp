#include "christmasMode.h"
#include "keyboard.h"

POSITION snowflakes[NUM_SNOWFLAKES];
POSITION cursor;
bool snowInitialized = false;
bool christmasMode = false;

void StopChristmasMode()
{
	christmasMode = false;
}

void MoveCursor(int x, int y)
{
	while (cursor.x != x || cursor.y != y)
	{
		if (cursor.y < y)
		{
			Keyboard.press(KEY_DOWN_ARROW);
			cursor.y++;
		}
		else if (cursor.y > y)
		{
			Keyboard.press(KEY_UP_ARROW);
			cursor.y--;
		}
		else if (cursor.x < x)
		{
			Keyboard.press(KEY_RIGHT_ARROW);
			cursor.x++;
		}
		else if (cursor.x > x)
		{
			Keyboard.press(KEY_LEFT_ARROW);
			cursor.x--;
		}

		delay(1);
		Keyboard.releaseAll();
		delay(1);
	}
}

void ReplaceCharAtCursor(char c)
{
	Keyboard.press(KEY_DELETE);
	delay(1);
	Keyboard.releaseAll();
	delay(2);
	Keyboard.write(c);
	cursor.x++;
}

void InitSnow()
{
	for (int a = 0; a < NUM_SNOWFLAKES; a++)
	{
		snowflakes[a].x = random(PICTURE_WIDTH - 1);
		snowflakes[a].y = random(PICTURE_HEIGHT - 1);
	}
	cursor.x = PICTURE_WIDTH;
	cursor.y = PICTURE_HEIGHT - 1;

	for (int a = 0; a < NUM_SNOWFLAKES; a++)
	{
		MoveCursor(snowflakes[a].x, snowflakes[a].y);
		ReplaceCharAtCursor('.');
	}

	snowInitialized = true;
}

void SnowFall()
{
	if (snowInitialized && christmasMode)
	{

		int id = random(NUM_SNOWFLAKES);

		MoveCursor(snowflakes[id].x, snowflakes[id].y);
		ReplaceCharAtCursor(asciiPicture[snowflakes[id].y + 1][snowflakes[id].x]);

		snowflakes[id].y++;

		if (snowflakes[id].y >= PICTURE_HEIGHT - 3)
			snowflakes[id].y = 1;

		MoveCursor(snowflakes[id].x, snowflakes[id].y);
		ReplaceCharAtCursor('.');
	}
}

void OpenPowershell()
{
	Keyboard.press(KEY_RIGHT_GUI);
	delay(1);
	Keyboard.releaseAll();
	delay(100);
	Keyboard.write("powershell", 10);
	delay(100);
	Keyboard.press(KEY_RETURN);
	delay(1);
	Keyboard.releaseAll();
	delay(100);
}

void RunCommands(char *lines[], int num, bool shift)
{
	for (int a = 0; a < num; a++)
	{
		Keyboard.write(lines[a], strlen(lines[a]));
		delay(100);

		if (shift)
			Keyboard.press(KEY_LEFT_SHIFT);
		Keyboard.press(KEY_RETURN);
		delay(1);
		Keyboard.releaseAll();
		delay(100);
	}
}

void StartChristmasMode()
{
	delay(5000);
	OpenPowershell();
	delay(400);
	RunCommands(commands, NUM_COMMANDS, false);
	RunCommands(asciiPicture, PICTURE_HEIGHT, true);
	InitSnow();
	christmasMode = true;
}
