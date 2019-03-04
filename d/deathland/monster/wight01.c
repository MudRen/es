#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "evil wight", "а��Թ��" );
	add("id",({"wight"}));
	set_short( "evil shadow", "а��Թ��" );
	set_long(
		"a terrible evil wight.\n"
		"һ�����˾��µ�а��Թ��,��˵����Щ��������ȥ���˵�������γɵ� .\n"
	);
	//set( "gender", "natural" );
	set( "alignment", -480 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "int", 17 );
	set_perm_stat( "kar", 12 );
	set_skill( "dodge", 93 );
	set( "tactic_func", "my_tactic" );
    set_natural_weapon( 35, 16, 27 );
	set_natural_armor( 70, 25 );
    set( "unbleeding",1);
    set("aggressive",1);
}

int my_tactic()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim,
          "а��Թ�鷢�����µ�Ц��,�������������ٶ����������ȡ���������.\n"
          );
      tell_room(environment(this_object()),
          "а��Թ�鷢�����µ�Ц��,�������������ٶ���"+victim->query("c_name")+"��ȥ.\n"
          ,({victim,this_object(),}) );
      victim->receive_special_damage("evil",10+random(17));
      report(this_object(),victim);
      return 1;
      }
}
