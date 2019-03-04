// chainmail.c
// A standard piece of armor, heavily commented to explain what all the
// properties are.
// Created by Mobydick@TMI-2, 9-30-92

#include <mudlib.h>

inherit ARMOR ;

void create()
{
	set_name( "chainmail", "���Ӽ�");
	add( "id", ({ "chain", "mail" }) );
	set_short( "a suit of chainmail", "���Ӽ�");
	set_long(
		"The mail mesh would cover your torso and upper arms.\n",
		"�������Ӽ׿��Ա������������ֱۡ�\n"
	);
	set( "type", "suit" );
	set( "armor_class", 6 );
	set( "weight", 150 );
	set( "value", ({ 30, "gold" }) );
}
