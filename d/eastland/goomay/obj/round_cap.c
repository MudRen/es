#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "small cap", "��ƤСñ" );
	add( "id", ({ "cap" }) );
	set_short( "a small cap", "��ƤСñ" );
	set_long(
		"You see a small round cap.\n",
		"����һ����в����Բ��Сñ��������������Ǯ�˵�ñ�ӡ�\n"
	);
	set( "unit", "��" );
        set("material","leather");
	set( "type", "head" );
	set( "armor_class", 4 );
	set( "weight", 20 );
	set( "value", ({ 70, "silver" }) );
}
