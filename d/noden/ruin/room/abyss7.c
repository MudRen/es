// abyss7.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();

    set_short("冥王行宫");
    set_long(@C_LONG
这里是冥王的行宫，极尽阴森恐怖之能事於一地。你不禁替你自己的前途
担忧起来，因为光看这里的布置，就知道这里的主人是个喜欢送人下地狱的家
伙，看来得赌上你一生的好运，才有离开这里的机会。
C_LONG
    );
    set("light", 1);
    set("objects", (["archfiend" : MOB"archfiend"]) );

    reset();
}
 
