#include "takeda.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("iron staff","ˮĥ����");
       add("id",({"staff"}) );
       set_short("ˮĥ����");
	   set_long(@C_LONG
����һ������Ľ������ɵ����ȣ������ͨ�ķ����޷����죬ֻ
����ˮɳ������ĥ������ˮĥ���ȣ���³��������ֵ�������
C_LONG	);
	
	set( "unit", "��" );
 	set( "weapon_class", 42 );
        set("type","blunt");
	set( "min_damage", 25 );
	set( "max_damage", 47 );
	set( "weight", 230 );
	set( "nosecond", 1 );
	set( "value", ({ 933, "gold" }) );
	
}	
