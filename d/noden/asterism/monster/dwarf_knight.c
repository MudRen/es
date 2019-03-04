#include "../asterism.h"

inherit "/d/noden/asterism/monster/report_damage";
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "dwarf knight", "������ʿ" );
	add("id",({"knight","dwarf"}) );
   set_short( "������ʿ" );
	set_long(
		"һ������İ�����ʿ,Ϊ���������������.\n"
	);
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "alignment", 1400 );
	set( "time_to_heal", 7 );
	set_natural_armor( 46, 40 );
	set_natural_weapon( 26 , 14 , 23 );
	set("max_hp",666);
	set("hit_points",666);
	set_perm_stat( "str", 27 );
	set_perm_stat( "dex", 23 );
	set_perm_stat( "int", 22 );
	set_perm_stat( "kar", 25 );
	set_skill( "parry",100 );
	set_skill( "longblade",100 );
	set( "wealth/gold", 30 );
	set( "special_defense", ([ "all": 38 ,"none":20 ]) );
	set( "aim_difficulty",(["critical":20,"vascular":19]) );
	wield_weapon(WEAPONS"longsword04");
	equip_armor(ARMORS"obsidian_plate");
	equip_armor(ARMORS"gloves03");
	equip_armor(ARMORS"helmet02");
	equip_armor(ARMORS"boots02");
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
    object victim, *guard,*victims;
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
    if ( random(10)<1 ) {
      victims=query_attackers();
      for(i=0;i<sizeof(victims);i++) {
        (victims[i])->receive_damage(35+random(20));
        tell_room(environment(),
                   "������ʿ�Ӷ����ľ޽��������еĵ���.\n", this_object() );
        report_damage(this_object(),victims[i]);
        }
      return 1;
      }
    else return 0;
}

