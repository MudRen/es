#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(18);
    set_name( "Princess Aiga", "����ϼ" );
    add( "id",({"aiga","princess"}) );
    set_short( "����ϼ����");
    set_long(@C_LONG
����ϼ���������ҵĵ�һ��������������͵������Ƕ�������һЦ����������Ȼ��
����ʮ�ֿɰ�����ȴʮ�����ԡ�ǧ��Ҫ��������Ŷ���������������Ǻܿ��µģ���
�ɱ���������Ի���Ŷ������֪Ϊ�Σ����ϴ���һ˿˿��������������ʲ��������
����˰���(sadness)�أ�
C_LONG
            );
    set("gender","female");
    set("unit","λ");
    set("class","scholar");
    set("race","daemon");
    set("age",18);
    set_perm_stat("str",21);
    set_perm_stat("dex",16);
    set("alignment",1000);
    set("weight",400);
    set("wealth/gold",200);
    set("hit_points",550);
    set("max_hp",550);
    set("special_defense",(["evil":55,"fire":50,"energy":80,"electric":70,
                            "cold":0,"none":30]) );
    set("aim_difficulty",
    (["critical":90,"weakest":10,"ganglion":10,"vascular":70]) );
    
    set_skill("longblade",80);
    set_skill("parry",70);
    set_skill("tactic",80);
    set_skill("dodge",70);
    set("tactic","berserk");
    set_natural_armor(76,35);
    set_natural_weapon(35,10,15);
    set("tactic_func","my_tactic");
    set("inquiry",([
         "sadness":"@@ask_sadness"]) );
    set("exp_reward",22000);   

    wield_weapon(TWEP"key1");
    equip_armor(TOBJ"veil");
    equip_armor(TOBJ"cloak");
}

int my_tactic()
{
    object victim;
    if( random(100) > 15 || !victim=query_attacker()  ) return 0;
    if( victim->query("stop_attack") ) return 0; 
     tell_object(victim,
      "\n����ϼ�ٻ�һ��Сľ���������Χ���²��Ľ�磬��������ж�....\n\n"
          );
     tell_room( environment(victim),
      "\n����ϼ�ٻ�һ��Сľ��������Χ���½�磬���� "+victim->query("c_name")+" ���ж�.\n\n"
      ,victim  );
     victim->block_attack(10);
     victim->set_temp("msg_stop_attack",
     "( �㱻���������ס���޷����ֹ�����)\n" );     
      return 1;
}

void ask_sadness(object who)
{
    if( !(who->query_temp("luoko_quest")) ){
    tell_object(who,@ALONG
��..........�������������ʱ���йɲ���ĸо�������......�������������Կ�ƺ�
Խ��Խ��˳���ˣ���ͷҲ���ϵļ¶���������ʲ�����Ҫ������һ�����ѵ��ػ�������
������Ҫ��ʧ����������ҵ���һ�ºò��ã���ֻϣ����ά�������������ػ��鲻Ҫ
���²ź�..........!
ALONG
         );
     who->set_temp("luoko_quest",1);
	return ;
    }
    tell_object(who,
         "��.........�㵽��Ҫ��Ҫ���˼�ѽ����Ҫ�Ļ��Ϳ���˼Һܼ�Ү��\n");
	return ;
}

void init()
{
    ::init();
    add_action("do_report","report");
}

int do_report(string str)
{
    string *name;
    name = this_player()->query("id");
    
    if( !str || str != "fine") {
    write(@FINE
����ϼ�����۾����ڴ��������˵������û����(fine)����
FINE
         );
    return 1;
    }
    if( !this_player()->query_temp("seed_ok")==1 )
    return notify_fail(
    "����ϼ�ƿ�������ߣ�����ƭ�ң���֪���������û���İ��ң��������ˣ�\n");
    
  if( (int)this_player()->query_temp("luoky_killer")==1 ){
     write("��Ȼ�Һܸ�л��Ϊ�ҽ��ǣ�����ɱ�������õĳ�����ǲ�����ˡ������\n");
     command( "kill "+name[0] );
     return 1;
     } 
    
    this_player()->delete_temp("seed_ok");
    if( (int)this_player()->query_quest_level("save_tree") < 1 ) {
    write("����ϼ�ܸ��˵�˵��̫���ˣ���лл�㣬���ֿ���ר�������ˣ�\n");
    this_player()->finish_quest("save_tree",1);
    write("���Ѿ���������������õ�1000�㾭��ֵ\n");
    this_player()->gain_experience(1000);
    return 1;
    }
    write("����ϼ����΢Ц��˵����лл���ٴΰ��ҽ�����е����ǣ�лл��\n");
    return 1;
}       

void die()
{
    object killer;
    killer = query("last_attacker");
    killer->set_temp("get_key",1);
    ::die();
    return;
}
    
