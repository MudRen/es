#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "halfling guard", "����������" );
	add("id",({"guard","halfling"}) );
   set_short( "����������" );
	set_long(
		"�㿴������Ц���İ���������,�������������Ҫ�������� , ���������ְ������.\n"
		"�����ֻ�ùԹԵ�վ����������\n"
	);
	set( "gender", "male" );
	set( "race", "halfling" );
	set( "alignment", 660 );
	set( "time_to_heal", 7 );
	set_natural_armor( 46, 19 );
	set_natural_weapon( 22 , 8 , 12 );
	set_perm_stat( "kar", 22 );
	set( "wealth/gold", 10 );
	set_skill("dodge",70);
	set( "special_defense", ([ "all": 22 ]) );
	wield_weapon(WEAPONS"longsword01");
	equip_armor(ARMORS"ringmail01");
	equip_armor(ARMORS"helmet01");
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
        "������������: ������һ��ѵ��˸��߰�!\n", guard[i] );
      guard[i]->kill_ob(victim);
    }
     return 0;
}

