#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(15);
    set_name("Shi Tsen","ʱǨ");
    add("id",({"thief","shi","tsen"}) );
    set_short("ʱǨ");
	set_long(@C_LONG
��������ʿ����Ź����飬�ֽ���㣬���Գ��ԣ����»�����Ϊ��ɽ�����б�����
����ͷ�죮�������㲻��ץ�����Ǯ����
C_LONG
	);
    set("alignment",-400);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "��" );
    set_perm_stat( "dex",23);
    set_perm_stat( "str",20);
    set_perm_stat( "int",19);
    set_perm_stat( "karma",26);
    set_skill("dagger",60);
    set_skill("dodge",90);	
    set ("max_hp",360);
    set ("hit_points",360);
    set ("wealth", ([ "gold":10]) );
    set_natural_weapon(8,8,9);
	set_natural_armor(28,12);
	set ("aim_difficulty",([ "gangolion":33,"vascular":38]) );
	set("special_defense", (["all":17,"none":20]) );
    set ("weight", 40);
    set ("tactic_func","steal");
    equip_armor(TARMOR"thief_amulet");
    equip_armor(TARMOR"simple_boots");
    wield_weapon(TWEAPON"thief_dagger");
    equip_armor(TARMOR"small_cloth");
}
int steal()
{
  object victim;
  string name,c_name;
  if (!(victim=query_attacker())) return 0;
  name =victim->query("name");
  c_name =victim->query("c_name");
  if (random(10)<2) { 
  tell_room(environment(this_object()),
  "\nʱǨһ˦�֣����һ�ѽ�Ǯ�ڹ�������....\n\n"
);
  victim->receive_special_damage("none",10);
  victim->add("wealth/gold",1);
return 1;
}
  if (random(10)<2 && victim->query("wealth/gold")>10) {
  tell_room(environment(this_object()),
  "\nʱǨ͵����"+c_name+"һЩǮ��˳������һ����....\n\n"
);
  victim->receive_special_damage("evil",8);
  victim->set("wealth/gold",(int)(victim->query("wealth/gold"))-10);
  return 1;
}
return 0;
}

