#include "takeda.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("ChiYu_axe ","�����ɱ��");
       add("id",({"axe","chiyu axe",}) );
       set_short("�����ɱ��");
	   set_long(@C_LONG
�����ò����������Ƶľ޸����ƻ����൱�󣬵�û�й��˵�����
���ò����ģ��ഫ�����������ս�Ƶ����¹֮Ұ���������ս��֮
�ᣬ���ս���������⵽�Ƶ۷�ӡ��������˵����ֻʣ��ʱ��һ����
C_LONG	
	);
	set( "unit", "��" );
 	set( "weapon_class", 40 );
        set("type","axe");
	set( "min_damage", 25 );
	set( "max_damage", 53 );
	set( "weight", 250 );
	set( "nosecond", 1 );
	set("bleeding",8);
	set( "value", ({ 1050, "gold" }) );
	
}	
