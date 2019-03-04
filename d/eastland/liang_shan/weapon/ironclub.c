#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit WEAPON;

int damage_count=0;
void create()
{
	set_name( "iron club", "����޼�Ƕ�" );
	add( "id", ({ "club", "iron_club" }) );
	set_short( "����޼�Ƕ�" );
	set_long(@C_LONG
�����������Ƶľ������������ƻ����൱�󣬵����û�й��˵�����
���ò����ģ���ڵİ�����������ɭɭ�����ݣ�ʹ�����뵽�����ĵ�ɽ��
C_LONG);
	set( "unit", "��" );
	set( "type", "blunt" );
	set( "hit_func", "weapon_hit" );
	set( "weight", 190 );
	set( "weapon_class", 40 );
        set( "min_damage", 20);
        set( "max_damage", 40 );
	set( "value", ({ 7350, "silver" }) );
        set( "bleeding",5);
        set( "nosecond",1);
        set( "extra_stats", ([ "kar" : -4 ]) );
	set( "hit_func","emit_poison"); 
}
int emit_poison(object victim)
{
     object holder;
    int my_str,vi_dex;
    
    if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	if ((int)holder->query("hit_points")<10 ) return 0;
	my_str = (int)holder->query_stat("str");
	vi_dex = (int)victim->query_stat("dex");
	if( random(my_str)*3 < random(vi_dex)*2+17 && (damage_count++)<=5 ) 
		return 0;
        victim->set("last_attacker",holder);
        victim->receive_special_damage("none", 16+random(9) );
        tell_object(holder,set_color( "���������޼�Ƕ������ˣ�һƬѪ��ӵ���Ѫ��������˿�ӿ��.....\n"
        ,"HIR",holder));
        tell_room(environment(holder),set_color(holder->query("c_name")+
        "��������޼�Ƕ������ˣ�һƬѪ��ӵ���Ѫ��������˿�ӿ��.....\n","HIR",holder),holder);
    (CONDITION_PREFIX + "bleeding")->apply_effect(victim,6,8,8);
    holder->set("hit_points",(int)holder->query("hit_points")-5);
    damage_count=0;
    return 1;
}
