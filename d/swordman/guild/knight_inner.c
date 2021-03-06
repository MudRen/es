#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
    set_short("Knight Inner room", "骑士厅");
	set_long( @LONG_DESCRIPTION
This is the inner hall of Knight's guild. Where the important meetings
are held. To the east is the guild.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
你现在进入了骑士公会内部的骑士厅，这里是骑士们开会的地方，只有骑士
公会的人才能进来，大厅中央有一本记载骑士战功\的书(book)，往西走可以回到
骑士公会，而北边则是骑士们存放高级装备的储藏室。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"north" : "/d/knight/fortress/knight_storage",
		"south" : "/d/knight/fortress/knight_shop",
		"west" : "/d/knight/fortress/knight_guild" ]) );
	set( "item_func", ([
		"book": "look_book" ]) );
	reset();
}

int look_book()
{
	int ws;

	ws = (int)this_player()->query("war_score");
	if( !ws ) write( "你到目前为止还没有建立任何战功\。\n" );
	else write( "你目前累积的战功\共有 " + ws + " 点。\n" );

	return 1;
}
