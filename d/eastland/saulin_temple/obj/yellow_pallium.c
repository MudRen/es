#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "yellow pallium","��ɫ����" );
	add( "id", ({ "pallium","cloth" }) );
	set_short( "��ɫ����" );
	set_long(
		"����һ��ֻ�н���Ժ�߼����Ӳ����ʸ����Ļ�ɫ���ġ�\n"
	);
	set( "unit", "��" );
        set("material","cloth");
	set( "type", "body" );
        set( "armor_class", 20 );
        set( "defense_bonus", 5 );
	set( "weight", 150 );
	set( "value", ({ 930, "silver" }) );
}
