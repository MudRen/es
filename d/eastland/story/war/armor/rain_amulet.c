#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("Rain amulet","���");
        add("id",({"amulet"}) );
        set_short("���");
	set_long(@C_LONG
һ����ʦ���ƵĻ������ϻ�ˮ�ε���״����������ȥ���ƽ���ˮ��һ����
C_LONG	         );
	set( "unit", "��" );
	set( "weight",6 );
	set( "type", "misc" );
        set("material","cloth");
	set( "defense_bonus", 4 );
	set( "special_defense",(["evil":20,"divine":-15]));
	set( "value", ({ 1000, "silver" }) );
}
