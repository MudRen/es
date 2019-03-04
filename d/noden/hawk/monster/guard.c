#include <mudlib.h>
inherit MONSTER;
#include "../hawk.h"
void create()
{
        ::create();
        set_level(17);
        set_name("hawkman guard", "���ϻ���");
        add( "id", ({"hawkman", "guard"}) );
        set_short("���ϻ���");
        set_long(
                "�����������ѡһ��սʿ��רְ�������ϡ�\n"
        );
        set( "gender", "male" );
        set( "race", "hawkman" );
        set( "alignment", 250 );
        set_natural_armor( 40, 20 );
	set_natural_weapon( 20,15,30 );
        set ("hit_points",400);
        set ("max_hp",400);
        set_perm_stat( "str", 22 );
        set_perm_stat( "dex", 25 );
        set_skill( "longblade", 80 );
        set_skill( "parry", 70 );
        set_skill( "block", 70 );
        set_skill( "dodge", 60 );
        set_skill( "defend", 100);
        set( "wealth/gold", 13 );
        set( "tactic_func","tac_func");
        set( "elder_guard",1);
	wield_weapon( WEAPON"stone_sword" );
	equip_armor( ARMOR"stone_shield" );
	equip_armor( ARMOR"leather_hauberk" );
}

void init()
{
        command("defend elder");
}

int is_a_guard( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("elder_guard") ) return 1;
    return 0;
}

int tac_func()
{
    object victim, *guard;
    int i;
    victim = query_attacker();
    if( !victim ) return 0;
    guard = filter_array( all_inventory(environment(this_object())),
            "is_a_guard", this_object() );
    for( i=0; i<sizeof(guard); i++ ) {
      tell_room( environment(this_object()),
      guard[i]->query("c_name")+"��: �е��ˣ��챣���ó��ϣ�\n", guard[i]
      );
      guard[i]->kill_ob(victim);
    }
     return 0;
}
