#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("pu blade","�ӵ�");
       add("id",({"blade"}) );
       set_short("�ӵ�");
	   set_long(
           "����һ�ѷǳ���ͨ�ĵ��ӣ�����ɽ��ǿ������ʽ������\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 17 );
    set("type","longblade");
	set( "min_damage", 9 );
	set( "max_damage", 18 );
	set( "weight", 65 );
	set("bleeding",5);
	set( "value", ({ 42, "gold" }) );
	
}	
