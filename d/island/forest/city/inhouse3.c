#include "../tsunami.h"

//inherit DOORS;
inherit ROOM;

void create()
{
    ::create();
    set_short("偏殿");
    set_long(@LONG
这儿是偏殿，也是砂纱美公主的寝宫。来到此处，只闻满室清香，四处
整理的一尘不染；由於公主年纪不大，所以这儿只有一些普通的陈设；倒是
因为公主颇喜爱看书，因此墙边书架上堆满满都是书。
LONG
             );
    set("exits",([
        "north":CITY"inhouse2"]) );
    set("light",1);
    set("objects",([
        "sasami":TMOB"sasami"]) );
/*    create_door("north","south",([
        "keyword":({"oak door","door"}),
        "status":"closed",
        "name":"Oak door",
        "c_name":"橡木门",
        "c_desc":"一扇厚重结实，刻工精美的橡木门"
        ]) );*/
     reset();
}

