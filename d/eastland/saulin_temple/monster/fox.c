#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
		object ob;
        ::create();
        set_level(16);
        set_name( "Charming woman of fox", "���꾫" );
        add ("id", ({ "fox","woman" }) );
        set_short( "���꾫");
        set("unit","ֻ");
        set_long(@C_LONG
����һֻʮ�ּ��ʵ�ǧ����꾫��ר����ȡ�����������������ر�С�ġ�
C_LONG
        );
	set("killer",1);
        set("max_hp", 600);
        set("hit_points",600);
        set("alignment",-1000 );
        set("wealth/silver",100);
        set("special_defense",([ "all" : 30, "none": 30 ]));
        set("aim_difficulty", ([ "critical" : 25, "vascular" : 30, ]) );
        set_perm_stat("str", 23);
        set_perm_stat("dex", 25);
        set_perm_stat("karma",25);
        set_perm_stat("int",25);
        set_natural_weapon(32, 21, 36);
        set_natural_armor(80, 36);
        set_skill("dodge",100);
        set("gender", "female");
        set_c_limbs(({ "����", "ͷ��", "�Ų�", "�ֱ�" }));
        set("tactic_func","special_att");
        set("chat_chance", 10 );
        set("att_chat_output", ({
            "���꾫��Ц���� �װ��ģ����˼��������������!!\n",
	    }) );
        ob = new( SAULIN_OBJ"fox_tail" );
        ob->move(this_object());
}

void report( object attacker, object victim )
{
   string message;
   seteuid(getuid());
   message= "/adm/daemons/statsd"->status_string(victim);
   tell_object( victim,
     set_color(sprintf("һ��������Ϯ�����ݷ�������һ��һ�ε������ȥ!!\n( ��%s )\n",message),"HIR",victim)
   );
}

int special_att()
{
    object victim;
    int att_type ;
    string c_name;
    if( !(victim = query_attacker()) ) return 0;
    // female won't effect, added by Kyoko.
	if( (string)victim->query("gender") == "female" ) return 0;
	
    c_name= victim->query("c_name");
    att_type = random(100);
    if( att_type < 20 ) {
      tell_room( environment(this_object()), 
        sprintf("\n���꾫��%s�����������˷ܵ�������������\n",c_name),
        this_player()
      );
      tell_object( victim, 
        set_color("\n���꾫���㱧���������˷ܵ������������\n","HIY",victim ));

      victim->receive_special_damage("cold", 30+random(12));
      report(this_object(),victim);
      return 1;
    } else if( att_type >= 20 && att_type < 40 ) {
      if( victim->query("stop_attack") ) return 0;
      tell_object( victim, 
        set_color("\n���꾫���ĵ���������Ի�ס�ˡ�\n","HIG",victim));

      tell_room( environment(), 
        sprintf("���꾫�����ĵ������%s�Ի�ס�� !\n",c_name),
        ({ victim, this_object() })
      );
      victim->block_attack(6);
      victim->set_temp("msg_stop_attack", 
        "( �����ڱ��Ի�ס�ˣ��޷������� )\n" );
      return 1;
    } else return 0;
}
