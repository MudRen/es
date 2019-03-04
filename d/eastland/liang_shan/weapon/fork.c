#include "takeda.h"
#include <stats.h>
#include <conditions.h>

inherit WEAPON;

void create()
{
       set_name("poisoned fork","ҩ��");
       add("id",({"fork"}) );
       set_short("ҩ��");
	   set_long(
           "����һ�Ѵ��ж�ҩ���Բ棬��˷�����ɫ�Ĺ�����\�������������ԣ�\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 17 );
        set("type","thrusting");
	set( "min_damage", 7 );
	set( "max_damage", 17 );
	set( "weight", 60 );
	set( "value", ({ 40, "gold" }) );
//        set( "hit_func","emit_poison");	
}
int emit_poison(object victim)
{
     object holder;
if ( !victim) return 0;
if (!(holder= environment(this_object())) || !living(holder) ) return 0;
if (random(8)>1) return 0;
   else {
victim->set("last_attacker",holder);

tell_room( environment(holder),
"\n"+holder->query("c_name")+"��ҩ��ʹ���˵��������ɫ��\n",
this_object());
(CONDITION_PREFIX + "simple_poison")->apply_effect(victim,7,4);
return 1;
       }
}
	
