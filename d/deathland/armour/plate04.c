#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("black silver plate","��ɫ������");
        add("id",({"plate","platemail"}) );
         set_short( "a black silver plate ","��ɫ������");
	set_long(
"This is a suit of plate worn by molader royality ,which can  \n"
"protect your body against opponent's attacks.\n",
"����һ�����˻��������ഫ������,���Ա�����ֿ����˵Ĺ���\n"
	);
	//set("no_sale",1);
	set( "unit", "��" );
	set( "weight", 320 );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 33 );
	set( "defense_bonus", 0 );
	set( "special_defense", ([ "fire": 6 ]) );
	set( "value", ({ 450, "gold" }) );
}
