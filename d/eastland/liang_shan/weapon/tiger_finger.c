#include "mudlib.h"

inherit WEAPON;

void create()
{
       set_name("tiger finger","��ָ��");
       add("id",({"finger","tiger"}) );
       set_short("��ָ��");
       set_long(
       "��ָ����ʵ�������д̵����ף������Դ˹������ˣ������ʹ������\n"
       "�˱�������������ⲫ����˲��۹������˻��������ܹ�������ƽ������\n"
       "������ࡣҲ��ˣ���ǿ��ɽ���ر�ƫ������������\n"
	);
	
	set( "unit", "��" );
 	set("block_tactic",0);
 	set( "weapon_class", 17 );
        set("type","unarmed");
	set( "min_damage", 10 );
	set( "max_damage", 19 );
	set( "nosecond", 1 );
	set( "weight", 65 );
	set("bleeding",2);
	set( "value", ({ 42, "gold" }) );
	set( "wield_func","wield_finger" );
	set( "unwield_func","unwield_finger" );
}	
