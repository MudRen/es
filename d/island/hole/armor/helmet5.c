#include <../hole.h>

inherit ARMOR;
int no_pray;
void create()
{
	set_name( "Daemon Visor","恶魔面罩" );
	add( "id", ({ "visor" }) );
	set_short( "恶魔面罩" );
	set_long(@LONG
	邪教徒为了要把恶魔的力量附在身上所戴的面罩。
	传说只要诚心祈求，就可以获得黑暗的力量。
LONG
		);
	set( "unit","顶" );
	set( "weight",50 );
	set( "type","head" );
	set( "material","heavy_metal" );
	set( "armor_class",6 );
	set( "defense_bonus",2 );
	set( "special_defense",([ "evil":25 ]) );
	set( "value",({ 520,"silver" }) );
	no_pray=0;
}

void init(){ add_action( "do_beg","beg" ); }

int do_beg(string str)
{
	object obj,player;
	
	obj=this_object();
	player=this_player();
	
	if( obj->query( "equipped" ) ){
		if( no_pray==1 ) return notify_fail( "这面罩已经失去作用了。\n" );
		if( !str || str!="ishige" ) return notify_fail( "想想看，谁是邪恶的象徵．．\n" );
		if( ((int)player->query( "alignment" )) < -1600 ) return notify_fail( "你已经够邪恶了。\n" );
		tell_object(player,set_color(
		"你咬破指尖将鲜血洒向空中，心中默念著召唤黑暗力量的咒语....\n"+
		"渐渐的你发觉身上充满了邪恶的力量。\n","HIY" ));
		player->set( "alignment",-1600 );
		player->add( "hit_points",-60 );
		no_pray=1;
		return 1;
	}
	else{
		tell_object( player,"想与恶魔打交道必须穿戴象徵邪恶的信物。\n" );
		return 1;
	}
}
