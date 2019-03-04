#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("holy plate","ʥ����");
        add("id",({"plate","platemail"}) );
         set_short( "a holy plate","ʥ����");
	set_long(
         "This plate seems heavy and enhanced with holy power.\n",
         "����һ�����ص�����,�ƺ�������ʥ��������������\n"
	         );
	set( "unit", "��" );
	set( "weight", 360 );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 30 );
	set( "defense_bonus", 5 );
	set( "special_defense", ([ "divine":10, "evil" :-5, "magic":-10 ]) );
	set( "value", ({ 300, "gold" }) );
}
