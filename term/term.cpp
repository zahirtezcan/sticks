#include <stdio.h>

enum Color
{
	Black,
	Red,
	Green,
	Yellow,
	Blue,
	Magenta,
	Cyan,
	Gray,
	Reserved,
	Default=9,
	HighMagenta = 65
};

enum Intensity
{
	Normal = 22,
	Bold = 1,
	Faint = 2
};

struct Console 
{
	static void SetStyle(Color foreground, Color background, Intensity intensity)
	{
		int fore = 30 + foreground;
		int back = 40 + background;

		printf("\33[%d;%d;%dm", fore, back, intensity);
	}

	static void SetBlink(bool enabled)
	{
		SetBasicStyle(5, enabled);
	}

	static void SetUnderline(bool enabled)
	{
		SetBasicStyle(4, enabled);
	}

	static void SetCrossed(bool enabled)
	{
		SetBasicStyle(6, enabled);
	}
	
	static void ResetStyle() {
		printf("\33[0m");
	}
private:
	static void SetBasicStyle(int style, bool enabled)
	{
		printf("\33[%dm", style + (enabled ? 0 : 20));
	}
};

int main()
{
	Console::SetStyle(Yellow, Blue, Normal);
	Console::SetBlink(true);
	printf("Hello,");
	Console::SetBlink(false);
	Console::SetUnderline(true);
	Console::SetStyle(Black, Red, Bold);
	printf("World!");
	Console::SetStyle(Default, Default, Faint);
	printf("KAPPA");
	Console::ResetStyle();
}

