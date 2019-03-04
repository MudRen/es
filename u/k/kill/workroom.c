#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        ::create();
      set_short( "凌风的玩具屋" );
        set_long(
             "你所看到的屋子是凌风的玩具屋，这里看起来似乎很乱，大概是\n"
             ""+HIW"波士和创世者"+NOR"经常来捣乱，所以才会...................\n"
             "由于凌风经常不在家，所以这里只有让捣蛋鬼们乱搞了。\n"NOR,
        );
        set( "light",1 );
        set( "exits", ([
    "west" : "u/b/boss/workroom.c",
    "north" : "/d/mage/tower/time.c",
    "healer" : "/d/healer/building/healer_guild.c",
    "knight" : "/d/knight/fortress/knight_guild.c",
    "thief" : "/d/thief/hall/thief_guild.c",
    "mage" : "/d/mage/tower/mage_guild.c",
    "monk" : "/d/monk/guild/monk_guild.c",    
    "scholar" : "/d/scholar/scholar/scholar_guild.c",

        ]) );
}
