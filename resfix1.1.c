#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv)
{
    if (argc == 1 || argc > 3 || argv[1] == "help" || argv[1] == "HELP")
    {
        printf("\nUsage: sudo ./resfix [MONITOR NAME] [RESOLUTION]\n");
        printf("[MONITOR NAME] --> eg: VGA-<number>/DVI-<number>/HDMI-<number>\n");
        printf("[RESOLUTION] -- > eg: 4k/Full_HD/HD \n");
    }
    else
    {
        printf("\nResFix v1.1 - [Ƶ]Zerone-Technologies\n");
        printf("Tested on Intel HD 4000 & Designed For [16:9] Displays Only(Still) Other Displays will be supported later\n");
        printf("DO AT YOUR OWN RISK !");
        printf("\nPress RETURN for continue and CTRL+Z to stop the program");
        system("read");
        ////TEST SECTION/////
        printf("\n\n%s , %s\n\n", argv[2],argv[1]);
        if(strcmp(argv[2],"4k") == 0)
        {
            printf("\nSelected 4k\n");
            system("sudo xrandr --newmode \"3840x2160_60.00\"  712.75  3840 4160 4576 5312  2160 2163 2168 2237 -hsync +vsync");
	        //system("sudo xrandr --addmode %c \"3840x2160_60.00\"",argv[3]);
            char buf[400];
	        snprintf(buf, sizeof(buf), "sudo xrandr --addmode %s \"3840x2160_60.00\"",argv[1]);
	        system("sudo xrandr --output LVDS-1 --mode \"3840x2160_60.00\"");
	        printf("Program Complete !");
        }
        else if(strcmp(argv[2],"Full_HD") == 0)
        {
            printf("\nSelected 1080p\n");
            system("sudo xrandr --newmode \"1920x1080_60.00\"  173.00  1920 2048 2248 2576  1080 1083 1088 1120 -hsync +vsync");
            char buf[400];
	        snprintf(buf, sizeof(buf), "sudo xrandr --addmode %s \"1920x1080_60.00\"",argv[1]);
	        system("sudo xrandr --output LVDS-1 --mode \"1920x1080_60.00\"");
	        printf("Program Complete !");
        }
        else if(strcmp(argv[2],"HD") == 0)
        {
            printf("\nSelected 720p\n");
            system("sudo xrandr --newmode \"1360x780_60.00\"   86.25  1360 1432 1568 1776  780 783 793 810 -hsync +vsync");
            char buf[400];
	        snprintf(buf, sizeof(buf), "sudo xrandr --addmode %s \"1360x780_60.00\"",argv[1]);
	        system("sudo xrandr --output LVDS-1 --mode \"1360x780_60.00\"");
	        printf("Program Complete !");
        }
        else
        {
            printf("System Error or entered resolution unavailable. see ./resfix help !");
        }
    }
}