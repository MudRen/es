#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("私塾");
    set_long(@LONG
这儿是魔族的一般人开的私塾，目的在以教授学问来换取个人的生活补
助。虽然一般人把小孩送到私塾来求学问的风气并不盛，但有钱人家仍希望
自己的子弟能懂得比别人多，好让自己能在别人面前抬得起头，因此便把孩
子往私塾送；「授课」这门职业也因此得以存活下去。
LONG
            );
    set("light",1);
    set("exits",(["west":CITY"sway1"]) );
    set("objects",([
        "teacher":TMOB"teacher",
        "student#4":TMOB"student",
        "student#3":TMOB"student",
        "student#2":TMOB"student1",
        "student#1":TMOB"student1"]) );
    reset();
#include <replace_room.h>
}
