#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "fire gloves", "��������" );
	add( "id", ({ "gloves" }) );
	set_short( "a fire gloves", "��������" );
	set_long(
		"You see a pair of red gloves with strange magic.\n",
		"����һ˫��ɫ�����ף���˵���ǻ������������������񶼻�����������֡�\n"
	);
	set( "unit", "˫" );
	set( "type", "hands" );
	set( "weight", 40 );
	set( "no_sale",1);
        set("material","light_metal");
	set( "armor_class", -5 );
        set( "defense_bonus", 2 );
	set("special_defense",(["electric":30 ]));
	set("extra_stats",(["str":-1,"dex":-2,"con":-2 ])); 
	set("extra_skills",(["blunt":10]));

	set( "value", ({ 240, "silver" }) );
}
