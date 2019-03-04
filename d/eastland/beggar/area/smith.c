#include "/d/eastland/beggar/dony.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "『薪胆村』铁匠铺" );
	set_long(@C_LONG
这是『薪胆村』里唯一的一家铁匠铺, 主人陆阿巧平时最喜欢为别人铸剑了
。你仔细一看, 地上铺满了一层厚厚的细铁屑, 那些铁屑都是打铁时溅落的火花
。铺内有许多火炉和铁□。吓!还有一个大铁槌,还真不是普通人能拿得起来的呢
。
C_LONG
               	);
	set( "light", 1 );
	set( "exits", ([
		"east" : DBEGGAR"north2"
	]) );

	set( "objects", ([
		"fun" : DMONSTER"blackmaster"
	]) );
        set_reset(this_object(),21600);
}
void reset()
{
    set_reset(this_object(),21600);
    ::reset();
}

