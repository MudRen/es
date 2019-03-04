#include "saulin_monk.c"

void create ()
{
        ::create();
        set_level(6);
        set_name( "basic bonze", "������ɮ" );
        add ("id", ({ "bonze","monk" }) );
        set_short("������ɮ");
        set("unit","λ");
        set_long(@C_LONG
����һλ����ĺ��У�ƽ�ճ��˴����֮�⣬����ϲ������\��\
�����ռ��������䳡ϰ�䣬��һ����׼����ա�
C_LONG
        );
        set("alignment",100);
        set("wealth/silver",10);
        set_perm_stat("str", 9);
        set_perm_stat("dex", 9);
        set_natural_weapon(7, 6, 10);
        set_natural_armor(30, 14);
        set("max_hp", 200);
        set("hit_points", 200);
        set("max_fp", 120);
        set("force_points", 120);
	set("force_effect",2);
        set("special_defense", ([ "all" : 5, ]) );
        set("aim_difficulty", ([ "critical" : 15, "vascular" : 30, ]) );
        set("attack_skill",FIST"ro_han");
        set("gonfus/ro_han",20);
        set("gender", "male");
        set("race", "human");
        set("tactic_func","group_attack");
        set("pursuing",1);
//	set("moving",1);
//	set("speed",35);
        set("chat_chance",10);
        set("chat_output",({
          "������ɮ˵���������������벻Ҫ���£���Ҫ�Ĵ���\n"+
          "              ��Ȼʩ���ͱ��Сɮ�������ˡ�\n"
        }) );
        set ("att_chat_output",({
          "������ɮ�ȵ�����̫��ʶ���ˣ����㲻Ҫ���»�������\n"+
          "              һ��Ҫ����һЩ��ѵ!!\n"
        }) );
}

int check_partner(object obj)
{
   if( obj->query_attacker() ) return 0;
   if( (string)obj->query("name") == "basic bonze" ||
       (string)obj->query("name") == "bonze" ) return 1;
   return 0;
}

int group_attack()
{
    object victim, *guard;
    int i;
    
    victim = query_attacker();
    if(!victim) return 0;
    guard = filter_array( all_inventory(environment(this_object())),
            "check_partner", this_object() );
    for( i=0; i<sizeof(guard); i++) {
      tell_room( environment(this_object()), 
        "������ɮ�󺰣��󵨿�ͽ�������������µĵ�����Ұ��ʦ�ֵ�����ѽ��\n"
      );
      guard[i]->kill_ob(victim);
    }
}     
