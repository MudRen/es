#include "../echobomber.h"

inherit MONSTER;

void create ()
{
        object ob1,ob2;

	::create();
	//seteuid( getuid() );
 set_level(16);
 set_name("dwarf soldier","����ʿ��");
 add ("id", ({ "soldier","dwarf"}) );
 set_short( "a dwarf soldier defending the troll",
           "�Կ����˵İ���ʿ��");
	set_long(@LONG
A dwarf soldier is defending the evil troll and protecting his country.
LONG
    ,@C_LONG
�Ⱛ��ʿ����Ϊ�˶Կ����˺ͱ����Լ��Ĺ�����Ŭ��
C_LONG
	);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "��" );
      set_perm_stat( "dex",15);
      set_perm_stat( "str",22);
      set_perm_stat( "int",8);
      set_perm_stat( "con",20);
      set_perm_stat( "piety",8);
      set_perm_stat( "karma", 12);
	
      set ("max_hp",520);
      set ("max_sp",0);
      set ("hit_points",520);
      set ("spell_points",0);
      set ("wealth", ([ "gold":3]) );
      set_natural_weapon(25,10,14);
      set_natural_armor(52,12);
      set ("weight", 350);
      set ("echo_dwarfsoldier",1);    
      equip_armor(Armour"/chainmail01");
      wield_weapon(Weapon"/hammer01");
      set( "tactic_func", "cast_help" ); 
}

int is_a_guard( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("echo_dwarfsoldier") ) return 1;
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


