#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "healer's robe", "ҽ������" );
	add( "id", ({ "robe" }) );
	set_short( "an healer's robe", "ҽ������" );
	set_long(
		"You see a healer's robe.\n",
		"����һ��ҽ�������İ�ɫ���ۣ�����մ��һЩ�߰ߵ���Ѫ����\n"
	);
	set( "unit", "��" );
        set("material","healer");
	set( "type", "body" );
	set( "weight", 80 );
	set( "armor_class", 20 );
	set( "value", ({ 150, "silver" }) );
}
