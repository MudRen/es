// /u/m/mad/parry/head.c

#include <mudlib.h>

inherit OBJECT;

void create()
{
   set_name("head", "奥斯塔的人头");
   set_short("奥斯塔的人头");
	set_long(
"这是一颗奥斯塔的人头。\n"
	);
   set("unit", "颗");
   set("weight", 80);
}
