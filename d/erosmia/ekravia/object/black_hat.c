#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black hat", "��ɫ��ñ" );
	add( "id", ({ "hat" }) );
   set_short( "��ɫ��ñ��" );
	set_long(
		"�ⶥ��ɫ��ԲͲ״�ĸ�ñ��һ����ħ��ʦ�ǵ�ע���̱ꡣ\n"
	);
	set( "unit", "��" );
	set( "type", "head" );
	set( "material","cloth");
	set( "armor_class", 5 );
	set( "weight", 10 );
	set( "value", ({ 100, "silver" }) );
}
