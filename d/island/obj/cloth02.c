#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black suit","��ɫ��װ" );
	add( "id", ({ "suit","cloth" }) );
	set_short( "��ɫ��װ" );
	set_long(
		"����Ǯ�δ������그��ʱ���õķ�װ����˵�����ر��������ࡣ\n"
	);
	set( "unit", "��" );
        set("material","cloth");
	set( "type", "body" );
        set( "armor_class", 40 );
        set( "defense_bonus", 5 );
	set( "weight", 100 );
	set( "value", ({ 1500, "silver" }) );
	set( "extra_stats" ,(["pie" : -1 , "dex" : 1 ]) );
}
