#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("gold necklace","��׹���");
        add("id",({"gold","necklace",}) );
         set_short( "a gold necklace","��׹���");
	set_long(
"This is a gold necklace \n"
"����һ���ɽ��Ӵ��������������и�����׹�ӣ��������ǳ�������\n" 
	);
	set( "unit", "��" );
	set( "weight", 12 );
        set("material","light_metal");
	set( "type", "misc" );
	set( "armor_class", 0 );
	set( "defense_bonus", 8 );
	set( "value", ({ 160, "gold" }) );
}
