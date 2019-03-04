#include "../oldcat.h"

inherit MONSTER;

void create ()
{
    ::create();
    set_level(16);
    set_name("the wizard Corak","������ʦ������");
    add("id",({"wizard","corak"}) );
    set_short("������ʦ������");
	set_long(
@LONG
һ��������ʦ���������ǰ�������ʷ����ǿ����ʦ�����������������ÿ���ƽ����
LONG
	);
    set("alignment",-880);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "��" );
    set_perm_stat( "dex",25);
    set_perm_stat( "str",14);
    set_perm_stat( "int",26);
    set_perm_stat( "con",18);
    set_perm_stat( "piety",27);
    set_perm_stat( "karma",16);
	
    set ("wealth", ([ "gold":30]) );
    set ("max_hp", 500);
    set ("hit_points", 500);
    set ("aim_difficulty", ([ "critical":50,"weakest":30,"vascular":30 ]) );
    set_natural_armor( 36 ,15 );
    set_natural_weapon(2,7,15);
    set ("weight", 350);
    set_skill("shortblade",90);
    set("special_defense", (["all":33,"none":20]) ); 
    set( "tactic_func", "cast_spell");
    set("chat_chance",5);
    set("chat_output", ({
        "\n��ʦ˵����������ļ�Ʒ��û�����䣬��Ը�������Լ��� ?\n\n",
        "\n��ʦ˵�����ý���ļ�Ʒ�Ѿ��������ˣ��ֿ���ƽ���Ķȹ�һ�ꡣ\n\n"
    }) );
    set("inquiry",([
        "volcano":"@@ask_volcano",
        ]) );
    wield_weapon(OWEAPON"shortsword1");
    equip_armor(OARMOR"mail1");
    equip_armor(OARMOR"ring1");
}

void ask_volcano(object who)
{
  tell_object(who,
    "��ʦ˵��ֻҪ����ÿ��������Ѫ��һλ���ˣ�����Ͳ��ᷢŭ����ɽ�Ͳ��ᱬ����\n"
  );
}

int cast_spell()
{
    object victim;
    string name,c_name;
    if( !(victim = query_attacker()) ) return 0;
    
    name = victim->query("name");
    c_name= victim->query("c_name");
    
    if( random(10) < 6 ) {
      tell_room( environment(this_object()),
        "\n\n����������һ�����FENDI MENTAR DIVI CREMBI MENTAR BONI\n"
        "���г���һ����ɫ������ֱ��������˵ĵ��ˣ����Ҹ�����������Ĺ�����\n\n"
         );
      victim->receive_special_damage("fire", 20+random(6));
      return 0;
    }
    if( (this_object()->query("hit_points")<180) && (random(100)<50) ) {
      tell_room( environment(this_object()),
        "�����˺���������ػ���ҽ�����Լ���\n"
      );
      this_object()->receive_healing(35+random(30));
      return 1;
    }
    
    return 0;
}
