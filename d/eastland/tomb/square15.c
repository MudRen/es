#include <almuhara.h>

inherit ROOM;

int gua;

void create()
{
	::create();
	set_short("地下广场");
	set_long( 
@C_LONG_DESCRIPTION
这□是一个巨大的广场，令你有豁然开朗的感觉。实在无法想像当年的工匠们是如何在
地底下建立如此大的广场，你不禁对那些工匠起了分敬意。广场边有一根浑圆发亮的大石柱
，上面贴了一张咒符(charm)。从符□上发出了浅紫色的光芒，映的周围一片紫色。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : TOMB"/square14", 
		"east" : TOMB"/square16",  ]) );
	add( "c_item_desc", ([
		"charm" :@AMULET_DESC
这是一张奇异的咒符，闪耀著浅紫色的光芒，你可以感受到它充满了能量。也\许\你可
\以\把它拿(get)下来。
AMULET_DESC
	]) );
	reset();	
}

void init()
{
	add_action( "get_amulet", "get" );
	add_action( "look_amulet", "look" );
}	

int get_amulet(string str)
{
	object player;
	
	player = this_player();
	
	if ( !str || str != "charm" )
		return 0;
	if ( gua )
		return 0;
	else 
		tell_object( player, 
			"当你试著拿下咒符时，突然起了一阵旋风....咒符竟化成了人形 !!\n");
		tell_room( environment(player), 
			"当" + player->query("c_cap_name") + "试著拿下咒符时，突然起了一阵旋风....咒符竟化成了人形 !!\n",
			player );
		new(MOB"/wind_guard")->move(environment(player));
		gua = 1;
		return 1;
}	

int look_amulet(string str)
{
	object player;
	
	if ( present("guard", this_object()) && str == "charm" )
		return 1;
	return 0;
}	