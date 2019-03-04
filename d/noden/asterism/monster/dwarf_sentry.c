#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(16);
	set_name( "dwarf sentry", "�۲�վ�ڱ�" );
	add("id",({"guard","sentry","dwarf"}) );
   set_short( "�۲�վ�ڱ�" );
	set_long(
		"һ�������ڱ�,�������������ĸ�λ,������������ޱ���ؼ�����\n"
		"ɽ·����������Ⱥ��\n" );
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "alignment", 400 );
	set( "time_to_heal", 8 );
	set_natural_armor( 40, 8 );
	set_natural_weapon( 24 , 12 , 15 );
	set("max_hp",350);
	set("hit_points",350);
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 20 );
	set_skill( "parry",40 );
	set_skill( "longblade",80 );
	set( "wealth/gold", 20 );
	set( "special_defense", ([ "all": 22 ]) );
	set( "aim_difficulty",(["critical":10,"vascular":10]) );
	wield_weapon(WEAPONS"longsword03");
	equip_armor(ARMORS"ringmail03");
	equip_armor(ARMORS"gloves03");
	set("echo_asterism",1);
        set( "tactic_func", "cast_help" ); 
}

int is_a_guard( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("echo_asterism") ) return 1;
    return 0;
}

int cast_help()
{ 
    object victim, *guard;
    int i;
    victim = query_attacker();
    if( !victim ) return 0;
    guard = filter_array( all_inventory(environment(this_object())),
            "is_a_guard", this_object() );
    for( i=0; i<sizeof(guard); i++ ) {
      tell_room( environment(this_object()), 
      guard[i]->query("c_name")+"��: ������һ��ѵ��˸��߰�!\n", guard[i]
      );
      guard[i]->kill_ob(victim);
    }
     return 0;
}

