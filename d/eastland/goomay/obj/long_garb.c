#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "long blue garb", "����ɫ����" );
	add( "id", ({ "garb" }) );
	set_short( "a long blue garb", "����ɫ����" );
	set_long(
		"You see a blue long garb.\n",
		"����һ������ͨ������ɫ���ۣ�������һ���ƹ񳯷��ǳ��������֡�\n"
	);
	set( "unit", "��" );
        set("material","cloth");
	set( "type", "body" );
	set( "armor_class", 8 );
	set( "weight", 50 );
	set( "value", ({ 140, "silver" }) );
}
