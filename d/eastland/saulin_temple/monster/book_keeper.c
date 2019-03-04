#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(16);
        set_name( "The library keeper", "�Ƹ�ɮ" );
        add ("id", ({ "bonze","monk","keeper" }) );
        set_short( "�Ƹ�ɮ");
        set("unit","λ");
        set_long(@DESC
����һλ������У���Ŀ������Ȳ�������Ȼ�������е�Ц�ݣ�����
�����ֳٲ�ɬ��̫��Ѩ�߸߹��𣬾�֪����һ����������޵ĸ��֣�
DESC
        );
        set("alignment",800);
        set("wealth/silver",500);
        set_perm_stat("str", 25);
        set_perm_stat("dex", 25);
        set_perm_stat("int", 29);
        set("max_hp", 600);
        set("hit_points", 600);
        set("max_fp", 200);
        set("force_points", 200);
	set("force_effect",2);
        set_natural_weapon(27, 20, 36);
        set_natural_armor(72, 20);
        set("special_defense", ([ "all" : 30, "none" : 20 ]) );
        set("aim_difficulty", ([ "critical" : 50, "vascular" : 50, ]) );
        set_skill("parry",100);
        set_skill("unarmed",100);
        set ("gender", "male");
        set ("race", "human");
        set ("tactic_func","group_attack");
	set("attack_skill",CLASS"bolo_fist");
	set("monk_gonfu/bolo-fist",80);
        set ("chat_chance",7);
        set ("chat_output",({
          "�Ƹ�ɮ˵�����ؾ������Ǳ����صأ���ʩ��������\n"
        }));
        set("att_chat_output",({
          "�Ƹ�ɮ�ȵ���ʩ��һ����У���ˡСɮʧ����!!\n"
        }));
	equip_armor(SAULIN_OBJ"grey_pallium");
	equip_armor(SAULIN_OBJ"necklace01");
}

int check_partner(object obj)
{
   if( obj->query_attacker() ) return 0;
   if( (string)obj->query("name") == "The library Guardian" ) return 1;
   return 0;
}

int group_attack()
{
    object victim,*guard;
    int i;
    victim = query_attacker();
    if (!victim) return 0;
    guard = filter_array( all_inventory(environment(this_object())),
            "check_partner",this_object() );
    for( i=0; i<sizeof(guard); i++ ) {
      tell_room(environment(this_object()),
        "�ظ�ɮ�󺰣��󵨿�ͽ�������ô��ؾ���ʦ�֣��������� ����\n");
      guard[i]->kill_ob(victim);
    }
}     

void die()
{
	object killer;
        tell_room( environment(), 
			"\n�Ƹ�ɮ�³�������Ѫ����е������õ���Ӧ�� ....\n"
			"\n���ӻ����ͳ�һ���ڹ��������ȥ���Ǻڹܷ���һ��������Х����\n"
			"\n����һ����ɫ���硣\n\n"
			,	this_object()
		);
	killer=query("last_attacker");
        find_object_or_load("/adm/daemons/event/saulin")->start_war();
        ::die(1);
}

