#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "white robe", "云袍" );
	add( "id", ({ "robe", }) );
	set_short( "云袍");
	set_long(@C_LONG
	一件洁白无暇的白色袍子，由袍子上所发出的圣洁光辉，使人觉得只要
	是配得上这袍子的人，绝对是一个善良的好人，对於邪恶的魔法也\许有
	些\许\的保护能力．	
C_LONG
	);
	set( "unit", "件" );
	set( "weight", 90 );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 24 );
	set( "defense_bonus", 9 );
	set( "special_defense" ,
	      ([ "evil": 5 ]) );
	set( "value", ({ 2000, "silver" }) );
}
