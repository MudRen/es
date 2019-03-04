#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "Thunder's gloves", "��������" );
	add( "id", ({ "gloves" }) );
	set_short( "a Thunder's gloves", "��������" );
	set_long(
		"You see a pair of golden gloves with strange magic.\n",
		"����һ˫��ɫ�����ף���˵�����������������������񶼻�����������֡�\n"
	);
	set( "unit", "˫" );
        set("material","monk");
	set( "type", "hands" );
	set( "weight", 40 );
	set( "no_sale",1);
	set( "armor_class", 0 );
        set( "defense_bonus", 2 );
	set("special_defense",(["electric":30, ]));
	set("extra_stats",(["str":-1,"dex":-2,"con":-2 ,])); 
	set("extra_skills",(["blunt":20,]));

	set( "value", ({ 240, "silver" }) );
}
