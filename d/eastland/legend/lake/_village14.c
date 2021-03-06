// File: /d/eastland/legend/lake/village14.c
// Generated by Roommaker Thu Mar 21 17:29:44 1996

#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("海堤");
	ob->set_long( @LONG_DESCRIPTION
你正走在海堤上，海堤往南、北方向延申。海堤旁种满一排排的防风林，枝干
不硬，细细软软的，像木麻黄一类的植物。东边是一片汪洋的大海，海浪不停地拍
打著坡堤。忽然！一个大浪打在岩礁上，溅起□天的水花，你闪避不及被淋个正著
；海风吹来，远远眺望，几艘渔船正随波载浮载沈；晦暗不明的天空，乌云团簇好
似一只只正在张牙舞爪的野兽。往西边走，可以进入渔村。
LONG_DESCRIPTION
	);

	ob->set( "light", 1 );
	ob->set( "exits", ([ 
		"south" : "/d/eastland/legend/lake/village16", 
		"north" : "/d/eastland/legend/lake/village15", 
		"west" : "/d/eastland/legend/lake/village13" ]) );
	ob->set( "objects", ([ 
		"captain" : "/d/eastland/legend/monster/captain2" ]) );
	ob->reset();
}
