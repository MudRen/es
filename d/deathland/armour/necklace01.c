#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("jewel necklace","��ʯ���");
        add("id",({"necklace"}) );
         set_short( "a pretty jewel necklace","Ư���ı�ʯ���");
	set_long(
	"a beautiful jewel necklace.\n",
	"һ����\��\�����ı�ʯ��ɵ����,�ƺ�ʮ�ֵİ���\n"
	);
	//set( "no_sale",1);
	set( "unit", "��" );
	set( "weight", 12 );
	set( "type", "misc" );
	set( "material", "element" );
	set( "armor_class", 0 );
	set( "defense_bonus", 7 );
	set( "special_defense", ([ "energy":5, "evil":-5 ]) );
	set( "value", ({ 398, "gold" }) );
}
