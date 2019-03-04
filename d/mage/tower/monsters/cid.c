#include "mobs.h"
#include <races.h>

inherit RACE_HUMAN;

void create()
{
	::create();
	seteuid( getuid() );
	set_level(13);
	set_name( "Cid Previa", "ʩ�� ��ά��" );
	add( "id", ({ "cid", "Cid", "engineer", }) );
	set_short( "a engineer Cid Previa", "��ʦ ʩ�� ��ά��" );
	set_long( @LONG
NEED WORK HERE!
LONG
             , @C_LONG
    �ó������ͷ��ָ��ֶ�����Ϊ����������ٵļ�ʦ����������ħ��
��Դ���о���Ŀǰ���������ѧ�ߣ�Ŭ���о��������µ�ħ����Դ�����
�������й� recharge �����⡣
C_LONG
	);
	set( "alignment", 2000 );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "λ" );
	set_perm_stat( "dex", 23 );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 24 );
	set_perm_stat( "con", 19 );
	set_perm_stat( "piety", 20 );
	set_perm_stat( "karma", 25 );
	set ("max_hp", 400);
	set ("hit_points", 400);
	set ("wealth/silver",100 );
	set_natural_weapon( 50, 15, 30 );
	set_natural_armor( 80, 30 );
    set ("weight", 800);
    set ("exp_reward",4000 );
    set_experience(50000);
    set_skill("dodge",80);
    set( "inquiry", ([
      "recharge" : "@@ask_recharge",
    ]) );
}

void init()
{
    ::init();
    add_action("to_value", "value");
}

void ask_recharge( object who )
{
    tell_object( who,
      "ʩ��˵: ������� recharge item ������ħ����Ʒ����Դ��\n"+
      "        value item ��������������Ҫ����Ǯ������ֵ��\n" 
    );
}

int to_value( string str )
{
    object item, who;
    int wc, damage, times, cost_money, cost_exp, skill, money, exp;
    who = this_player();
    if( !str )
      return notify_fail("Value what ?\n");
    if( !(item=present( str, who )) )
      return notify_fail( can_read_chinese() ?
        "ʩ��˵: ������û���������\n" : "Cid says: You have no this item.\n"
      );
    if( !item->query("max_charge") )
      return notify_fail(
        "ʩ��˵: �ⲻ��ħ����Ʒ���޷�����ħ����Դ!\n" 
      );
    wc = (int)item->query("weapon_class");
    damage = (int)item->query("special_damage");
    times = (int)(item->query("max_charge"))-(int)(item->query("charge_left"));
    skill = (int)who->query_skill("recharge");
    money = 200;
    exp = 500;
    cost_money = wc*damage*times*(150-skill)/money;
    cost_exp = wc*damage*damage*(150-skill)/exp;
    if( !cost_money )
      tell_object( who,
        "ʩ��˵: ����Ʒ����Ҫ������Դ��\n"
      );
    else
      tell_object( who,
        "ʩ��˵: ��������Ʒ����Դ�� "+cost_money+" ���Ҽ� "+cost_exp+
        " �㾭��ֵ��\n"
      );
    return 1;
}
