#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "中英文翻译室" );
	set_long(
			"由於东方故事同时支援中文与英文两种语言，所以在你的程式中必\n"
		"须同时提供两种语言的讯息。若是你在翻译或是加进你所不熟悉的语言\n"
		"讯息上有困难，可以在这里留言请其它巫师帮忙。往西可以回到品质管\n"
		"制部。\n"
	);
	set( "light", 1 );
	set( "exits", ([
		"west"	:	"/d/wiz/qc-request"
	]) );

	// Cause the trans_board to load
	call_other( "/d/wiz/trans_board", "???" );
}
