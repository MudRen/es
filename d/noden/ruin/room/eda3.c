// eda3.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("依达波第亚宫．门厅");
    set_long(@C_LONG
走进依达波第亚宫的门厅里，只见石块与瓦砾散落了一地，目光所及尽是
一片破败萧条的景象。门厅的中央有个平台，上面有块小铜牌 (plate)，似乎
刻著有字。
C_LONG
    );
    set("item_desc", ([
	"plate" : "铜牌上刻著：「海王子．依达波第亚大人」\n"
	]) );
    set("exits", ([ "north" : AREA"eda4" ]) );
    reset();
}

