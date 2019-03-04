#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "Emerald ring", "�����ָ" );
	add( "id", ({ "ring" }) );
	set_short( "a emerald ring", "�����ָ" );
	set_long(
		"You see a beautiful emerald ring.\n",
		"����һ����Ư���������ָ��������һ�����ص�ħ����\n"
	);
	set( "type", "finger" );
	set("material","element");
	set("defense_bonus",2);
	set( "weight", 5 );
	set( "value", ({ 210, "silver" }) );
        set("extra_skills",(["trading":15,]));
	
}
