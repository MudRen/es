#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "daoist's robe", "������" );
	add( "id", ({ "robe" }) );
	set_short( "a daoist's robe", "������" );
	set_long(
		"You see a daoist's robe.\n",
		"����һ����ʿ��������ɫ���ۣ�ǰ�������һ������ͼ����\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
        set("material","cloth");
	set( "weight", 100 );
	set( "armor_class", 15 );
	set( "value", ({ 100, "silver" }) );
}
