#include "../almuhara.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Sword Saint", "��ʥ" );
	add( "id", ({ "saint", "guard" }) );
	set_short( "��ʥ" );
	set_long(
		"�㿴��һλ������Į�������������������Ȼ�������ĵ���˿��û�з�Ӧ����\n"
		"�������ܱ����������˺ù�ͨ���㲻�������й����(here)���¡�\n"
			);
	set( "gender", "male" );
	set( "race", "daemon" );
	set( "alignment", 1000 );
	set( "hit_points", 1200 );
	set( "max_hp", 1200 );
	set_natural_armor( 110, 45 );
	set_natural_weapon( 50, 30, 40 );
	set_perm_stat( "str", 23 );
	set_perm_stat( "dex", 29 );
	set_perm_stat( "int", 29 );
	set_perm_stat( "pie", 23 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "kar", 25 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );
	set_skill( "tactic", 100 );
	set("alt_corpse","NONE");
	set( "tactic", "melee" );
	set( "force_effect", 8 );
	set( "force_type", "cold" );
	set( "wealth/gold", 200 );
	set( "special_defense", ([ "all": 50,"none":60 ]) );
        set( "aim_difficulty", ([ "vascular":20 ]) );
        set( "tactic_func", "my_tactic");
        set( "inquiry", ([
"here" : 
	    "������ҵ������ң���������Ҫ�ʽ�ڣ(sword_tomb)��....\n" ,
"sword_tomb" : 
	          "��ڣ�ǻʵ������˽��ġ���Ϊ�ʵ�ϲ���ռ����ֽ�������Ҫ��Щ����Զ\n"
	          "���������������˽���ڣ��\n" ,
"stone" : 
	     "��ʯ����һ���ɴ��ʦ  Т����ʩ�ķ�ӡ(seal)�����ڣ�ڵ�һ��а������ȡ\n"
	     "�˴˴������������û���һ֮�쳣а������ޡ���ʦ��ʱ���������ȥ��ֻ�а������ڷ�\n"
	     "ӡ�У��ȴ������ܳ������ޡ�\n" ,
"seal" : 
	     "��Ҳ���Ǻ�������������������������Сͯ��\n" ,
	     ]) );     
	wield_weapon( WEAPONS"/antique_sword" );
}

int my_tactic()
{
  object victim;
  
  if ( !(victim=query_attacker()) || (random(10)>3)) return 0;
  tell_object(victim,
       "\n��ʥ����� : ��������ʮһ�� !!\n");
	tell_room(environment(this_object()),
		sprintf("��ʥ��%s�� : ��������ʮһ�� !!\n\n",
			victim->query("c_cap_name")),({ this_object(),victim }) );
  victim->receive_damage( 25 + random(15));
  return 1;
}

int is_a_weapon(object item)
{
 	return ((int)item->query("wielded")) ;
}

void relay_message(string class1,string msg)
{
     string who,str,tmp;
     object *weapons,obj;
     
     if( sscanf( msg, "%s(%s)���˹�����\n", tmp,who )==2 ) 
        {
         obj = find_player(lower_case(who));
         if(!obj) return ;
	weapons = filter_array( all_inventory( obj ), "is_a_weapon", this_object() );
	if( !weapons || !sizeof(weapons) ) return;
	tell_object( obj,"��ʥ����֮��ͻȻ����һ���������ƺ�Ҫ���������һ�ϳ��̡�\n" );
	this_object()->kill_ob(obj);
	return;
	}
}

void die()
{
	tell_room( environment(this_object()), 
		"��ʥ�����Ц : ����춰��� !! ����춰��� !!\n��Ц���У���ʥ�����廯�ɷɻң��׷���ɢ��\n\n" ,
		this_object() );
	::die(1);
}
