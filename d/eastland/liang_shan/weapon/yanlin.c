#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("yanling blade","���ᵶ");
       add("id",({"blade"}) );
       set_short("���ᵶ");
	   set_long(
           "�������ֺú���ϲ���ĵ��ӣ���Ϊ���ǳ���ʹ������Ҳ����\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 30 );
        set("type","longblade");
	set( "min_damage", 15 );
	set( "max_damage", 33 );
	set( "weight", 70 );
	set("bleeding",5);
	set( "value", ({ 90, "gold" }) );
	
}	
