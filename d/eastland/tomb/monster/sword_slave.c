#include "../almuhara.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Sword Slave", "��ū" );
	add( "id", ({ "slave", "guard" }) );
	set_short( "��ū" );
	set_long(
		"�㿴��һλ�����������������������˫Ŀ΢�գ������ĵ���˿\n"
		"��û�з�Ӧ��\n"
	);
	set( "gender", "male" );
	set( "race", "orc" );
	set( "alignment", 1000 );
	set( "hit_points", 1200 );
	set( "max_hp", 1200 );
	set_natural_armor( 100, 35 );
	set_natural_weapon( 40, 20, 30 );
	set_perm_stat( "str", 22 );
	set_perm_stat( "dex", 28 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "pie", 20 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "kar", 25 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );
	set_skill( "tactic", 100 );
	set("alt_corpse","NONE");
	set( "tactic", "berserk" );
	set( "force_effect", 8 );
	set( "force_type", "cold" );
	set( "wealth/gold", 200 );
	set( "special_defense", ([ "all": 50,"none":60 ]) );
        set( "aim_difficulty", ([ "vascular":20 ]) );
        set( "tactic_func", "my_tactic");
   
	wield_weapon( WEAPONS"/gemmy_sword" );
}

int my_tactic()
{
  object victim;
  int dam;
  
  if ( !(victim=query_attacker()) || (random(10)>2)) return 0;
  tell_object(victim,
       "\n��ū����֮��ͻȻ�������콣��������� !!\n");
	tell_room(environment(this_object()),
		sprintf("��ū����֮��ͻȻ�������콣����%s��ȥ !\n\n",
			victim->query("c_cap_name")),({ this_object(),victim }) );
  dam = 23 + random(7);
  victim->receive_damage(dam);
  return 1;
}

int is_a_weapon(object item)
{
 	return ((int)item->query("wielded")) ;
}

void relay_message(string class1,string msg)
{
     string who,str,aa;
     object *weapons,obj;
     
     if( sscanf( msg, "%s(%s)���˹�����", aa , who )==2 )      
        {
         obj = find_player(lower_case(who));
         if(!obj) return ;
	weapons = filter_array( all_inventory( obj ), "is_a_weapon", this_object() );
	if( !weapons || !sizeof(weapons) ) return;
	tell_object( obj, 
		"��ū����֮��ͻȻ����һ���������ƺ�Ҫ���������һ�ϳ��̡�\n");
	this_object()->kill_ob(obj);
	return;
	}
}

void die()
{
	tell_room( environment(this_object()), 
		"\n��ū�����һЦ��ͻȻ���ɷɻ������ɢ��\n\n" ,
		this_object() );
	::die(1);		
}	 	