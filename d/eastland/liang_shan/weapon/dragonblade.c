#include "takeda.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("green-dragon glaive ","�������µ�");
       add("id",({"glaive","green-dragon",}) );
       set_short("�������µ�");
	   set_long(@C_LONG
������ʥ�ع����õ��������µ����ƻ����൱�󣬵�û�й��˵�����
���ò�����
C_LONG	);
	
	set( "unit", "��" );
 	set( "weapon_class", 48 );
        set("type","longblade");
	set( "min_damage", 30 );
	set( "max_damage", 53 );
	set( "weight", 250 );
	set( "nosecond", 1 );
        set( "bleeding",10);
	set( "value", ({ 1010, "gold" }) );
}

