#include "../echobomber.h"

inherit MONSTER;

void create ()
{
        object ob1,ob2,ob3,ob4,ob5;

	::create();
    set_level(18);
    set_name("dwarf soldier captain","����ʿ���ӳ�");
    add ("id", ({"dwarf","captain",}) ); 
    set_short( " A dwarf soldier captain",
            "����ʿ���ӳ�");
    set_long(@LONG
A dwarf captain is leading dwarf soldier to defend evil troll and protect his
country.
LONG
    ,@C_LONG
�Ⱛ�˶ӳ����쵼��ʿ��ȥ�Կ�ɽ�����˺ͱ����Լ��Ĺ���
C_LONG
	);
    set("alignment",300);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "��" );
    set_perm_stat( "dex",15);
    set_perm_stat( "str",25);
    set_perm_stat( "int",13);
    set_perm_stat( "con",20);
    set_perm_stat( "piety",8);
    set_perm_stat( "karma", 19);
	
    set ("max_hp",520);
    set ("max_sp",0);
    set ("hit_points",520);
    set ("spell_points",0);
    set ("wealth", ([ "gold":3]) );
    set_natural_weapon(27,5,18);
	set_natural_armor(40,25);
        set ("special_defense",(["all":10,"scholar":10]) );
	set ("aim_difficulty",(["critical":30,"vascular":15]) );
    set ("weight", 350);
    equip_armor(Armour"/plate01");
    equip_armor(Armour"/boots01");
    equip_armor(Armour"/helmet01");
    equip_armor(Armour"/shield02");
    wield_weapon(Weapon"/hammer01");
    set("echo_dwarfsoldier",1);
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


