#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set_short("林中草地");
	set_long( @C_LONG_DESCRIPTION
你走到了一片草地上，四周都是松林，除了山风吹掠、虫鸣鸟啼外，没
有一点尘俗杂音，阴凉幽静的森林气息深深的迷醉每一颗来自俗世尘嚣的心
，你顿时放下世俗的一切种种牵绊，放开心胸来体会这份难得的自然之美。
当你仔细一看，发现有一块草皮(grass) 颜色似乎和其他草地不同，呈现一
种淡青色，显得十分醒目。
C_LONG_DESCRIPTION
	);
    set("item_desc", ([ "grass" : @C_LONG
你走上前去仔细观察那块草皮，发现它是由许\多十分可爱的青绿色小草缀
成的，咦! 这草一茎七叶、通体细刺，看起来颇像是有用的药草，或许\你
可以挖几株回去向高人请教请教 !
C_LONG
	]));
    set("objects", ([
        "snakea" : "/d/noden/monster/snake",
        "snakeb" : "/d/noden/monster/snake",
    ]) );
    set("herb_left", 2);
        set_outside("eastland");
	set( "exits", ([
         "east" : SAULIN"entrance",
	]) );
	reset();
}

void init()
{
    add_action( "dig_herb", "dig" );
}

int dig_herb(string arg)
{
    if( !arg || arg !="herb" )
		return notify_fail( can_read_chinese() ?
		  "你东挖西挖的累得满身大汗才想起来：你不知道要挖什麽？\n" :
		  "Dig what ?\n" );
	else if( query("herb_left") < 1 ) {
		tell_object(this_player(), can_read_chinese() ?
			"不知是那个缺德鬼把这块草皮上的植物都给挖掉了。\n":
			"There are no herbs here.\n"
		);
		return 1;
	} else {
	if (present("snake",environment(this_player())))
	{
        tell_object(this_player(), 
	"慢著慢著 !! 那些药草正盘著一条蛇，至少要先把它请走吧 !!\n" 
	);
	return 1;
	}
        tell_object(this_player(), @GOT_HERB
你跪下来细心的连土把药草挖出来，在你的手心上，药草更显得青翠，不过
，如果你不把它包好(pack)再赶快种回土里并且浇上一大瓢的水，恐怕它的
绿意会消失的很快。
GOT_HERB
		);
		add("herb_left", -1);
		new( SAULIN_OBJ"herb" )->move(this_player());
		return 1;
	}
}

void reset()
{
	set("herb_left", 2);
	::reset();
}
