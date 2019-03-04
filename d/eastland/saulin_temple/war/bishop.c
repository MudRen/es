
#include "saulin_war.h"

inherit War;

void create()
{

        ::create();
        set_level(17);
        set_name( "Arch bishop of evil", "��������" );
        add ("id", ({ "bishop", "arch", }) );
        set_short( "��������" );
        set_long(@C_LONG
���ǳ��а������������̽�������������ƽ�����ˣ��к����鲻��������
�������ĵ�������ǰ����ʮ���и������ʸ�ȡ�ӵ�Ѫ������Ҳ��Ϊ����Ұ�
����ȫ����������ʿ��׷����
C_LONG
                 );
	set("alignment",-2000);
	set( "gender", "male" );
	set( "race", "daemon" );
	set( "unit", "��" );
	set("monk_value",80);
        set_perm_stat( "str", 20 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "kar", 25 );
        set ("wealth", ([ "silver": 200 ]) );
        set_natural_weapon(18,13,22);
        set_natural_armor(30,40);
        set("special_defense",(["all":40,"none":30]) );
        set("aim_difficulty",(["critical":15,"weakest":15,"vascular":15]) );
	set ("weight", 400);
	set_skill("mace",98);
	set_skill("parry",70);
        wield_weapon(Obj"snake_staff");
	equip_armor(Obj"ice_cloth");
	equip_armor(Obj"ice_cloak");
        equip_armor(Obj"ice_amulet");
	set( "tactic_func", "cast_spell");
}

void report( object attacker, object victim )
{
   string c_message;
   seteuid(getuid());
   c_message= "/adm/daemons/statsd"->c_status_string(victim);
   tell_object( victim,
      "( ��"+c_message+" )\n"
   );
}

int cast_spell()
{
    object victim;
    string c_name;
    if( !(victim = query_attacker()) ) return 0;

    c_name= victim->query("c_name");

    if( random(10) < 4 ) {
      tell_room( environment(this_object()), 
        "\n�������������һ�ű�������"+c_name+"\n\n"
       );
      victim->receive_special_damage("ice", 23+random(12));
      report(this_object(),victim);
      return 1;
    }
    return 0;
}
