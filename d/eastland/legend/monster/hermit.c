#include "../legend.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(17);
    set_name( "hermit", "����" );
    add( "id",({"hermit"}) );
    set_short( "����");
    set_long(@LONG
һλ��Լ�ˡ���ʮ������ˣ������������Ｚ�����ġ���ʮ���ˣ���Ϊʱ��̫�ã�
Ҳ������ԭ����ʲ��ʲ��ֻ֪��������ʮ����ǰ��λ������������ҽ�������Ϊʲ
���������ȴû��֪������������վ���������Ȫˮ�������ƺ�������˼��
��ó����ˣ�һ��Ҳû��������Ĵ��ڣ������������ڵ����ӣ�������Ҳ������ȥ
��������
LONG
            );
    set("unit","λ");
    set("race","human");      
    set("class","healer");
    set("age",89);
    set("gender","male" );
    set("alignment",6000);
    set("weight",600);
    set_perm_stat("str",20);
    set_perm_stat("dex",26);
    set_perm_stat("int",28);
    set_perm_stat("kar",30);
    set("hit_points",550);
    set("max_hp",550);
    set_natural_armor(55,50);
    set_natural_weapon(28,6,8);
    set_skill("dodge",80);
    set_skill("parry",70);
    set_skill("dagger",90);
    set_skill("anatomlogy",100);
    set("special_defense", ([ "all": 50,"none":30]) );
    set("aim_difficulty",
    (["critical":65,"vascular":20,"ganglion":70,"weakest":65]) );
    set("stun_difficulty",90);
    wield_weapon(LWEAPON"ice_needle");
    set("chat_chance",10);
    set( "att_chat_output", ({
        "���ߵ����ɶ񣡾��Ҵ����ҵ��徲�����Һúý�ѵ�㣡\n"
    }) );
    set("inquiry", ([
           "����":"@@ask_buty",
         "beauty":"@@ask_buty",
     "����������":"@@ask_ball",
           "ball":"@@ask_ball",
         "������":"@@ask_tree",
           "tree":"@@ask_tree"
    ]) );
    set("tactic_func","my_tactic");
}        
void ask_buty(object asker)
{
write(@C_LONG
����˵������Ҫ����ร����Ѿ��������ˣ���Ҫ����ร��᲻��̫̰���㣿
�����������˰��죮��
����˵���������Ҫ�����Ļ�����ȥ�Ҵ�˵�еġ������������������Ƕ����ǲ�֪
�����������������������м��أ�������������ڡ����������ϣ�Լÿǧ�꿪��һ��
���������������Ž�һ�ι����൱����ޱȡ����ǣ��ڡ����������������޿��أ�
������������������������ȡ�ã��м��мǡ�

����˵���ᣬ������һ�Ծ�˼����������   

C_LONG
      );
}
void ask_ball(object asker)
{
write(@C_LONG
����˵��������������?
����˵����һ���ܺõĶ��������㲻���ã���������ֻҪ ( use_lifeball )
�����������Ϳ����ˡ�
C_LONG
      );
}
void ask_tree(object asker)
{
write(@C_LONG
����˵����һ����˵���ĵؼ��������˲���Ե�����������������������ò���
����������������������������࿳��ֻ���Ĺ�����������Ե��������������
          ������ҡҡ���ɣ�˵�������С��������������
C_LONG
      );
}
int my_tactic()
{
     object victim;
     int select;
          
     if (!(victim= query_attacker())) return 0;
     select=random(20);
     if ( select > 13 ) set("aiming_loc","critical");
     else if ( select > 11 ) set("aiming_loc","ganglion");
     else if ( select > 3 ) set("aiming_loc","weakest");
     else if ( select > 0 ) {
          if ( victim->query("conditions/bleeding") ) set("aiming_loc","weakest");
          else set("aiming_loc","vascular");
     }
     return 0;
}