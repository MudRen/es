#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "品质管制部" );
	set_long(
			"这里是巫师创作的品质管制部，所有要开放让玩家接触得到的区\n"
		"域，物品都必须经过品质管制部的审核。将你要申请品质检验的内容\n"
		"( 格式请参照 \"help policy\" )写在这里的留言板上，大巫师们会\n"
		"尽快加以审核并将结果放在这里。在你东边的是中英文翻译室。\n"
	);
	set( "light", 1 );
	set( "exits", ([
		"west"	:	"/d/wiz/wiz_office",
		"east"	:	"/d/wiz/translate"
	]) );

	// Cause the QC-request board to load
	call_other( "/d/wiz/qc_board", "???" );
}
