#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("Silk cloth","˿���·�");
        add("id",({"cloth"}) );
         set_short( "Silk cloth","˿���·�");
	set_long(
"This is a suit of cloth made of silk meterial.and it is worn \n"
"by Yang's bishop.\n"
"����һ��˿���·�,ͨ���� Yang ����ʦ������,�����һ�ֱ�������������\n"
	);
	set( "unit", "��" );
	set( "weight", 150 );
	set( "type", "body" );
	set( "material", "cloth" );
	set( "armor_class", 20 );
	set( "defense_bonus", 5 );
	set( "special_defense", ([ "evil" :8, "divine":-10 ]) );
	set( "value", ({ 218, "gold" }) );
}
