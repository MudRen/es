#include "../moyada.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(13);
	set_name( "guard of Moyada", "Ī�Ǵ�����" );
	add ("id", ({ "guard", }) );
	set_short( "Ī�Ǵ�����" );
	set_long( @C_LONG
����Ī�Ǵ������, ��ֹ�����а���������, ������������ħ��ʦ��
C_LONG
	);
	set( "alignment", 1200 );
	set( "class", "mage");
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "��" );
	set_perm_stat( "dex", 17 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 22 );
	set_perm_stat( "con", 13 );
	set_perm_stat( "piety", 25 );
	set_perm_stat( "karma", 18 );
	set("max_hp", 400);
	set("hit_points", 400);
	set("wealth", ([ "silver": 100 ]) );
	set_natural_weapon( 20, 12, 20 );
	set_natural_armor( 54, 30 );
    set("weight", 400);
    set("exp_reward",4200 );
    set_experience(250000);
    set("sepcial_defense", ([ "all":35, "none":20, ]) );
    set("aim_difficulty",
    	([ "critical":35, "vascular":50, "weakest":25, "ganglion":45, ]) );
    set_skill("dodge",50);
    set_skill("elemental",100);
    set_skill("concentrate",70);
    set_skill("target",70);
    set("magic_delay", 1);
    set("spells/fireball", 3);
        
    wield_weapon( MOYADA"obj/wands/fire_wand" );
    equip_armor( MOYADA"obj/magic_robe" );
    set( "tactic_func", "cast_spell" );
}

int is_a_guard( object obj )
{
    if( obj->query_attacker() ) return 0;
    if( (string)obj->query("name") == "guard of Moyada" ) return 1;
    return 0;
}

int cast_spell()
{// 20% cast a spell fireball 3
    object victim, *guard;
    int i;
    victim = query_attacker();
    if( !victim ) return 0;
    guard = filter_array( all_inventory(environment(this_object())),
            "is_a_guard", this_object() );
    for( i=0; i<sizeof(guard); i++ ) {
      tell_room( environment(this_object()), 
        "Ī�Ǵ��������: һ��Ϊ����Ī�Ǵ��ս!\n" , guard[i]
      );
      guard[i]->kill_ob(victim);
    }
    if( random(10)>2 ) return 0;
    command( "cast fireball on "+victim->query("name"));
    return 1;
}
