#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "yoroi", "ս��" );
   set_short( "��ʽս��" );
	set_long(
     "����һ����ʽ�����ף������Ӳ����ţƤ�ô�����������Ȼ������Ҫ\n"
		"�Ĳ�λ���Ͻ���Ƭ��\n"
	);
	set( "unit", "��" );
	set( "weight", 210 );
	set( "type", "body" );
	set( "material", "light_metal");
	set( "armor_class", 25 );
	set( "defense_bonus", 3 );
    set( "special_defense",
           ([ "electric":-3, "acid":2 ]) );
	
	set( "value", ({ 820, "silver" }) );
	set( "no_sale", 1 );
}
