#include "saulin_monk.c"

void create()
{
        ::create();
        set_level(16);
        set_name( "The library Guardian", "�ظ�ɮ" );
        add ("id", ({ "bonze","monk","guardian" }) );
        set_short( "�ظ�ɮ");
        set("unit","λ");
        set_long(
@DESC
����һλ������У���Ŀ������Ȳ�������Ȼ�������е�Ц�ݣ�����
�����ֳٲ�ɬ��̫��Ѩ�߸߹��𣬾�֪����һ����������޵ĸ��֡�
DESC
        );
        set("alignment",800);
        set("wealth/silver",500);
        set_perm_stat("str", 23);
        set_perm_stat("dex", 25);
        set_natural_weapon(24, 20, 36);
        set_natural_armor(55, 30);
        set("max_hp", 500);
        set("hit_points", 500);
        set("max_fp",200);
        set("force_points", 200);
	set("force_effect",2);
        set("special_defense", ([ "all" : 40, "none" : 20 ]) );
        set("aim_difficulty", ([ "critical" : 50, "vascular" : 50, ]) );
        set_skill("parry",80);
        set_skill("unarmed",100);
        set ("gender", "male");
        set ("race", "human");
	set("attack_skill",CLASS"keep_flower");
	set("monk_gonfu/keep-flower",10);
        set ("tactic_func","group_attack");
        set ("chat_chance",7);
        set ("chat_output",({
          "�ظ�ɮ˵�����ؾ������Ǳ����صأ���ʩ��������\n"
        }));
        set ("att_chat_output",({
          "�ظ�ɮ�ȵ���ʩ��һ����У���ˡСɮʧ����!!\n"
        }));
	equip_armor(SAULIN_OBJ"cloth5a");
	equip_armor(SAULIN_OBJ"necklace01");
}

int check_partner(object obj)
{
   if( obj->query_attacker() ) return 0;
   if( (string)obj->query("name") == "The library keeper" ) return 1;
   return 0;
}

int group_attack()
{
    object victim,*guard;
    int i;
    victim = query_attacker();
    if (!victim) return 0;
    guard = filter_array( all_inventory(environment(this_object())),
            "check_partner",this_object());
    for(i=0;i<sizeof(guard); i++){
      tell_room(environment(this_object()),
        "�Ƹ�ɮ�󺰣��󵨿�ͽ�������ô��ؾ���ʦ�֣��������㣡\n"
      );
      guard[i]->kill_ob(victim);
    }
}     
